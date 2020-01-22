#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxm = 105;
const int EXTRALARGE = 20000000;
const int SUPERLARGE = 2147483647;
struct QueData_ {
	int x, y, val, col, mogiked;
}que[EXTRALARGE];
int m, n, ans, cols[maxm][maxm];
int bestopt[maxm][maxm];
int dx[4] = {-1, 0,+1, 0};
int dy[4] = { 0,+1, 0,-1};


bool in_the_board(int a, int b) {
	return 0<a && a<=m && 0<b && b<=m; 
};

int main () {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	
	scanf("%d%d", &m, &n);
	memset(bestopt, -1, sizeof(bestopt));
	/*for (int i=1; i<=m; i++)
		for (int j=1; j<=m; j++) bestopt[i][j] = -1;*/
	
	for (int i=1; i<=n; i++) {
		int xx, yy, colo;
		scanf("%d%d%d", &xx, &yy, &colo);
		cols[xx][yy] = colo+1;
	}
	
	int head = 0, tail = 1;
	que[0].x = 1; 
	que[0].y = 1; 
	que[0].val = 0; 
	bestopt[1][1] = 0;
	que[0].col = cols[1][1];
	que[0].mogiked = 0;
	ans = SUPERLARGE;
	while (head<tail) {
		//printf("!");
		//printf("%d", head);/////
		QueData_ first = que[head];
		for (int i=0; i<4; i++) if (in_the_board(first.x+dx[i], first.y+dy[i])){
			int newx = first.x+dx[i];
			int newy = first.y+dy[i];
			int nextcol = cols[newx][newy];
			if (nextcol == 0) {
				if (!first.mogiked  && (first.val+2 < bestopt[newx][newy] || bestopt[newx][newy] == -1) )
				{
					if (/*first.val+2+1 < bestopt[newx][newy] || */(first.col == 1)) {
						que[tail].x = newx;
						que[tail].y = newy;
						que[tail].val = first.val + 2;
						if (first.col != 1) que[tail].val++;
						que[tail].col = 1; //MAKE IT RED
						que[tail].mogiked = 1;
						bestopt[newx][newy]= que[tail].val;
						tail ++;
					}
				
					if (/*first.val+2+1 < bestopt[newx][newy] || */(first.col == 2)) {
						que[tail].x = newx;
						que[tail].y = newy;
						que[tail].val = first.val + 2;
						if (first.col != 2) que[tail].val++;
						que[tail].col = 2; // MAKE IT YELLOW
						que[tail].mogiked = 1;
						bestopt[newx][newy] = que[tail].val;
						tail ++;
					}
				}
			} else {
				if (nextcol != 0) {
					//{
					//printf("%d#", bestopt[newx][newy]);///
					if ((nextcol == first.col)    &&   (first.val < bestopt[newx][newy] || bestopt[newx][newy] == -1)) {
						que[tail].x = newx;
						que[tail].y = newy;
						que[tail].val = first.val;
						que[tail].col = first.col;//cols[que[tail].x][que[tail].y];
						que[tail].mogiked = 0;
						bestopt[newx][newy] = que[tail].val;	
						tail ++;
						//printf("@");///		
					} else
					if (nextcol != first.col   &&   (first.val+1 < bestopt[newx][newy] || bestopt[newx][newy] == -1)) {
						que[tail].x = newx;
						que[tail].y = newy;
						que[tail].val = first.val + 1;
						que[tail].col = first.col;//cols[que[tail].x][que[tail].y];
						que[tail].mogiked = 0;
						bestopt[newx][newy] = que[tail].val;	
						tail ++;		
					}
				}
			}
		}
		if (que[head].x == m && que[head].y ==m) 
				{
					//printf("Get!:%d\n", que[head].val);//////
					ans = min(ans, que[head].val);
				}
		head++;
	}
	/*printf("\nPRINT THE QUE(len:%d)::\n", tail);
	for (int i=1; i<=300; i++) {
		printf("\n(%d,%d)	val:%d	col:%d	mo?:%d\n", que[i].x, que[i].y, que[i].val, que[i].col, que[i].mogiked);
	}
	printf("\END\n");*/
	
	if (ans != SUPERLARGE) printf("%d", ans); else printf("-1");
	
	return 0;
}
