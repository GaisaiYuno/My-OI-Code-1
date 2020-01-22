#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
const int inf=2e9;
const int dx1[4]={0,0,1,-1},dy1[4]={1,-1,0,0};
const int dx2[8]={-2,-1,-1,0,0,1,1,2},dy2[8]={0,1,-1,2,-2,1,-1,0};
int n,m,x,y,c,f[maxn][maxn];
char s[maxn][maxn];
int dfs(int x,int y)
{
	if(x<2||y<2||x>n+1||y>n+1)return inf;
	if(f[x][y])return f[x][y];
	if(x==n+1&&y==n+1)return f[x][y]=0;
	if(x==n+1&&y==n&&s[n+1][n+1]=='#')return 2;
	if(x==n&&y==n+1&&s[n+1][n+1]=='#')return 2;
	f[x][y]=inf;
	for(int i=0;i<4;i++)if(s[x+dx1[i]][y+dy1[i]]!='#')
	f[x][y]=min(f[x][y],dfs(x+dx1[i],y+dy1[i])+(s[x][y]==s[x+dx1[i]][y+dy1[i]]?0:1));
	for(int i=0;i<8;i++)if(s[x+dx2[i]][y+dy2[i]]!='#')
	f[x][y]=min(f[x][y],dfs(x+dx2[i],y+dy2[i])+(s[x][y]==s[x+dx2[i]][y+dy2[i]]?2:3));
	return f[x][y];
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(s,'#',sizeof s);
	for(int i=0;i<m;i++)scanf("%d%d%d",&x,&y,&c),s[x+1][y+1]=(c?'y':'r');
	dfs(2,2);
	if(f[2][2]==inf)printf("-1\n");
	else printf("%d\n",f[2][2]);
	fclose(stdin);fclose(stdout);
	return 0;
}
