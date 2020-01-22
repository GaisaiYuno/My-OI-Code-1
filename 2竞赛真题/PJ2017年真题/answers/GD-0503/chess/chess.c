#include <stdio.h>
#include <string.h>
int board[100][100], scanlist[4], boardGONE[100][100];
long long minMethod = 1000000;

//0 = red, 1 = yellow, 4 = permantly red, 5 = permantly yellow.

void resetboard(){
	int k, l;
	for (k = 0; k < 100; k++){
		for (l = 0; l < 100; l++){
			board[k][l] = 3;
			boardGONE[k][l] = 0;
		}
	}
}

int scan(int x, int y, int color, int gold, int border){
	//printf("DID LOOP\n");
	boardGONE[x][y] = 1;
	//printf("NOW LOADING X: %d, Y: %d, STACKED GOLD: %d\n", x, y, gold);
	if (x >= border && y >= border) {
		if (gold < minMethod) {
			minMethod = gold;
		}
	}
	if (board[x][y + 1] == color) scan(x, y + 1, color, gold, border); //check right side
	if (board[x + 1][y] == color) scan(x + 1, y, color, gold, border); //check down side
	if (board[x][y + 1] == 1 - color) scan(x, y + 1, 1 - color, gold + 1, border); //check right side different color
	if (board[x + 1][y] == 1 - color) scan(x + 1, y, 1 - color, gold + 1, border); //check down side different color
	if (x > 1) {
		if (board[x - 1][y] == color && boardGONE[x][y] == 0) scan(x - 1, y, color, gold, border); //check up side
		if (board[x - 1][y] == 1 - color && boardGONE[x][y] == 0) scan(x - 1, y, 1 - color, gold + 1, border); //check up side different color
	}
	if (y > 1) {
		if (board[x][y - 1] == color && boardGONE[x][y] == 0) scan(x, y - 1, 1 - color, gold, border); //check left side
		if (board[x][y - 1] == 1 - color && boardGONE[x][y] == 0) scan(x, y - 1, 1 - color, gold + 1, border); //check left side different color
	}
	if (board[x][y + 1] == 3 && (board[x][y + 2] != 3 || board[x + 1][y + 1] != 3)) { //check no color coordinate on the right direction
		scan(x, y + 1, color, gold + 2, border);
	} else if (board[x + 1][y] == 3 && (board[x + 2][y] != 3 || board[x + 1][y + 1] != 3)) { //check no color coordinate on the down direction
		scan(x + 1, y, color, gold + 2, border);
	} else return -1;
	if (x > 1) {
		if (board[x - 1][y] == 3 && (board[x - 2][y] != 3 || board[x - 1][y - 1] != 3) && boardGONE[x][y] == 0) { //check no color coordinate on the up direction
			scan(x - 1, y, color, gold + 2, border);
		}
	}
	if (y > 1) {
		if (board[x][y - 1] == 3 && (board[x][y - 2] != 3 || board[x - 1][y - 1] != 3) && boardGONE[x][y] == 0) { //check no color coordinate on the up direction
			scan(x, y - 1, color, gold + 2, border);
		}
	}
	return 0;
}

int main(){
	FILE *chessin, *chessout;
	int m, n, i;
	int cdnX, cdnY, clr;
	int startX = 1, startY = 1, startCLR;
	int gd = 0;
	resetboard();
	//memset(board, 2, sizeof(board));
	chessin = fopen("chess.in", "r");
	chessout = fopen("chess.out", "w");
	fscanf(chessin, "%d%d", &m, &n);
	for (i = 1; i <= n; i++) {
		fscanf(chessin, "%d%d%d", &cdnX, &cdnY, &clr);
		board[cdnX][cdnY] = clr;
	}
	startCLR = board[cdnX][cdnY];
	//printf("%d\n", board[1][5]);
	scan(startX, startY, startCLR, gd, m);
	if (minMethod == 1000000) fprintf(chessout, "%d", -1);
	if (minMethod != 1000000) fprintf(chessout, "%d", minMethod);
	fclose(chessin);
	fclose(chessout);
	return 0;
}
