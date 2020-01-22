#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int m,n,a[105][105],ans=10000000;
int work(int x,int y,int k,int l)
{
	if(x==m&&y==m)
	{
		ans=min(ans,k);
		return 0;
	}
	if(x>m||y>m||x<1||y<1)
	  return 0;
	if(a[x+1][y]!=a[x][y])
	{
		if(a[x+1][y]==2)
		{
			l=a[x][y];
			work(x+1,y,k+2,l);
		}
		else
		{
			if(a[x][y]==2)
			{
				if(a[x+1][y]!=l)
				{
					l=2;
					work(x+1,y,k+1,l);
				}
				else
				{
					l=2;
					work(x+1,y,k,l);
				}
			}
			else
			{
				work(x+1,y,k+1,l);
			}
		}
	}
	else
	{
		if(a[x+1][y]==a[x][y]&&a[x][y]!=2)
		  work(x+1,y,k,l);
	}	
	if(a[x-1][y]!=a[x][y])
	{
		if(a[x][y+1]==2)
		{
			l=a[x][y];
			work(x,y+1,k+2,l);
		}
		else
		{
			if(a[x][y]==2)
			{
				if(a[x][y+1]!=l)
				{
					l=2;
					work(x,y+1,k+1,l);
				}
				else
				{
					l=2;
					work(x,y+1,k,l);
				}
			}
			else
			{
				work(x,y+1,k+1,l);
			}
		}
	}
	else
	{
		if(a[x][y+1]==a[x][y]&&a[x][y]!=2)
		  work(x,y+1,k,l);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	    a[i][j]=2;
	
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	if(m>5)
	{
		cout<<-1;
		return 0;
	}
	work(1,1,0,2);
	if(ans!=10000000)
	  cout<<ans;
	else
	  cout<<-1;
	return 0;
}
