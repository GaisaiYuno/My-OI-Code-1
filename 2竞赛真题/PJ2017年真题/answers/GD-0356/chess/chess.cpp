#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int map[101][101],n,m,x,y,in,ans=10000000,step[4][2]={{-1,0},{0,1},{1,0},{0,-1}},used[101][101];
bool ok=false,ue=false;

void dfs(int a,int b,int pay)
{
	int w,e;
	if(a==m&&b==m)
	{
		if(pay<ans)ans=pay;
		ok=true;
		return;
	}
	else
	for(int i=0;i<4;i++)
	{
		w=a+step[i][0];
		e=b+step[i][1];
		if((w<=m&&w>=1)&&(e<=m&&e>=1))
		{
			if(map[w][e]==map[a][b]&&map[w][e]!=0&&used[w][e]==0)
			{
				if(ue==true)ue=false;
				used[w][e]=1;
				dfs(w,e,pay);
				used[w][e]=0;
			}
			else if(map[w][e]==0&&used[w][e]==0&&ue==false)
			{
				used[w][e]=1;
				ue=true;
				map[w][e]=map[a][b];
				dfs(w,e,pay+2);
				map[w][e]=0;
				used[w][e]=0;
				ue=false;
			}
			else if(map[a][b]!=map[w][e]&&map[a][b]!=0&&map[w][e]!=0&&used[w][e]==0)
			{
				if(ue==true)ue=false;
				used[w][e]=1;
				dfs(w,e,pay+1);
				used[w][e]=0;
			}
		}
	}
}


int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(used,0,sizeof(used));
	memset(map,0,sizeof(map));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&in);
		map[x][y]=in+1;
	}
	if(m<=35)
	{
	used[1][1]=1;
	dfs(1,1,0);
	if(ok==false)ans=-1;
	printf("%d",ans);
	}
	else printf("-1");
	return 0;
}
