//http://hzwer.com/3570.html
//从任意一个X节点画一条射线与边界垂直
//当我们从右向左bfs的时候碰到这条线，就停止bfs；当我们绕了一圈从左向右bfs的时候碰到这条线，我们就继续走 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int sx,sy,tx,ty;
char tmp[maxn+5];
char a[maxn+5][maxn+5]; 
int dist[2][maxn+5][maxn+5];
int mark[maxn+5][maxn+5];
//  dist[1][x][y]表示从左向右经过这条线之后起点到(x,y)的最短距离，
//dist[0][x][y]表示没有经过这条线，起点到(x,y)的最短距离。
//当我们从左向右经过这条线后的bfs我们就只更新dist[1][x][y]，最后输出的就是dist[1][起点x][起点y]。
struct node{
	int x;
	int y;
	int flag;
	node(){
		
	}
	node(int _x,int _y,int _flag){
		x=_x;
		y=_y;
		flag=_flag;
	}
};
queue<node>q;
int dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={1,-1,0,1,-1,0,1,-1};
void bfs(int sx,int sy){
	dist[0][sx][sy]=0;
	q.push(node(sx,sy,0));
	while(!q.empty()){
		node now=q.front();
		q.pop();
//		printf("(%d,%d) flag=%d dist=%d\n",now.x,now.y,now.flag,dist[now.flag][now.x][now.y]);
		for(int i=0;i<8;i++){
			int xx=now.x+dx[i];
			int yy=now.y+dy[i];
			if(xx>0&&yy>0&&xx<=n&&yy<=m&&a[xx][yy]!='X'){
				if(mark[now.x][now.y]&&yy<=now.y) continue;
				if(mark[xx][yy]&&yy>now.y){
					if(dist[1][xx][yy]==INF){
						dist[1][xx][yy]=dist[0][now.x][now.y]+1;
						q.push(node(xx,yy,1));
					}
				}else{
					if(dist[now.flag][xx][yy]==INF){
						dist[now.flag][xx][yy]=dist[now.flag][now.x][now.y]+1;
						q.push(node(xx,yy,now.flag));
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",tmp+1);
		for(int j=1;j<=m;j++){
			a[i][j]=tmp[j];
			if(tmp[j]=='*'){
				sx=i;
				sy=j;
			}
			if(tmp[j]=='X'){
				tx=i;
				ty=j;
			}
		}
	}
	for(int i=tx;i<=n;i++){
		mark[i][ty]=1;
	}
	memset(dist,0x3f,sizeof(dist));
	bfs(sx,sy);
	printf("%d\n",dist[1][sx][sy]);
}
