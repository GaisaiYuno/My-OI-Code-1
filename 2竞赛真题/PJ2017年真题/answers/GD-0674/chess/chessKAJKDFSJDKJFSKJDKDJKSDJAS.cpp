#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define yellow 2
#define red    1
#define null   0
#define found  -1
int xx,yy,c1;
int m,n,am[105][105];
int min1=1000000000;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(char x,char y,char nowc,short mon,bool bbb)
{
	if(  x<1||x>m  ||  y<1||y>m  )		return;
	if(x==m&&y==m)
	 if(mon<min1)
	 {
	 	 if(bbb)
		  min1=mon;
		 else
		  min1=mon+1;
		 return;
	 }
	am[x][y]=found;
	if(nowc==null)
	{
		bool kkk=false;
		for(int i=0;i<4;i++)
		{
			if(am[x+dx[i]][y+dy[i]]==yellow||am[x+dx[i]][y+dy[i]]==red)
			 kkk=true;
		}
		if(!kkk)
		{
			am[x][y]=null;
			return;
		}
	}
	for(int i=0;i<4;i++)
	{
		if(		am[x+dx[i]][y+dy[i]]	==	found	)
		 continue;
		else if(		am[x+dx[i]][y+dy[i]]	==	nowc	)
		 dfs(x+dx[i],y+dy[i],nowc,mon,true);
		else if(		am[x+dx[i]][y+dy[i]]	==	null	)
		 dfs(x+dx[i],y+dy[i],null,mon+2,true);
		else if(		am[x+dx[i]][y+dy[i]]	!=	nowc	)
		 dfs(x+dx[i],y+dy[i],(nowc==yellow)?red:yellow,mon+1,false);
	}
	am[x][y]=nowc;
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(am,0,sizeof(am));
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>xx>>yy>>c1;
		am[xx][yy]=c1+1;//2=yellow,1=red;
	}
	if(am[m][m]==null)
	{
		cout<<"-1";
		return 0;
	}
	dfs(1,1,am[1][1],0,true);
	if(min1==1000000000)
	{
		cout<<"-1";
		return 0;
	}
	cout<<min1;
	return 0;
}

