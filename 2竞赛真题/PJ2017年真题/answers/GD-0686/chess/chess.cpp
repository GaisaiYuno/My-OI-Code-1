#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxx = 106, maxy = 106;

int m, n, x, y, c;
int color[maxx][maxy], head, tail, a, b, cr, mon, n_a, n_b, n_cr, t_a[4] = {-1, 0, 0, 1}, t_b[4] = {0, -1, 1, 0};
bool mag;
int money[maxx][maxy];

struct node {
	int h, l, colour, mony;
	bool magic;
}open[10 * maxx * maxy];

bool check(int);
void place(bool, int, int);

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);

	scanf("%d%d", &m, &n);

	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
			color[i][j] = money[i][j] = -1;

	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &x, &y, &c);
		color[x][y] = c;
	}

	head = tail = 1;
	open[head].h = open[head].l = 1;
	open[head].magic = 0;
	open[head].colour = color[1][1];
	open[head].mony = 0;
	money[1][1] = 0;
	while (head <= tail) {
		a = open[head].h;
		b = open[head].l;
		mag = open[head].magic;
		cr = open[head].colour;
		mon = open[head].mony;
		for (int i = 0; i < 4; ++i) {
			n_a = a + t_a[i];
			n_b = b + t_b[i];
			n_cr = color[n_a][n_b];
			if (n_a < 1 || n_a > m || n_b < 1 || n_b > m)
				continue;
			if (n_cr == -1) {
				if (! mag && ! check(2))
					place(1, 2, cr);
			}
				else {
				if (cr == n_cr) {
					if (! check(0))
						place(0, 0, n_cr);
				}
					else {
					if (! check(1))
						place(0, 1, n_cr);
					}
				}
			}
		++head;
}

	printf("%d", money[m][m]);

	return 0;
}

bool check(int k) {
	return money[n_a][n_b] > -1 && money[n_a][n_b] <= mon + k;
}

void place(bool use, int k, int C) {
	++tail;
	open[tail].h = n_a;
	open[tail].l = n_b;
	open[tail].magic = use;
	open[tail].colour = C;
	open[tail].mony = mon + k;
	money[n_a][n_b] = mon + k;
}
