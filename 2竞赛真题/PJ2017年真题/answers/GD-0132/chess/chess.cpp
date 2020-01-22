#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
using namespace std;
int sum,m,n,i,j,aa,bb,c,a[205][205],x,y,a1,a2,a3,a4,t;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (i=1; i<=n; i++)
	{
		cin>>aa>>bb>>c;
		a[aa][bb]=c+1;
	}
	x=1;y=1;
	while (x!=m||y!=m)
	{
		if (x!=1&&y!=1)
		{
			if (a2==2&&a1==2)
			{
				a[x][y]=a[x-1][y];
				y++;
				a1=0;
				if (x==m&&y==m)
				{
					if (a[x][y-1]!=a[x][y]) sum++;
				}
				if (a[x][y]==0)
				 if (a[x][y+1]==0&&a[x+1][y]==0) {cout<<-1;return 0;}
				continue;
			}
		}
		if (a[x][y]==0)
		 if (a[x][y+1]==0&&a[x+1][y]==0) {cout<<-1;return 0;}
		if (a[x][y+1]==0) a1=2; else
		if (a[x][y]==a[x][y+1]) a1=0; else
		if (a[x][y]!=a[x][y+1]) a1=1;
		if (a[x+1][y]==0) a2=2; else
		if (a[x][y]==a[x+1][y]) a2=0; else
		if (a[x][y]!=a[x+1][y]) a2=1;
		if (a1<a2&&y<m) y++; else x++;
		sum+=min(a1,a2);
	}
	cout<<sum;
	return 0;
}
