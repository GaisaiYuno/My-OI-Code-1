#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 9
#define maxs 5
#define INF 0x7fffffff
using namespace std;
struct node {
	int x;
	int y;
	int cost;
	int state;
	node() {

	}
	node(int xx,int yy,int c,int s) {
		x=xx;
		y=yy;
		cost=c;
		state=s;
	}
};
int a[maxn][maxn];
int used[maxn][maxn][maxs];
const int walkx[4]= {1,-1,0,0},walky[4]= {0,0,1,-1};
int bfs(int sx,int sy,int ex,int ey) {
	queue<node>q;
	memset(used,0x3f,sizeof(used));
	q.push(node(sx,sy,0,1));
	node now,nex;
	int ans=INF;
	while(!q.empty()) {
		now=q.front();
		q.pop();
		if(now.x==ex&&now.y==ey) {
			ans=min(ans,now.cost);
		}
		for(int i=0; i<4; i++) {
			nex.x=now.x+walkx[i];
			nex.y=now.y+walky[i];
			if(nex.x<=0||nex.y<=0||nex.x>8||nex.y>8) continue;
			nex.cost=now.cost+a[nex.x][nex.y]*now.state;
			nex.state=now.state*a[nex.x][nex.y]%4+1;
			if(used[nex.x][nex.y][nex.state]<=nex.cost) continue;
			used[nex.x][nex.y][nex.state]=nex.cost;
			q.push(nex);
		}
	}
	return ans;
}
int main() {
	int x1,y1,x2,y2;
	while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2)!=EOF) {
		if(x1==0&&y1==0&&x2==0&&y2==0) break;
		for(int i=1; i<=8; i++) {
			for(int j=1; j<=8; j++) {
				scanf("%d",&a[i][j]);
			}
		}
		printf("%d\n",bfs(x1,y1,x2,y2));
	}
}
