#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 110,
	      dx[] = {-1, 0, 0, 1},
		  dy[] = {0, -1, 1, 0};

int n, m;
int a[MAXN][MAXN];
int dis[MAXN][MAXN];
bool inq[MAXN][MAXN];

struct point {
	int x, y;
	int dis;
	int color;
};

void bfs() {
	queue < point > Q;
	point tmp;
	tmp.x = 1, tmp.y = 1, tmp.color = 0;
	Q.push(tmp);
	while(!Q.empty()) {
		point x = Q.front();
		Q.pop();
		
		for(int i = 0; i < 4; ++i) {
			int temp = 0;
			if(x.x + dx[i] < 1 || x.x + dx[i] > n || x.y + dy[i] < 1 || x.y + dy[i] > n) {
				continue;
			}
			if(a[x.x][x.y] == 0 && a[x.x + dx[i]][x.y + dy[i]] == 0) {
				continue;
			}
			if(inq[x.x + dx[i]][x.y + dy[i]]) {
				continue;
			}
			
			if(a[x.x][x.y] == 0) { // 出发点是用了魔法的 
				temp = a[x.x + dx[i]][x.y + dy[i]] != x.color;
				if(x.dis + temp < dis[x.x + dx[i]][x.y + dy[i]]) {
					tmp.x = x.x + dx[i];
					tmp.y = x.y + dy[i];
					tmp.color = 0;
					dis[x.x + dx[i]][x.y + dy[i]] = x.dis + temp;
					Q.push(tmp);
				}
			}
			if(a[x.x + dx[i]][x.y + dy[i]] == 0) { // 到达的点要用魔法 
				// 假设是a种颜色
				temp = 2 + (a[x.x][x.y] != 1);
				tmp.x = x.x + dx[i];
				tmp.y = x.y + dy[i];
				tmp.color = 1;
				tmp.dis = dis[x.x][x.y] + temp;
				Q.push(tmp);
				// 假设是b种颜色 
				temp = 2 + (a[x.x][x.y] != 2);
				tmp.x = x.x + dx[i];
				tmp.y = x.y + dy[i];
				tmp.color = 2;
				tmp.dis = dis[x.x][x.y] + temp;
				Q.push(tmp);
			}
			if(a[x.x][x.y] != 0 && a[x.x + dx[i]][x.y + dy[i]] != 0) {
				temp = a[x.x][x.y] != a[x.x + dx[i]][x.y + dy[i]];
				if(dis[x.x][x.y] + temp < dis[x.x + dx[i]][x.y + dy[i]]){
					tmp.x = x.x + dx[i];
					tmp.y = x.y + dy[i];
					tmp.color = 0;
					tmp.dis = 0;
					dis[x.x + dx[i]][x.y + dy[i]] = dis[x.x][x.y] + temp;
					Q.push(tmp);
				}
			}
		}
	}
}

int main(void) {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(a, 0, sizeof a);
	for(int i = 0; i < m; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		a[x][y] = c + 1;
	}
	memset(dis, 0x3f, sizeof dis);
	dis[1][1] = 0;
	bfs();
	printf("%d\n", dis[n][n] == 0x3f3f3f3f ? -1 : dis[n][n]);
	return 0;
}
