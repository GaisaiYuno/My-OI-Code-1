//#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<memory.h>
#include<algorithm>
#include<fstream>

using namespace std;
ifstream cin ("chess.in" ,ios::in );
ofstream cout("chess.out",ios::out);
/*
#define 
ask(s1,s2)	  //s1 to s2
	(s1==s2	?0//TheSame
	:s1==-1	?0//WhiteToColor
	:s2==-1	?2//ColorToWhite
	:		 1)//DifferentColor
*/
long long min_spend=0x7fffffffffffffff,m,n;
short	color[102][102];
bool	been[102][102];

long long dfs(long long x,long long y,short yet_color,long long spend)
{
	been[x][y]=true;
	
	if(spend>min_spend||x>m||y>m||!x||!y)
		return 0x7fffffffffffffff;
	if(x==m&&y==m)
	{
		//cout<<x<<' '<<y<<' '<<spend<<'\n';
		min_spend=min(min_spend,spend);
		return spend;
	}
	//cout<<'('<<x<<','<<y<<")"<<spend<<"->\n";
	long long k=0x7fffffffffffffff;
	bool flag=yet_color!=-1;
	
	if(color[x+1][y]==-1&&flag&&!been[x+1][y])
		color[x+1][y]=color[x][y],
		dfs(x+1,y,-1,spend+2),
		color[x+1][y]=-1;
	if(color[x][y+1]==-1&&flag&&!been[x][y+1])
		color[x][y+1]=color[x][y],
		dfs(x,y+1,-1,spend+2),
		color[x][y+1]=-1;
	if(color[x][y-1]==-1&&flag&&!been[x][y-1])
		color[x][y-1]=color[x][y],
		dfs(x,y-1,-1,spend+2),
		color[x][y-1]=-1;
	if(color[x-1][y]==-1&&flag&&!been[x-1][y])
		color[x-1][y]=color[x][y],
		dfs(x-1,y,-1,spend+2),
		color[x-1][y]=-1;
	
	if(color[x+1][y]!=-1&&!been[x+1][y])
		dfs(x+1,y,color[x][y],spend+(color[x+1][y]!=color[x][y]));
	if(color[x][y+1]!=-1&&!been[x][y+1])
		dfs(x,y+1,color[x][y],spend+(color[x][y+1]!=color[x][y]));
	if(color[x][y-1]!=-1&&!been[x][y-1])
		dfs(x,y-1,color[x][y],spend+(color[x][y-1]!=color[x][y]));
	if(color[x-1][y]!=-1&&!been[x-1][y])
		dfs(x-1,y,color[x][y],spend+(color[x-1][y]!=color[x][y]));
	
	been[x][y]=false;
	return k;
}
int main()
{
	memset(been,false,sizeof(been));
	memset(color,-1,sizeof(color));
	cin>>m>>n;
	long long i,x,y;
	for(i=1;i<=n;++i)
		cin>>x>>y,
		cin>>color[x][y];
	dfs(1,2,color[1][1],0);
	dfs(2,1,color[1][1],0);
	cout<<(min_spend==0x7fffffffffffffff?-1:min_spend)<<'\n';
	cin.clear();
	cout.clear();
	cin.close();
	cout.close();
	return 0;
}
/*
{
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
//
8
}
*/
