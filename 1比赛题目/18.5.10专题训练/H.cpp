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
};
int is_ok(int x,int y) {
	if(a[x][y]=='#') return 0;
	if(used[x][y]==1) return 0;
	if(x<=0||y<=0||x>n||y>m) return 0;
	return 1;
}
int bfs(int sx,int sy) {
	queue<node>q;
	q.push(node(sx,sy,0));
	memset(used,0,sizeof(used));
	used[sx][sy]=1;
	int cnt=0;
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		cnt++;
		for(int i=0; i<4; i++) {
			int xx=now.x+walkx[i];
			int yy=now.y+walky[i];
			int tt=0;
			if(is_ok(xx,yy)) {
				tt=now.t+1;
				used[xx][yy]=1;
				q.push(node(xx,yy,tt));
			}
		}

	}
	return cnt;
}
int main() {
	int sx,sy;
	while(scanf("%d %d",&n,&m)!=EOF) {
		getchar();
		if(n==0&&m==0){
			 return 0;
		} 
		swap(n,m);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				scanf("%c",&a[i][j]);
				if(a[i][j]=='@') {
					sx=i;
					sy=j;
				}
			}
			getchar();
		}
		int ans=bfs(sx,sy);
		printf("%d\n",ans);
	}
}
