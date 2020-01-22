#include<bits/stdc++.h>
using namespace std;
int ans,a[101][101],dp[101][101][2],m,n,i,j,x,y,c;
bool f[101][101];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=0;i<=m;i++){
		for(j=0;j<=m;j++){
			dp[i][j][1]=100000;
			dp[i][j][0]=100000;
			a[i][j]=2;
			f[i][j]=true;
		}
	}
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c;
	}
	if(a[1][1]!=2){
		dp[1][1][a[1][1]]=0;
	}
	else{
		dp[1][1][0]=2;
		dp[1][1][1]=2;
		f[1][1]=false;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			else{
				if(a[i][j]==2){
					if(f[i-1][j]){
						dp[i][j][1]=min(dp[i][j][1],min(dp[i-1][j][1]+2,dp[i-1][j][0]+3));
						dp[i][j][0]=min(dp[i][j][0],min(dp[i-1][j][0]+2,dp[i-1][j][1]+3));
					}
					if(f[i][j-1]){
						dp[i][j][1]=min(dp[i][j][1],min(dp[i][j-1][1]+2,dp[i][j-1][0]+3));
						dp[i][j][0]=min(dp[i][j][0],min(dp[i][j-1][0]+2,dp[i][j-1][1]+3));
					}
					f[i][j]=false;
				}
				else{
					dp[i][j][a[i][j]]=min(dp[i][j-1][a[i][j]],min(dp[i-1][j][1-a[i][j]]+1,dp[i][j-1][1-a[i][j]]+1));
					dp[i][j][a[i][j]]=min(dp[i-1][j][a[i][j]],dp[i][j][a[i][j]]);
				}
			}
		}
	}
	ans=min(dp[m][m][1],dp[m][m][0]);
	if(ans>=100000){
		cout<<-1;
	}
	else{
		cout<<ans;
	}
}
