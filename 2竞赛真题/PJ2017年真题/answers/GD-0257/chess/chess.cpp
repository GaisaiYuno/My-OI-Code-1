#include <cstdio>
#include <algorithm>

using std::min;

using namespace std;

#define MAXQ 300000
#define IMX 2147483647

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int map[105][105];
bool flag[105][105][3];
int f[105][105][3];

struct Data {
	int x, y;
	bool UsingMo;
	int MoC;
} q[MAXQ + 5];

int SPFA(int n)
{
	f[1][1][0] = 0;
	flag[1][1][0] = 1;
	q[0].x = 1; q[0].y = 1;
	q[0].UsingMo = 0; q[0].MoC = 0;
	int head = 0, tail = 1;
	while (head != tail) {
		for (int i = 0; i < 4; ++ i) {
			int xx = q[head].x + dx[i];
			int yy = q[head].y + dy[i];
			if (xx < 1 || xx > n || yy < 1 || yy > n)
				continue;
			int mm = 0;
			if (map[xx][yy]) {
				if (q[head].UsingMo)
					mm = f[q[head].x][q[head].y][q[head].MoC] + (q[head].MoC != map[xx][yy]);
				else
					mm = f[q[head].x][q[head].y][0] + (map[q[head].x][q[head].y] != map[xx][yy]);
				if (mm < f[xx][yy][0]) {
					f[xx][yy][0] = mm;
					if (!flag[xx][yy][0]) {
						flag[xx][yy][0] = 1;
						q[tail].x = xx; q[tail].y = yy;
						q[tail].UsingMo = 0; q[tail].MoC = 0;
						tail = (tail + 1) % MAXQ;
					}
				}
			} else {
				if (q[head].UsingMo)
					continue;
				mm = f[q[head].x][q[head].y][0] + 2;
				int MoC = map[q[head].x][q[head].y];
				if (mm < f[xx][yy][MoC]) {
					f[xx][yy][MoC] = mm;
					if (!flag[xx][yy][MoC]) {
						flag[xx][yy][MoC] = 1;
						q[tail].x = xx; q[tail].y = yy;
						q[tail].UsingMo = 1; q[tail].MoC = MoC;
						tail = (tail + 1) % MAXQ;
					}
				}
			}
		}
		flag[q[head].x][q[head].y][q[head].MoC] = 0;
		head = (head + 1) % MAXQ;
	}
}

int main(void)
{
	freopen("chess.in",  "r",  stdin);
	freopen("chess.out", "w", stdout);
	int m = 0, n = 0;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++ i)
		for (int j = 1; j <= m; ++ j)
			for (int k = 0; k <= 2; ++ k)
				f[i][j][k] = IMX;
	for (int i = 1; i <= n; ++ i) {
		int x = 0, y = 0, c = 0;
		scanf("%d%d%d", &x, &y, &c);
		map[x][y] = c + 1;
	}
	SPFA(m);
	if (map[m][m])
		printf("%d", (f[m][m][0] == IMX) ? -1 : f[m][m][0]);
	else
		printf("%d", (min(f[m][m][1], f[m][m][2]) == IMX) ? -1 : min(f[m][m][1], f[m][m][2]));
	return 0;
}

