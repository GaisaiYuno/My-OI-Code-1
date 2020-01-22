#include<iostream>
#define maxn 25
using namespace std;
int n,m;
long long dp[maxn][maxn];//dp[i][j]表示i个H,j个D的种数 
int main(){
	for(int i=1;i<=20;i++) dp[i][1]=i;
	//dp[1][1]=1;
	for(int i=2;i<=20;i++){
		for(int j=2;j<=20;j++){
			if(i>=j) dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	while(cin>>n>>m){
		cout<<dp[n][m]<<endl;
	}
}
