#include <iostream>
#include <queue>
using namespace std;
struct stp
{
	int x;
	int y;
	int mx;
	int my;
};
queue<stp> ygy;
int n, m, r, c, x, y;
char map[2005][2005];
bool go[2005][2005];
int mx[] = {0, 0, 1, -1}, my[] = {1, -1, 0, 0};
int ans;
int main()
{
	cin >> n >> m >> r >> c >> x >> y;
	r--, c--;
	ygy.push({r, c, x, y});
	for (int i = 0; i < n; i++)
		cin >> map[i];
	while (ygy.size())
	{
		stp a = ygy.front();
		ygy.pop();
		if (a.mx < 0 || a.my < 0)
			continue;
		if (go[a.x][a.y])
			continue;
		go[a.x][a.y] = 1;
		ans++;
		for (int i = 0; i < 4; i++)
		{
			int tx = a.x + mx[i], ty = a.y + my[i];
			if (tx < 0 || ty < 0 || tx == n || ty == m)
				continue;
			if (go[tx][ty])
				continue;
			if (map[tx][ty] == '*')
				continue;
			ygy.push({tx, ty, a.mx - (my[i] == -1), a.my - (my[i] == 1)});
		}
	}
	cout << ans;
}
