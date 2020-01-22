#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
using namespace std;
int color[110][110];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
bool vis[110][110][3][2];
struct data
{	int x, y, c, s;
	bool bo;
	data(int _1, int _2, int _3, bool _4, int _5):x(_1), y(_2), c(_3), bo(_4), s(_5) {}
	bool operator < (const data &a) const { return s > a.s; }
};
priority_queue<data> q;
int main()
{	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++)
	{	int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		color[x][y] = c+1;
	}
	q.push(data(n, n, 0, 0, 0));
	while(!q.empty())
	{	int x = q.top().x, y = q.top().y, c = q.top().c, s = q.top().s;
		bool bo = q.top().bo;
		q.pop();
		if(x == 1 && y == 1) { printf("%d\n", s); return 0; }
//		vis[x][y][c][bo] = 0;
		bool flag = 0;
		for(int i=0; i<4; i++)
		{	int tx = x+dx[i], ty = y+dy[i];
			if(tx < 1 || tx > n || ty < 1 || ty > n) continue;
			if(color[tx][ty] == 0 && !bo)
			{	for(int j=1; j<=2; j++)
					if(!vis[tx][ty][j][1])
					{	q.push(data(tx, ty, j, 1, s + 2 + (c == j ? 0 : 1)));
						vis[tx][ty][j][1] = 1;
					}
			}
			else if(color[tx][ty])
			{	if(!vis[tx][ty][color[tx][ty]][0])
				{	q.push(data(tx, ty, color[tx][ty], 0, s + (c == color[tx][ty] ? 0 : 1)));
					vis[tx][ty][color[tx][ty]][0] = 1;
				}
			}
		}
	}
	puts("-1");
	return 0;
}
