#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int p[2][4]={{1,-1,0,0},{0,0,1,-1}};
int n,m,ans=0x7fffffff,map[110][110],vis[110][110];
void dfs(int x,int y,int money,int color,bool check){
	if(x==n&&y==n){
		ans=min(ans,money);
		return;
	}
	for(int i=0;i<=3;i++){
		int nx=p[0][i]+x,ny=p[1][i]+y;
		if(!nx||!ny||nx==n+1||ny==n+1)
			continue;
		if(!vis[nx][ny]){
			vis[nx][ny]=1;
			if(map[nx][ny]==-1){
				if(check)
					dfs(nx,ny,money+2,color,0);
			}
			else
				if(map[nx][ny]==color)
					dfs(nx,ny,money,color,1);
				else
					dfs(nx,ny,money+1,map[nx][ny],1);
			vis[nx][ny]=0;
		}
	}
	vis[x][y]=1;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(map,-1,sizeof(map));
	while(m--){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c+1;
	}
	dfs(1,1,0,map[1][1],1);
	ans==0x7fffffff?puts("-1"):printf("%d",ans);
	return 0;
}
