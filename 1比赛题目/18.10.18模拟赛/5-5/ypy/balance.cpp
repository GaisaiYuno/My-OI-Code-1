#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n;
int maxx,maxy;
int a[maxn][maxn];
int sum[maxn][maxn];
void init(){
	for(int i=1;i<=maxx;i++){
		for(int j=1;j<=maxy;j++){
			sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
} 
int query(int x1,int y1,int x2,int y2){
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int check(int x){
	for(int a=0;a<=maxx;a+=2){
		for(int b=0;b<=maxy;b+=2){
			int t1=query(0,0,a,b);
			int t2=query(a,0,maxx,b);
			int t3=query(a,b,maxx,maxy);
			int t4=query(b,0,a,maxy);
			if(max(max(t1,t2),max(t3,t4))<=x) return 1;
		}
	} 
	return 0;
} 
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	int x,y;
	n=qread();
	for(int i=1;i<=n;i++){
		x=qread();
		y=qread();
		a[x][y]=1;
		maxx=max(maxx,x);
		maxy=max(maxy,y);
	}
	init();
	int l=0,r=n;
	int mid;
	int ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		} 
		else l=mid+1; 
	}
	printf("%d\n",ans);
}
