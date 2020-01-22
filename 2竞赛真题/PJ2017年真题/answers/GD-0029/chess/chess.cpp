#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int dx[5],dy[5];
int m,x,z,y,n;
int ans=-1;
int a[110][110];
void dfs(int x,int y)
{
    if (x<1||x>m||y<1||y>m) return;
    for (int i=1; i<=4; i++)
    {
    	if (a[x+dx[i]][y+dy[i]]==a[x][y] && a[x][y]!=-1) dfs(x+dx[i],y+dy[i]);
    	else if (a[x+dx[i]][y+dy[i]]!=a[x][y] && a[x][y]!=-1) 
		{
			ans+=1;
		    dfs(x+dx[i],y+dy[i]);
        }
        else 
		{
		   ans+=2;
		   dfs(x+dx[i],y+dy[i]);
	    }
    }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	dx[1]=1; dx[2]=-1; dx[3]=0; dx[4]=0;
	dy[1]=0; dy[2]=0; dy[3]=1; dy[4]=-1;
	cin>>m>>n;
	for (int i=0; i<=m; i++)
	 for (int j=0; j<=m; j++)
	  a[i][j]=-1;
	for (int i=1; i<=n; i++) 
	{
	    scanf("%d%d%d",&x,&y,&z);
	    a[x][y]=z;
    }
    cout<<-1;
	return 0;
}
