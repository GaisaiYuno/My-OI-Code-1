#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define Y 1
#define R 0

using namespace std;

int mov[5][3] = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};

int map[105][105];
int gold[105][105][3], m, n;

int main () {
	memset (map, -1, sizeof (map));
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	scanf ("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		int posx, posy, colour;
		scanf ("%d%d%d", &posx, &posy, &colour);
		map[posx][posy] = colour;
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != -1)gold[i][j][map[i][j]] = -1;
			else gold[i][j][Y] = gold[i][j][R] = -1;
		}			
	if (map[1][1] != -1)gold[1][1][map[1][1]] = 0;
	else gold[1][1][Y] = gold[1][1][R] = 0;
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++){
			for (int k = 1; k <= 4; k++) {
				int tmpx = i + mov[k][0], tmpy = j + mov[k][1];
				if (tmpx < 1 || tmpx > m || tmpy < 1 || tmpy > m) continue;
				if (map[i][j] == -1 && map[tmpx][tmpy] == -1) continue;
				if (map[i][j] == -1)if (gold[i][j][R] == -1 && gold[i][j][Y] == -1) break;
				if (map[i][j] != -1)if (gold[i][j][map[i][j]] == -1) break;
				if  (map[i][j] == -1) {
					
					if (gold[tmpx][tmpy][map[tmpx][tmpy]] == -1)
						gold[tmpx][tmpy][map[tmpx][tmpy]] = min (gold[i][j][R] + (map[tmpx][tmpy] == Y), gold[i][j][Y] + (map[tmpx][tmpy] == R));
					else {
						gold[tmpx][tmpy][map[tmpx][tmpy]] = min (gold[tmpx][tmpy][map[tmpx][tmpy]], 
										min (gold[i][j][R] + (map[tmpx][tmpy] == Y), gold[i][j][Y] + (map[tmpx][tmpy] == R)));
					}
				} 
				if (map[tmpx][tmpy] == -1) {
					if (gold[tmpx][tmpy][R] == -1)
						gold[tmpx][tmpy][R] = gold[i][j][map[i][j]] + 2 + (map[i][j] == Y);
					else 
						gold[tmpx][tmpy][R] = min (gold[tmpx][tmpy][R], gold[i][j][map[i][j]] + 2 + (map[i][j] == Y));
						
					if (gold[tmpx][tmpy][Y] == -1)
						gold[tmpx][tmpy][Y] = gold[i][j][map[i][j]] + 2 + (map[i][j] == R);
					else 
						gold[tmpx][tmpy][Y] = min (gold[tmpx][tmpy][Y], gold[i][j][map[i][j]] + 2 + (map[i][j] == R));
				}
				if (map[tmpx][tmpy] != -1 && map[i][j] != -1) {
					if (map[tmpx][tmpy] == map[i][j]) {
						if (gold[tmpx][tmpy][map[tmpx][tmpy]] == -1)
							gold[tmpx][tmpy][map[tmpx][tmpy]] = gold[i][j][map[i][j]];
						else
							gold[tmpx][tmpy][map[tmpx][tmpy]] = min (gold[tmpx][tmpy][map[tmpx][tmpy]], gold[i][j][map[i][j]]);
					} else {
						if (gold[tmpx][tmpy][map[tmpx][tmpy]] == -1)
							gold[tmpx][tmpy][map[tmpx][tmpy]] = gold[i][j][map[i][j]] + 1;
						else
							gold[tmpx][tmpy][map[tmpx][tmpy]] = min (gold[tmpx][tmpy][map[tmpx][tmpy]], gold[i][j][map[i][j]] + 1);
					}
						
							
				}
				
			}
		}
	if (map[m][m] != -1)printf ("%d\n", gold[m][m][map[m][m]]);
	else printf ("%d\n", min (gold[m][m][R], gold[m][m][Y]));
	fclose (stdin);
	fclose (stdout);
	return 0;
}
