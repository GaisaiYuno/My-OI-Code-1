#include<cstdio>
using namespace std;
int color[101][101],n,m,x,y,c,money;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		color[x][y]=c+1;
	}
	
	x=1;
	y=1;
	c=color[1][1];
	color[1][1]=0;
	while (true)
	{
		if (x+1==n && y==n && color[n][n]==c || x==n && y+1==n && color[n][n]==c || x==n && y==n) break;
		else if (x+1==n && y==n && color[n][n] || x==n && y+1==n && color[n][n]) {money++; break;}
		else if (x+1==n && y==n || x==n && y+1==n) {money+=2; break;}
		else if (color[x][y+1]==c) y++;
		else if (color[x+1][y]==c) x++;
		else if (color[x-1][y]==c) x--;
		else if (color[x][y-1]==c) y--;
		else if (color[x][y+1]) {money++;y++;c=color[x][y];}
		else if (color[x+1][y]) {money++;x++;c=color[x][y];}
		else if (color[x][y-1]) {money++;y--;c=color[x][y];}
		else if (color[x-1][y]) {money++;x--;c=color[x][y];}
		else if (color[x+1][y+1]==c) {money+=2;x++;y++;}
		else if (color[x+2][y]==c) {money+=2;x+=2;}
		else if (color[x][y+2]==c) {money+=2;y+=2;}
		else if (color[x+1][y+1]) {money+=3;x++;y++;c=color[x][y];}
		else if (color[x+2][y]) {money+=3;x+=2;c=color[x][y];}
		else if (color[x][y+2]) {money+=3;y+=2;c=color[x][y];}
		else if (color[x-1][y-1]==c) {money+=2;x--;y--;}
		else if (color[x-2][y]==c) {money+=2;x-=2;}
		else if (color[x][y-2]==c) {money+=2;y-=2;}
		else if (color[x-1][y-1]) {money+=3;x--;y--;c=color[x][y];}
		else if (color[x-2][y]) {money+=3;x-=2;c=color[x][y];}
		else if (color[x][y-2]) {money+=3;y-=2;c=color[x][y];}
		else {printf("-1");return 0;}
		color[x][y]=0;
	}
	printf("%d",money);
	return 0;
}
