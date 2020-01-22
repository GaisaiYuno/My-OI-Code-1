#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 25
#define maxw 10000
using namespace std;
int c,g;
int x[maxn],m[maxn];
long long dp[maxn][maxw*2+5];
int main(){
	scanf("%d %d",&c,&g);
	for(int i=1;i<=c;i++) scanf("%d",&x[i]);
	for(int i=1;i<=g;i++) scanf("%d",&m[i]);
	dp[0][maxw]=1;
	for(int i=1;i<=g;i++){
		for(int j=0;j<=maxw*2;j++){
			for(int k=1;k<=c;k++){
				dp[i][j]=dp[i][j]+dp[i-1][j-m[i]*x[k]];
			}
		}
	}
	cout<<dp[g][maxw]<<endl;
} 
//dp[i][j] i个砝码，力矩矢量和为j-10000(防止负数出现) 
//dp[i][j]=dp[i][j]+dp[i-1][j-m[i]*x[k]]
