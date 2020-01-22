#include<cstdio>
#include<cstring>
#define INF 1000001
using namespace std;
const int nx[4]={-1,0,0,1},ny[4]={0,-1,1,0};
int a[101][101],b[101][101],m,n,x,y,c,Ans[101][101],na,nb;
int Pay(int m,int n,int p,int q)
{
	if(a[m][n]&&!a[p][q])
		return 2;
	if((a[m][n]&&a[p][q]&&a[m][n]!=a[p][q])||(!a[m][n]&&b[m][n]!=a[p][q]))
		return 1;
	return 0;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(Ans,INF,sizeof(Ans));
	Ans[1][1]=0;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&c);
		a[x][y]=c+1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<4;k++)
			{
				na=i+nx[k];
				nb=j+ny[k];
				if(na<1||na>m||nb<1||nb>m||Ans[na][nb]==INF||(!a[na][nb]&&!a[i][j]))
					continue;
				if(Ans[i][j]>Ans[na][nb]+Pay(na,nb,i,j))
				{
					if(!a[i][j])
						b[i][j]=a[na][nb];
					Ans[i][j]=Ans[na][nb]+Pay(na,nb,i,j);
					if(!a[na][nb])
						b[na][nb]=0;
				}
			}
		}
	}
	if(Ans[m][m]<INF)
		printf("%d",Ans[m][m]);
	else
		printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
