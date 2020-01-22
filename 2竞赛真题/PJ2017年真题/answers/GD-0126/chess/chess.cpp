#include <cstdio>
using namespace std;
int m, n, cost, lastX, lastY;
int map[128][128] = {-1}, money[128][128] = {-1};
bool impossible = false, enable[128][128] = {true}, visited[128][128] = {false};
void search(int x, int y) {
	int temp = money[lastX][lastY];
	visited[x][y] = true;
	if (map[x][y] == -1 && !enable[lastX][lastY]) {
		impossible = true;
		return;
	}
	if (map[x][y] == -1 && enable[lastX][lastY]) {
		enable[x][y] = false;
		temp += 2;
	}
	if (map[x][y] != -1 && map[x][y] != map[lastX][lastY] && map[lastX][lastY] != -1) {
		enable[x][y] = true;
		temp += 1;
	}
	if (map[x][y] != -1 && map[lastX][lastY] == -1) {
		enable[x][y] = true;
	}
	if (!visited[x][y]) money[x][y] = temp;
	if (visited[x][y] && temp <= money[x][y]) money[x][y] = temp;
	lastX = x, lastY = y;
	if (x < m) search(x + 1, y);
	if (y < m) search(x, y + 1);
	return;
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		map[x][y] = c;
	}
	lastX = 0, lastY = 1;
	money[0][1] = 0;
	search(1, 1);
	cost = money[m][m];
	impossible = true;
	if (impossible) printf("-1");
	else printf("%d", cost);
	return 0;
}
