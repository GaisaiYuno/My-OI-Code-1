#include<cstdio>
using namespace std;
int n,m,mp[102][102],mn=50000,stp[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y,int s,bool mfed)
{
	if(s>=mn)return;
	if(x==n&&y==n)
	{
		if(s<mn)mn=s;
		return;
	}
	int tmp=mp[x][y];
	mp[x][y]=-2;
	for(int i=0;i<4;i++)
	{
		if(x+stp[i][0]<1||x+stp[i][0]>n||y+stp[i][1]<1||y+stp[i][1]>n)continue;
		if(mp[x+stp[i][0]][y+stp[i][1]]>=0)
		{
			if(tmp!=mp[x+stp[i][0]][y+stp[i][1]])s++;
			dfs(x+stp[i][0],y+stp[i][1],s,false);
		}
		if(!mfed&&mp[x+stp[i][0]][y+stp[i][1]]==-1)
		{
			mp[x+stp[i][0]][y+stp[i][1]]=tmp;
			dfs(x+stp[i][0],y+stp[i][1],s+2,true);
			mp[x+stp[i][0]][y+stp[i][1]]=-1;
		}
	}
	mp[x][y]=tmp;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int i=0;i<102;i++)
	  for(int j=0;j<102;j++)mp[i][j]=-1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int tmpx,tmpy;
		scanf("%d%d",&tmpx,&tmpy);
		scanf("%d",&mp[tmpx][tmpy]);
	}
	dfs(1,1,0,false);
	printf("%d",mn==50000?-1:mn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
