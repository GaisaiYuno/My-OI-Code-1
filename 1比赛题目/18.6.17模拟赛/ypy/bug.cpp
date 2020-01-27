#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 16
#define maxm 1005
#define INF 0x3f3f3f3f
using namespace std;
int n;
struct point{
	double x;
	double y;
	int len;
	int num[maxm];
}dot[maxn+5];
int dp1[maxm][maxm];
const int match[6][6]={
   {-100,-1,-2,-8,-16,-32},
   {-1,6,-2,-4,-1,-2},
   {-2,-2,7,2,3,-7},
   {-8,-4,2,8,1,5},
   {-16,-1,3,1,9,2},
   {-32,-2,-7,5,2,15}
};
double get_len(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int get_match(int *a,int *b,int lena,int lenb){
	for(int i=0;i<=lena;i++){
		for(int j=0;j<=lenb;j++){
			dp1[i][j]=-INF;
		}
	}
	dp1[0][0]=0;
	for(int i=1;i<=lena;i++){
		dp1[i][0]=dp1[i-1][0]+match[a[i-1]][0];
	}
	for(int i=1;i<=lenb;i++){
		dp1[0][i]=dp1[0][i-1]+match[0][b[i-1]];
	}
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			dp1[i][j]=max(max(dp1[i-1][j]+match[a[i-1]][0],dp1[i][j-1]+match[0][b[j-1]]),dp1[i-1][j-1]+match[a[i-1]][b[j-1]]);
		}
	}
	if(dp1[lena][lenb]<0) return 0;
	else return dp1[lena][lenb];
}
double get_val(point a,point b){
	return (double)get_match(a.num,b.num,a.len,b.len)/get_len(a.x,a.y,b.x,b.y);
}
double val[maxn+5][maxn+5];
double dp2[(1<<maxn)+5][maxn+5];
double tsp(){
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			dp2[i][j]=INF;
		}
	}
	for(int i=0;i<n;i++) dp2[(1<<i)][i]=0;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(!(i&(1<<j))) continue;
			for(int k=0;k<n;k++){
				if(!(i&(1<<k))) continue;
				if(j==k) continue;
				dp2[i][j]=min(dp2[i&(~(1<<j))][k]+val[k][j],dp2[i][j]);
			}
		}
	}
	double ans=INF;
	for(int i=1;i<n;i++){
		ans=min(ans,dp2[(1<<n)-1][i]+val[i][0]);
	}
	return ans;
}
char m[maxm];
int main(){
//	freopen("bug.in","r",stdin);
//	freopen("bug.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %lf %lf",m,&dot[i].x,&dot[i].y);
		int l=strlen(m);
		dot[i].len=l;
		for(int j=0;j<l;j++){
			dot[i].num[j]=m[j]-'0';
		}
	}
//	sort(dot+1,dot+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			val[i][j]=val[j][i]=get_val(dot[i],dot[j]);
		}
	}
	printf("%lf",tsp());
	return 0;
}
