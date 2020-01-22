# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
const int N = 1e2 + 10;
struct node
{
	int x,y,cost,col,p;
}q[N * N * 500];
int a[N][N],bz[N][N][4],dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int n,m,i,ans;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(bz,0x3f,sizeof(bz));
	scanf("%d%d",&m,&n);
	for (i = 1;i <= n; i++)
	{
		int x,y,tmp;
		scanf("%d%d%d",&x,&y,&tmp);
		++tmp;
		a[x][y] = tmp;
	}
	int h = 1,t = 1;
	bz[1][1][a[1][1]] = 0;
	q[h] = (node){1,1,0,a[1][1],0};
	while (h <= t)
	{
		node now = q[h++];
		for (i = 0;i < 4; i++)
		{
			int x1 = now.x + dir[i][0],y1 = now.y + dir[i][1];
			if (x1 < 1 || x1 > m || y1 < 1 || y1 > m) continue;
			if (!a[x1][y1] && now.p) continue;
			if (a[x1][y1] == now.col)
			{
				int col = now.col;
				int cost = now.cost;
				if (cost >= bz[x1][y1][col]) continue;
				bz[x1][y1][col] = cost;
				q[++t] = (node){x1,y1,cost,col,0};
			}else
			if (a[x1][y1] != now.col && a[x1][y1] != 0)
			{
				int col = a[x1][y1];
				int cost = now.cost + 1;
				if (cost >= bz[x1][y1][col]) continue;
				bz[x1][y1][col] = cost;
				q[++t] = (node){x1,y1,cost,col,0};
			}else
			if (a[x1][y1] == 0 && now.p == 0)
			{
				int col = 1;int cost = now.cost + 2;
				if (col != now.col) ++cost;
				if (cost >= bz[x1][y1][col]) continue;
				bz[x1][y1][col] = cost;
				q[++t] = (node){x1,y1,cost,col,1};
				col++; cost = now.cost + 2;
				if (col != now.col) ++cost;
				if (cost >= bz[x1][y1][col]) continue;
				bz[x1][y1][col] = cost;
				q[++t] = (node){x1,y1,cost,col,1};
			}
		}
	}
	ans = min(bz[m][m][1],bz[m][m][2]);
	if (ans > 2 * m * m) puts("-1");
	else printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
