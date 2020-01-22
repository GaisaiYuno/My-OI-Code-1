#include<cstdio>
#include<cstdlib>
using namespace std;
int fx[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int n,m,map[201][201],x[40001],y[40001],ch[40001],cl[40001],nu[201][201],o[40001];
int main()
{	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++) for (int j=1;j<=m;j++) nu[i][j]=200000000;
	for (int i=1;i<=n;i++)
	{
		int x1,y1,c;
		scanf("%d%d%d",&x1,&y1,&c);
		c++;
		map[x1][y1]=c;
	}
	int t=1,h=1,pp=0;
	x[1]=1;
	y[1]=1;
	cl[1]=map[1][1];
	while (t<=h)
	{
		if (x[t]==m&&y[t]==m) pp=1;
		for (int i=0;i<4;i++)
		{
			int x1=x[t]+fx[i][0],y1=y[t]+fx[i][1];
			if (x1<=0||x1>m||y1<=0||y1>m||(map[x[t]][y[t]]==0&&map[x1][y1]==0)) continue;
			if (map[x1][y1]==0&&nu[x1][y1]>o[t]+2)
			{
				o[++h]=o[t]+2;
				nu[x1][y1]=o[t]+2;
				x[h]=x1;
				y[h]=y1;
				cl[h]=map[x[t]][y[t]];
			}else
			if (map[x1][y1]!=cl[t]&&nu[x1][y1]>o[t]+1)
			{
				o[++h]=o[t]+1;
				nu[x1][y1]=o[t]+1;
				x[h]=x1;
				y[h]=y1;
				cl[h]=map[x1][y1];
			}else
			if (map[x1][y1]==cl[t]&&nu[x1][y1]>o[t])
			{
				o[++h]=o[t];
				nu[x1][y1]=o[t];
				x[h]=x1;
				y[h]=y1;
				cl[h]=map[x1][y1];
			}
		}
		t++;
	}
	if (pp==0) printf("-1\n");
		else printf("%d\n",nu[m][m]);
	fclose(stdin);
	fclose(stdout);
}
