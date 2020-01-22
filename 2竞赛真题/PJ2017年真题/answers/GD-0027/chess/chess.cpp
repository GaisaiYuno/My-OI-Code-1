#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int n,m,x,y,c,dp[1100][1100],colour[1100][1100];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(colour,-1,sizeof(colour));
	memset(dp,0,sizeof(dp));
	cin>>m>>n;
	for (int i=1;i<=n;i++){
		cin>>x>>y>>c;
		colour[x][y]=c;
	}
//	for (int i=1;i<=m;i++) dp[i][1]=0;
//	for (int i=1;i<=m;i++) dp[1][i]=0;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++){
			if (colour[i-1][j]==1&&colour[i][j]==1) dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if (colour[i-1][j]==1&&colour[i][j]==0) dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
			if (colour[i-1][j]==0&&colour[i][j]==0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if (colour[i-1][j]==0&&colour[i][j]==1) dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
			if (colour[i][j-1]==1&&colour[i][j]==1) dp[i][j]=max(dp[i][j],dp[i][j-1]);
			if (colour[i][j-1]==1&&colour[i][j]==0) dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
			if (colour[i][j-1]==0&&colour[i][j]==0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
			if (colour[i][j-1]==0&&colour[i][j]==1) dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
			
			/*
			if (colour[i][j]!=0&&colour[i][j]!=1){
				
			}
			*/
		}
	}
	/*
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
	if (dp[m][m]!=0) cout<<dp[m][m];
	else cout<<"-1";
	return 0;
}
