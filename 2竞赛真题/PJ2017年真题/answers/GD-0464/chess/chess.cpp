#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 110;
const int oo = 100000000;

int ss[maxn][maxn];
int cl[maxn][maxn];
int dis[maxn][maxn][3];

int n, m;

int xx[4]={0, 0, 1, -1};
int yy[4]={1, -1, 0, 0};

int dfs(int x, int y, int co) {
	
	if(x==n && y==n) {
		if(cl[x][y] == 2) return 2;
		if(cl[x][y] != co) return 1;
		if(cl[x][y] == co) return 0;
	}
	
	int _min = oo;
	for (int kb=0; kb<4; kb++) {
		int nx = x+xx[kb], ny = y+yy[kb];
		if(nx<1||nx>n||ny<1||ny>n) continue;
		if(ss[nx][ny] == 1) continue;
		
		ss[nx][ny] = 1;
		
		
		if(cl[nx][ny] != 2 && cl[x][y] != 2) {
			if(dis[nx][ny][cl[x][y]]) {
				_min =min(_min, dis[nx][ny][cl[x][y]]);
				continue;
			}
			dis[nx][ny][cl[x][y]] = dfs(nx, ny, cl[x][y]), _min = min(_min, dis[nx][ny][cl[x][y]]);
		}
		else if(cl[nx][ny] == 2 && cl[x][y] != 2) {
			if(dis[nx][ny][cl[x][y]]) {
				_min =min(_min, dis[nx][ny][cl[x][y]]);
				continue;
			}
			dis[nx][ny][cl[x][y]] = dfs(nx, ny, cl[x][y]), _min = min(_min, dis[nx][ny][cl[x][y]]);
		}
		else if(cl[nx][ny] != 2 && cl[x][y] == 2) {
				if(dis[nx][ny][co]) {
				
					_min =min(_min, dis[nx][ny][co]);
					continue;
				}
				dis[nx][ny][co] = dfs(nx, ny, co), _min = min(_min, dis[nx][ny][co]);
			}
			/*
			else {
				if(dis[nx][ny][cl[nx][ny]]) {
				
					_min =min(_min, dis[nx][ny][cl[nx][ny]]+1);
					continue;
				}
				dis[nx][ny][cl[nx][ny]] = dfs(nx, ny, cl[nx][ny]), _min = min(_min, dis[nx][ny][cl[nx][ny]]+1);
			}
			*/
		else continue;
		
		ss[nx][ny] = 0;
	}
	
	if(cl[x][y] == 2) return 2+_min;
	if(cl[x][y] != co) return 1+_min;
	if(cl[x][y] == co) return _min;
}

int main() {
	
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
		cl[i][j] = 2;
	
	for (int i=1, x, y, z; i<=m; i++) {
		
		scanf("%d %d %d", &x, &y, &z);
		cl[x][y] = z;	
	}
	/*
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			printf("%d ", cl[i][j]);
		}
		puts("");
	}
	*/
	int ans = dfs(1, 1, cl[1][1]);
	if(ans >= oo) printf("-1");
	else 		  printf("%d", ans);
	
	return 0;
}
