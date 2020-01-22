#include <iostream>
#include <cstdio>
using namespace std;
int n,m,x,y,c,a[101][101],i,f[101][101],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},pr;
bool b[101][101];
int mi(int a,int b)
{
	if (a>b) return b;
	else return a;
}
bool pd(int x,int y,int k)
{
	int x1=x+dx[k],y1=y+dy[k],o=f[x1][y1];
	if (a[x1][y1]==0)
	{
		if (a[x][y]==0) return false;
		f[x1][y1]=mi(f[x][y]+2,f[x1][y1]);
		if (o==f[x1][y1]) return false;
		else
		{
			pr=a[x][y];
			return true;
		}
	}
	else
	if (a[x1][y1]!=pr&&pr!=-1||pr==-1&&a[x1][y1]!=a[x][y])
	{
		f[x1][y1]=mi(f[x][y]+1,f[x1][y1]);
		pr=-1;
		if (o==f[x1][y1]) return false;
		else
		return true;
	}
	else
	if (a[x1][y1]==pr&&pr!=-1||pr==-1&&a[x1][y1]==a[x][y])
	{
		f[x1][y1]=mi(f[x][y],f[x1][y1]);
		pr=-1;
		if (o==f[x1][y1]) return false;
		else
		return true;
	}
}
void dfs(int x,int y)
{
	int i;
	for (i=0;i<4;i++)
	if (x+dx[i]>0&&x+dx[i]<m+1&&y+dy[i]>0&&y+dy[i]<m+1&&!b[x+dx[i]][y+dy[i]]&&pd(x,y,i))
	{
		b[x+dx[i]][y+dy[i]]=1;
		dfs(x+dx[i],y+dy[i]);
		b[x+dx[i]][y+dy[i]]=0;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	for (i=1;i<=m;i++)
	for (int j=1;j<=m;j++)
	f[i][j]=2147483647;
	f[1][1]=0;
	pr=-1;
	b[1][1]=true;
	dfs(1,1);
	if (f[m][m]==2147483647) printf("-1");
	else printf("%d",f[m][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
	//RP++
}
