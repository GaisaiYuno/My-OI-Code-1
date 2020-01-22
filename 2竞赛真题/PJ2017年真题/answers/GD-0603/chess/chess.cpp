#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int m,n,cost=0;

struct block
{
	int c=2;
}b[110][110];

bool check(int x,int y)
{
	if(b[x+1][y].c==2&&b[x][y+1].c==2)return false;
	else return true;
}

void dfs(int x,int y)
{
	if(x==m&&y==m)return;
	if(check(x,y))
	{
		if(b[x+1][y].c!=2&&b[x+1][y].c==b[x][y].c)dfs(x+1,y);
		else if(b[x][y+1].c!=2&&b[x][y+1].c==b[x][y].c)dfs(x,y+1);
		else if(b[x][y+1].c==2){cost++;dfs(x+1,y);}
		else if(b[x+1][y].c==2){cost++;dfs(x,y+1);}
	}	
	else
	{
		if(b[x+1][y+1].c!=2)
		{
			if(b[x+1][y+1].c==b[x][y].c){cost+=2;dfs(x+1,x+1);}
			else {cost+=3;dfs(x+1,x+1);}
		}
		else if(b[x+2][y].c!=2)
		{
			if(b[x+2][y].c==b[x][y].c){cost+=2;dfs(x+2,y);}
			else {cost+=3;dfs(x+2,y);};
		}
		else if(b[x][y+2].c!=2)
		{
			if(b[x][y+2].c==b[x][y].c){cost+=2;dfs(x,y+2);}
			else {cost+=3;dfs(x,y+2);}
		}
		else cost=-1;
		
	}
	return;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i;
	cin>>m>>n;
	for(i=1;i<=n;i++)	
	{
		int x,y;
		cin>>x>>y;
		cin>>b[x][y].c;
	}
	dfs(1,1);
	cout<<cost;
	fclose(stdin);fclose(stdout);
	return 0;
}
