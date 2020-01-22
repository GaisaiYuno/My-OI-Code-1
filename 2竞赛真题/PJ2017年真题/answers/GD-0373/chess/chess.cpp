#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[105][105],ans,x,y;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m+1;i++)
	  for(int j=1;j<=m+1;j++)
	    a[i][j]=-1;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	x=1,y=1;
	bool b=0,c=1;
	while(x!=m || y!=m)
	{
		if(b==0)
		{
			if(a[x+1][y]==a[x][y] || a[x][y+1]==a[x][y])
			{
				if(a[x+1][y]==a[x][y] || y==m)
		    	  x+=1;
		    	else
		    	{
		    		if(a[x][y+1]==a[x][y] || x==m)
			          y+=1;
		    	}
			}
			else
			{
				if(a[x+1][y]!=-1 || a[x][y+1]!=-1)
				{
					if(a[x+1][y]!=-1 || y==m)
					{
						ans++;
						x+=1;
					}
					else
					{
						if(a[x][y+1]!=-1 || x==m)
					    {
					    	ans++;
				    		y+=1;
			    		}
					}
				}
				else
				{
					if(a[x+1][y+1]==-1 && a[x+2][y]==-1 && a[x][y+2]==-1)
					{
						c=0;
						break;
					}
					else
					{
						if(a[x+1][y+1]!=-1 || a[x+2][y]==a[x][y] || y==m)
						{
							ans+=2;
							b=1;
					        a[x+1][y]=a[x][y];
							x+=1;
						}
						else
						{
							if(a[x][y+2]==a[x][y] || x==m)
				    		{
			    			    ans+=2;
		    			    	b=1;
	    				    	a[x][y+1]=a[x][y];
    				    		y+=1;
   							}
						}	
					}
				}
			}
		}
		else
		{
			if(a[x+1][y]==a[x][y] || a[x][y+1]==a[x][y])
			{
				if(a[x+1][y]==a[x][y] || y==m)
		    	  x+=1;
		    	else
		    	{
		    		if(a[x][y+1]==a[x][y] || x==m)
			          y+=1;
		    	}
			}
			else
			{
				if(a[x+1][y]!=-1 || y==m)
				{
					ans++;
					x+=1;
				}
				else
				{
					if(a[x][y+1]!=-1 || x==m)
					{
					    ans++;
					    y+=1;							
					}
				}
			}
			b=0;
		}
	}
    if(c==0)
	  cout<<"-1";
	else
	  cout<<ans;
	return 0;
}
