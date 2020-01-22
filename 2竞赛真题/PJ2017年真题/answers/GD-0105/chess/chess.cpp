#include<cstdio>
#include<cstring>
int min(int a,int b){
	return a<b?a:b;
}
int m,n,ans=0x7fffffff;
int a[105][105];
bool vis[105][105];
void dfs(int i,int j,int magic,int cost){
	if(a[i][j]==0&&magic==0)return;
	if(i==m&&j==m){
		ans=min(cost,ans);
		return;
	}
	if(vis[i][j]==1)return;
	vis[i][j]=1;
	if(i+1<=m){
		if(a[i+1][j]!=0&&(magic==1||a[i+1][j]==a[i][j]))dfs(i+1,j,0,cost);
		else if(a[i][j]!=a[i+1][j]&&a[i+1][j]!=0)dfs(i+1,j,0,cost+1);
		else if(a[i+1][j]==0&&magic==0)dfs(i+1,j,1,cost+2);
	}
	if(i-1>=1){
		if(a[i-1][j]!=0&&(magic==1||a[i-1][j]==a[i][j]))dfs(i-1,j,0,cost);
		else if(a[i][j]!=a[i-1][j]&&a[i-1][j]!=0)dfs(i-1,j,0,cost+1);
		else if(a[i-1][j]==0&&magic==0)dfs(i-1,j,1,cost+2);
	}	
	if(j+1<=m){
		if(a[i][j+1]!=0&&(magic==1||a[i][j+1]==a[i][j]))dfs(i,j+1,0,cost);
		else if(a[i][j]!=a[i][j+1]&&a[i][j+1]!=0)dfs(i,j+1,0,cost+1);
		else if(a[i][j+1]==0&&magic==0)dfs(i,j+1,1,cost+2);
	}
	if(j-1>=1){
		if(a[i][j-1]!=0&&(magic==1||a[i][j-1]==a[i][j]))dfs(i,j-1,0,cost);
		else if(a[i][j]!=a[i][j-1]&&a[i][j-1]!=0)dfs(i,j-1,0,cost+1);
		else if(a[i][j-1]==0&&magic==0)dfs(i,j-1,1,cost+2);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	dfs(1,1,0,0);
	if(ans!=0x7fffffff)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
