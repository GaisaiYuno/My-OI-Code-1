#include <cstdio>
#include <climits>
using namespace std;
int n,m,x,y,c,MIN = INT_MAX,color[200][200],b[200][200][3];
const int f[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y,bool hasUse,int hasPaid,int current) {
	if (x == m && y == m) {
		if (hasPaid<MIN) MIN = hasPaid;
		return;
	}
	for (int i = 0;i<4;i++) {
		int newX = x+f[i][0],newY = y+f[i][1],paid = 0;
		if ((newX < 1) || (newY < 1) || (newX > m) || (newY > m)) continue;
		if (color[newX][newY] != 0) {
			if (color[newX][newY] != current) paid = 1;
			if (b[newX][newY][color[newX][newY]] > hasPaid+paid) {
				b[newX][newY][color[newX][newY]] = hasPaid+paid;
				dfs(newX,newY,false,hasPaid+paid,color[newX][newY]);
			}
		} else {
			if (hasUse) continue;
			paid = 2;
			if (b[newX][newY][current] > hasPaid+paid) {
				b[newX][newY][current] = hasPaid+paid;
				dfs(newX,newY,true,hasPaid+paid,current);
			}
		}
	}
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i = 0;i<n;i++) {
		scanf("%d%d%d",&x,&y,&c);
		color[x][y] = c+1;
	}
	for (int i = 0;i<200;i++)
		for (int j = 0;j<200;j++)
			for (int k = 0;k<3;k++) b[i][j][k] = INT_MAX;
	b[1][1][color[1][1]] = 0;
	dfs(1,1,false,0,color[1][1]);
	printf("%d",((MIN == INT_MAX)?(-1):(MIN)));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
