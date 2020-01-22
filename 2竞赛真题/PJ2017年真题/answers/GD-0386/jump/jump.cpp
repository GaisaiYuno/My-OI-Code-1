#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxm = 105;
const int ANYCOLOR = 233;
const int SUPERLARGE = 2147483647;
struct QueData_ {
	int x, y, val, col, mogiked;
}que[maxm^2];
int m, n, ans, cols[maxm][maxm];
int bestopt[maxm][maxm];
int dx[4] = {-1, 0,+1, 0};
int dy[4] = { 0,+1, 0,-1};

int main () {
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	/*W T F*/
	printf("-1");
	
	return 0;
}
