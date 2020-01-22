#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,color[101][101],f[101][101];
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
bool vis[101][101];
int dfs(int x,int y){
	if(x==m && y==m) return 0;
	if(f[x][y]) return f[x][y];
	int ans=100000;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>0 && nx<=m && ny>0 && ny<=m && !vis[nx][ny] && (color[nx][ny] || color[x][y])){
			vis[nx][ny]=true;
			if(color[nx][ny]){
				if(color[nx][ny]==color[x][y]) ans=min(ans,dfs(nx,ny));
				else ans=min(ans,dfs(nx,ny)+1);
			} else ans=min(ans,dfs(nx,ny)+2);
			vis[nx][ny]=false;
		}
	}
	return f[x][y]=ans;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		color[x][y]=c+1;
	}
	vis[1][1]=true;
	int res=dfs(1,1);
	printf("%d\n",res>=100000?-1:res);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) printf("%d\t",f[i][j]>=100000?-1:f[i][j]);
//		printf("\n");
//	}
}
