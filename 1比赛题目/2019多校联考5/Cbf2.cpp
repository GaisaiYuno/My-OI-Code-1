#include<iostream>
#include<cstdio>
#define maxn 1000
using namespace std; 
int n,k;
int dp[maxn+5][maxn+5]; 
int main(){
	scanf("%d %d",&n,&k);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int u=0;u<=j;u++) dp[i][j]+=dp[i-1][u];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
}
//C(n+k-1,k)
