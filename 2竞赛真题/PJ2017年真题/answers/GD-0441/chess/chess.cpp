#include<iostream>
#include<cstdio>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int m,n,x,y,col;
int a[150][150],b[150][150],f[150][150]={0};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1; i<=m; i++)
	    for(int j=1; j<=m; j++)
		    a[i][j]=-1; 
	f[1][1]=1;
	for(int i=1; i<=n; i++)
	{
		cin>>x>>y>>col;
		a[x][y]=col;
	}
	for(int i=1; i<=m; i++)
	    for(int j=1; j<=m; j++)
	    {
	    	if (a[i][j]!=-1)
	    	{
	    		for(int k=0; k<3; k++)
	    		{
	    			int nx,ny;
	    			nx=i+dx[k];
	    			ny=j+dy[k];
	    			if(nx>0&&nx<=m&&ny>0&&ny<=m&&a[nx][ny]!=-1)
	    			{
	    				if(a[i][j]==a[nx][ny])
	    				{
	    					f[nx][ny]=f[i][j];
	    					
	    				}
	    				if(a[i][j]!=a[nx][ny])
	    				{
	    					f[nx][ny]=f[i][j]+1;
	    				}
	    			}
	    		}
	    	}
	    }
	    cout<<f[m][m];
	    return 0;	
}
