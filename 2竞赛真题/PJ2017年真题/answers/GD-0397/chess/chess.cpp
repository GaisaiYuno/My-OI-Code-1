#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,m,i,j,x,y,c,a[105][105],k,p;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c+1;
	}
    i=1;j=1;p=0;
	while(i!=n&&j!=n)
	{
		if(a[i][j+1]==a[i][j]&&a[i][j+1]!=0)
		{
			j++;
		}
		if(a[i+1][j]==a[i][j]&&a[i+1][j]!=0)
		{
			i++;
		}else
		if(a[i][j+1]!=a[i][j]&&a[i][j+1]!=0)
		{
			j++;
			k++;
		}else
		if(a[i+1][j]!=a[i][j]&&a[i+1][j]!=0)
		{
			i++;
			k++;
		}
		if(a[i+1][j+1]==a[i][j]&&a[i+1][j+1]!=0)
		{
			i++;
			j++;
			k+=2;
		}else
		if(a[i+1][j+1]!=a[i][j]&&a[i+1][j+1]!=0)
		{
			i++;
			j++;
			k+=3;
		}else if(a[i][j+1]==0&&a[i+1][j]==0&&a[i+1][j+1]==0)
		    {
	    		p=1;
	    		break;
	    	}
	}
	if(p==1) cout<<-1; else cout<<k;
	return 0;
}

