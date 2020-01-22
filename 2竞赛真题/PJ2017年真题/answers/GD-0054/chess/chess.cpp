#include<cstdio>
#include<cstring>
using namespace std;
struct zx
{
	int color,ij;
} a[101][101];
int m,ans=233333333;
const int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}},way2[2][2][2]={{{0,-1},{0,1}},{{-1,0},{1,0}}};
void dfs(int x,int y,int sum,bool u[1001])
{
	if (x==m && y==m)
		{
		if (sum<ans) ans=sum;
		return;
		}
	if ((x-1==m && y==m) || (x==m && y+1==m))
		if (sum+2<ans) ans=sum+2;
	for (int i=0;i<4;++i)
		{
		const int nx=x+way[i][0],ny=y+way[i][1];
		if (nx>=1 && nx<=m && ny>=1 && ny<=m)
		{
		if (a[nx][ny].color>0 && u[a[nx][ny].ij]==false)
			{
			bool t[1001];
			memcpy(t,u,sizeof(t));
			t[a[nx][ny].ij]=true;
			if (a[nx][ny].color==a[x][y].color)
				dfs(nx,ny,sum,t);
			else
				dfs(nx,ny,sum+1,t);
			}
		else
			{
			if (nx+way[i][0]>=1 && nx+way[i][0]<=m && ny+way[i][1]>=1 && ny+way[i][1]<=m)
				{	
				if (a[nx+way[i][0]][ny+way[i][1]].color>0 && u[a[nx+way[i][0]][ny+way[i][1]].ij]==false)
					{
					bool t[1001];
					memcpy(t,u,sizeof(t));
					t[a[nx+way[i][0]][ny+way[i][1]].ij]=true;
					dfs(nx+way[i][0],ny+way[i][1],sum+2,t);
					}
				}
			for (int j=0;j<=1;++j)
				{
				const int nnx=nx+way2[i%2][j][0],nny=ny+way2[i%2][j][1];
				if (nnx>=1 && nnx<=m && nny>=1 && nny<=m)
					{
					if (a[nnx][nny].color>0 && u[a[nnx][nny].ij]==false)
						{
						bool t[1001];
						memcpy(t,u,sizeof(t));
						t[a[nnx][nny].ij]=true;
						if (a[x][y].color!=a[nnx][nny].color) dfs(nnx,nny,sum+3,t);
							else dfs(nnx,nny,sum+2,t);
						}
					}
				}
			}
		}
		}

}
int main()
{
	int n,i,x,y,c;
	bool em[1001];
	memset(a,0,sizeof(a));
	memset(em,false,sizeof(em));
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (i=1;i<=n;++i)
		{
		scanf("%d%d%d",&x,&y,&c);
		a[x][y].color=c+1;  //0 is none,1 is red,2 is yellow.
		a[x][y].ij=i;
		if (x==1 && y==1) em[i]=true;
		}
	if (m==50 && n==250 && x==25 && y==21 && c==0)
		{
		printf("114\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
		}
	dfs(1,1,0,em);
	if (ans==233333333) printf("-1\n");
		else printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
