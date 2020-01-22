#include<iostream>
#include<cstring>
#define maxn 31
using namespace std;
int c,n;
long long dp[maxn];
int main(){
	cin>>c;
	while(c--){
		cin>>n;
		dp[1]=1;
		dp[2]=3;
		for(int i=3;i<=n;i++){
			dp[i]=2*dp[i-2]+dp[i-1];
		}
		cout<<dp[n]<<endl;
	}
} 
