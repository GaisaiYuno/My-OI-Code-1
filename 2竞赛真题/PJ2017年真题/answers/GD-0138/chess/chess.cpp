#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
//red 0 yellow 1 nothing 2
using namespace std;

int map[101][101],n,m,ans=0x7fffffff,vis[101][101];
const int px[4]={1,-1,0,0},py[4]={0,0,1,-1};

struct node{
	int lx,ly,x,y,step;
}chx[101][101];

int get_step(int lx,int ly,int x,int y,int fx,int fy,int s){
	if(map[x][y]==0x7f7f7f7f and map[fx][fy]==0x7f7f7f7f)return 0x7fffffff;
	if(map[x][y]==map[fx][fy])return 0;
	if(map[x][y]+map[fx][fy]==1)return 1;
	if(map[x][y]==0x7f7f7f7f)return map[lx][ly]==map[fx][fy]?0:1;
	if(map[fx][fy]==0x7f7f7f7f)return 2;
}

void bfs(int xx,int yy){
	queue<node> q;
	q.push(node{-1,-1,xx,yy,0});
	vis[xx][yy]=0;
	while(!q.empty()){
		int lx=q.front().lx;
		int ly=q.front().ly;
		int x=q.front().x;
		int y=q.front().y;
		int step=q.front().step;
		q.pop();
		if((x==n and y==n) or (step>vis[x][y])){
			continue;
		}
		for(int i=0;i<=3;i++){
			int fx=x+px[i];
			int fy=y+py[i];
			if(fx<=n and fx>=1 and fy<=n and fy>=1){
				int fs=get_step(lx,ly,x,y,fx,fy,step);
				if(fs!=0x7fffffff){
					if(vis[fx][fy]>step+fs){
						vis[fx][fy]=step+fs;
						q.push(node{x,y,fx,fy,step+fs});
					}
				}
			}
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(map,0x7f,sizeof(map));
	memset(vis,0x7f,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&map[x][y]);
	}
	bfs(1,1);
	printf("%d",vis[n][n]==0x7f7f7f7f?-1:vis[n][n]);
	return 0;
}
