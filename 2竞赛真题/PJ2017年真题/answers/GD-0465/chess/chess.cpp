#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int m,n,i,j,xw,yw,c,y,x,a[101][101],ans;
int main ()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    cin>>m>>n;
    for (i=1;i<=m;i++)
    for (j=1;j<=m;j++)
    {
    	a[i][j]=-1;
    }
    for (i=1;i<=n;i++)
    {
    	cin>>xw>>yw>>c;
    	a[xw][yw]=c;
    }
    y=x=1;
    while (x!=m||y!=m)
    {
    	if (a[x+1][y]==-1&&a[x][y+1]==-1&&a[x+1][y+1]==-1)
    	{
    		cout<<-1<<endl;
    		return 0;
    	}
    	if (a[x+1][y]==a[x][y]) x++;
    	else
    	{
    	    if (a[x][y+1]==a[x][y]) y++;
    	    else
    	    {
    	    	if (a[x][y+1]!=-1) {ans++;y++;}
    	    	else
    	    	{
     				if (a[x+1][y]!=-1) {ans++;x++;}
     				else
     				{
    				    if ((a[x+1][y]==-1&&a[x][y+1]==-1)&&a[x+1][y+1]==a[x][y]) {ans=ans+2;x++;y++;}
    				    else
    				    {
    				    	if ((a[x+1][y]==-1&&a[x][y+1]==-1)&&a[x+1][y+1]!=a[x][y]) {ans=ans+3;x++;y++;}
    				    }
    			    }
    		    }
    		} 
        }
    }
    cout<<ans<<endl;
	return 0;
}

