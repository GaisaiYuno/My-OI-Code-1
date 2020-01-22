#include<iostream>
#include<cstring>
#define maxn 11
using namespace std; 
int t,n;
int a[maxn];
int dp[maxn][maxn];//表示i的位置为a[i] 
int abs(int x){
	return x>=0?x:-x;
}
int main(){
	cin>>t;
	while(t--){
		int x;
		memset(a,0,sizeof(a));		
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=10;i++){
			cin>>x;
			a[x]=i;
		}
		for(int len=1;len<maxn-1;len++){
			for(int i=1;i+len<maxn;i++){
				dp[i][i+len]=dp[i][i+len-1]+abs(a[i+len]-a[i+len-1]);
				for(int j=1;j<i+len;j++){
					dp[i][i+len]=min(dp[i][j-1]+dp[j][i+len]+abs(a[i+len]-a[j-1]),dp[i][i+len]);
				}
			}
		}
		cout<<dp[1][10]<<endl;
	}
}
