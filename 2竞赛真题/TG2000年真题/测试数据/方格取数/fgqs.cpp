#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 11 
using namespace std;
int n,xx,yy,ans1,ans2;
int a[maxn][maxn],dp[maxn][maxn],d[maxn][maxn];
inline int fread(){
	int x=0;
	char c=getchar();
	int sign=1;
	while(c<'0'||c>'9') {
		c=getchar();
		if(c=='-') sign=-1;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
void my_print(int x,int y) {
	//printf("(%d,%d) %d\n",x,y,d[x][y]);
	if(x==1&&y==1){
		a[x][y]=0;
		return;
	}
	if(d[x][y]==1) my_print(x,y-1);	//×ó
	if(d[x][y]==2) my_print(x-1,y);	//ÉÏ
	if(d[x][y]==3) my_print(x-1,y-1);
	if(a[x][y]!=0) a[x][y]=0;
}
int main(){
	//freopen("fgqs5.in","r",stdin);
	//freopen("fgqs.out","w",stdout);
	cin>>n;
	int u,v,w;
	while(u!=0&&v!=0&&w!=0){
		u=fread();
		v=fread();
		w=fread();
		a[u][v]=w;
	}
	ans1=ans2=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i-1][j]<dp[i][j-1]){
				dp[i][j]=dp[i][j-1]+a[i][j];
				d[i][j]=1;
			}
			else if(dp[i-1][j]>dp[i][j-1]){
				dp[i][j]=dp[i-1][j]+a[i][j];
				d[i][j]=2;
			}
			else{
				dp[i][j]=dp[i-1][j-1]+a[i][j];
				d[i][j]=3;
			}
		    if(dp[i][j]>ans1){
		    	ans1=dp[i][j];
		    	xx=i;
		    	yy=j;
			}
		}
	} 
	my_print(xx,yy);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i-1][j]<dp[i][j-1]){
				dp[i][j]=dp[i][j-1]+a[i][j];
				//a[i][j]=0;
			}
			else{
				dp[i][j]=dp[i-1][j]+a[i][j];
				//a[i][j]=0;
			}
			ans2=max(ans2,dp[i][j]);
		}
	}
	cout<<ans1<<' '<<ans2<<endl;
	cout<<ans1+ans2<<endl;
	return 0;
}
/*
7
1 3 2
1 4 3
2 3 3
3 3 3
5 5 4
6 5 4
7 3 2
7 5 4
0 0 0

0 0 2 3 0 0 0 0
0 0 3 0 0 0 0 0
0 0 3 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 4 0 0 0
0 0 0 0 4 0 0 0
0 0 2 0 4 0 0 0
*/ 










