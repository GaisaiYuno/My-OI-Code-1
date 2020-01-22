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
	long double x;
	long double y;
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
long double get_len(long double x1,long double y1,long double x2,long double y2){
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
		dp1[i][0]=dp1[i-1][0]+match[a[i]][0];
	}
	for(int i=1;i<=lenb;i++){
		dp1[0][i]=dp1[0][i-1]+match[0][b[i]];
	}
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			dp1[i][j]=max(max(dp1[i-1][j]+match[a[i]][0],dp1[i][j-1]+match[0][b[j]]),dp1[i-1][j-1]+match[a[i]][b[j]]);
		}
	}
	if(dp1[lena][lenb]<0) return 0;
	else return dp1[lena][lenb];
}
long double get_val(point a,point b){
	return (long double)get_match(a.num,b.num,a.len,b.len)/get_len(a.x,a.y,b.x,b.y);
}
long double val[maxn+5][maxn+5];
long double dp2[(1<<maxn)+5][maxn+5];
long double tsp(){
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			dp2[i][j]=INF;
		}
	}
	dp2[0][0]=0;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(!(i&(1<<k))) continue;
				if(j==k) continue;
				dp2[i][k]=min(dp2[i&~(1<<k)][j]+val[j][k],dp2[i][k]);
			}
		}
	}
	long double ans=dp2[(1<<n)-1][0];
	for(int i=1;i<n;i++){
		ans=min(ans,dp2[(1<<n)-1][i]+val[i][0]);
	}
	return ans;
}
char m[maxm];
int main(){
	freopen("bug16.in","r",stdin);
//	freopen("bug.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %Lf %Lf",m,&dot[i].x,&dot[i].y);
		int l=strlen(m);
		dot[i].len=l;
		for(int j=0;j<l;j++){
			dot[i].num[j+1]=m[j]-'0';
		}
	}
//	sort(dot+1,dot+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			val[i][j]=val[j][i]=get_val(dot[i],dot[j]);
		}
	}
	printf("%.10Lf",tsp());
	return 0;
}
