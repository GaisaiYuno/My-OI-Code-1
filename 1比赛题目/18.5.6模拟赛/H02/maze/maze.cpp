#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define INF 2139062143
#define maxn 205
using namespace std;
char map[maxn][maxn];
int dis[maxn][maxn],used[maxn][maxn];
int w,h;
int n,m;
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
struct node{
	int x;
	int y;
	int d;
	node(){}
	node(int a,int b,int c){
		x=a;
		y=b;
		d=c;
	}
};
void bfs(int sx,int sy){
	queue<node>q;
	memset(used,0,sizeof(used));
	q.push(node(sx,sy,1));
	node now,nex;
	while(!q.empty()){
		now=q.front();
		q.pop();
		int x,y;
		for(int i=0;i<4;i++){
			x=now.x+walkx[i];
			y=now.y+walky[i];
			if(used[x][y]==1||x<=0||y<=0||x>n||y>m||map[x][y]!=' '||dis[x][y]<now.d+1) continue;
			nex=node(x,y,now.d+1);
			used[x][y]=1;
			dis[x][y]=min(dis[x][y],nex.d);
			q.push(nex);
		}
	}
}
int conv_dis(int x){
	if(x%2==0) return x/2;
	else return x/2+1;
}
int is_edge(int x,int y){
	if(x==1) return 1;
	if(y==1) return 1;
	if(x==n) return 1;
	if(y==m) return 1;
	else return 0;
}
char tmp[maxn];
int main(){
//	freopen("maze2.in","r",stdin);
//	freopen("maze.out","w",stdout);
	scanf("%d %d",&w,&h);
	n=2*w+1;
	m=2*h+1;
	swap(n,m);
	int x1,x2,y1,y2;
	x1=x2=y1=y2=-1;
	for(int i=0; i<=n; i++) {
		gets(map[i]+1);
    }

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(is_edge(i,j)){
				if(map[i][j]==' '&&x1==-1&&y1==-1){
					 x1=i;
					 y1=j;
				}else if(map[i][j]==' '){
					 x2=i;
					 y2=j;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) dis[i][j]=INF;
	}
	bfs(x1,y1);
	bfs(x2,y2);
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==0&&j%2==0&&dis[i][j]!=INF){
				ans=max(ans,conv_dis(dis[i][j]));
			}
		}
//		printf("\n");
	}
	printf("%d\n",ans);
}
/*
5 3
+-+-+-+-+-+
|         |
+-+ +-+ + +
|     | | |
+ +-+-+ + +
| |     |  
+-+ +-+-+-+

*/
