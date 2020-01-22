#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 15 
using namespace std;
int n;
int a[maxn][maxn],dp[maxn][maxn][maxn][maxn]; 
inline int qread(){
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
int main(){
	//freopen("fgqs.in","r",stdin);
	//freopen("fgqs.out","w",stdout);
	cin>>n;
	int u,v,w;
	u=v=w=1;
	while(u!=0||v!=0||w!=0){
		u=qread();
		v=qread();
		w=qread();
		a[u][v]=w;
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int u=1;u<=n;u++){
					int tmp=0;
					if(dp[i-1][j][k-1][u]>tmp) tmp=dp[i-1][j][k-1][u];
					if(dp[i-1][j][k][u-1]>tmp) tmp=dp[i-1][j][k][u-1];
					if(dp[i][j-1][k][u-1]>tmp) tmp=dp[i][j-1][k][u-1];
					if(dp[i][j-1][k-1][u]>tmp) tmp=dp[i][j-1][k-1][u];
					if(i==k&&j==u)dp[i][j][k][u]=max(dp[i][j][k][u],a[i][j]+tmp);
					else  dp[i][j][k][u]=max(dp[i][j][k][u],a[i][j]+a[k][u]+tmp); 
				}
			}
		}
	}
	cout<<dp[n][n][n][n]<<endl;
	return 0;
}




