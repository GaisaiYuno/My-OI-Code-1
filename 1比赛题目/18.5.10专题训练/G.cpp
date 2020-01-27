#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 205
using namespace std;
char a[maxn][maxn];
int used[maxn][maxn];
int n,m;
int cnt=0;
const int walkx[4]= {1,-1,0,0},walky[4]= {0,0,1,-1};
struct node {
	int x;
	int y;
	int t;
	node() {}
	node(int xx,int yy,int tim) {
		x=xx;
		y=yy;
		t=tim;
	}
	friend bool operator <(node p,node q) {
		return p.t>q.t;
	}
};
int is_ok(int x,int y) {
	if(a[x][y]=='#') return 0;
	if(used[x][y]==1) return 0;
	if(x<=0||y<=0||x>n||y>m) return 0;
	return 1;
}
int bfs(int sx,int sy) {
	priority_queue<node>q;
	q.push(node(sx,sy,0));
	memset(used,0,sizeof(used));
	used[sx][sy]=1;
	while(!q.empty()) {
		node now=q.top();
		q.pop();
		if(a[now.x][now.y]=='a') {
			return now.t;
		}
		for(int i=0; i<4; i++) {
			int xx=now.x+walkx[i];
			int yy=now.y+walky[i];
			int tt=0;
			if(is_ok(xx,yy)) {
				if(a[xx][yy]=='x') tt=now.t+2;
				else tt=now.t+1;
				used[xx][yy]=1;
				q.push(node(xx,yy,tt));
			}
		}

	}
	return 0;
}
int main() {
	int sx,sy;
	while(scanf("%d %d\n",&n,&m)!=EOF) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				scanf("%c",&a[i][j]);
				if(a[i][j]=='r') {
					sx=i;
					sy=j;
				}
			}
			getchar();
		}
		int ans=bfs(sx,sy);
		if(ans==0) printf("Poor ANGEL has to stay in the prison all his life.\n");
		else printf("%d\n",ans);
	}
}
