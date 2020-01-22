#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int m,n,tu[110][110],tor1,tor2,tor3,ans=0x7fffffff;
void dfs(int x,int y,int mon,int col)
{
//	cout<<x<<" "<<y<<" "<<mon<<" "<<col<<endl;
	if(x==m&&y==m)
	{
		ans=min(ans,mon);
		return;
	}
	if(x+1<=m)
	{
		tor1=x+1;tor2=y;
		if(tu[tor1][tor2]!=3||tu[x][y]!=3)
		{
			if(tu[tor1][tor2]==col) dfs(tor1,tor2,mon,col);
			else
			{
				if(tu[tor1][tor2]==3&&tu[x][y]!=3) dfs(tor1,tor2,mon+2,col);
				else  dfs(tor1,tor2,mon+1,tu[tor1][tor2]);
			}
		}
	}
	if(y+1<=m)
	{
		tor1=x;tor2=y+1;
		if(tu[tor1][tor2]!=3||tu[x][y]!=3)
		{
			if(tu[tor1][tor2]==col) dfs(tor1,tor2,mon,col);
			else
			{
				if(tu[tor1][tor2]==3&&tu[x][y]!=3) dfs(tor1,tor2,mon+2,col);
				else  dfs(tor1,tor2,mon+1,tu[tor1][tor2]);
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
	 	for(int j=1;j<=m;j++)
	 	{
	  		tu[i][j]=3;
	  	}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&tor1,&tor2,&tor3);
		tu[tor1][tor2]=tor3;
	}
	dfs(1,1,0,tu[1][1]);
	if(ans==0x7fffffff) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
*/
