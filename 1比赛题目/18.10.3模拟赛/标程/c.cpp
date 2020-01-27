#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
unsigned long long int n,a,b,c;
unsigned long long int dp[100][100][100];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>a>>b>>c;
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) for(int k=0;k<=c;k++) dp[i][j][k]=n;
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			for(int k=0;k<=c;k++){
				if(i) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]>>1);
				if(j) dp[i][j][k]=min(dp[i][j][k],(dp[i][j-1][k]+1)>>1);
				if(k) dp[i][j][k]=min(dp[i][j][k],(dp[i][j][k-1]-1)>>1);
				if(dp[i][j][k]==0){
					cout<<0<<endl;
					return 0;
				}
			}
		}
	}
	cout<<dp[a][b][c]<<endl;
	return 0;
}

/*

dp[i][j][k]=MIN( dp[i+1][j][k] >>1 , dp[i][j+1][k]+1 >>1 , dp[i][j][k+1]-1 >>1 )

*/
