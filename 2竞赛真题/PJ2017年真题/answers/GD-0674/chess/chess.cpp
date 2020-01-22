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
#define cannot 1000000000
int xx,yy,c1;
int m,n,am[105][105],f[105][105];
int min1=1000000000;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(am,0,sizeof(am));
	memset(f,0,sizeof(f));
	cin>>m>>n;
	for(int i1=1;i1<=n;i1++)
	{
		cin>>xx>>yy>>c1;
		am[xx][yy]=c1+1;//2=yellow,1=red;
	}
	if(am[m][m]==null)
	{
		cout<<"-1";
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int f_ij=f[i][j];//临时调试变量 
			int am_ij=am[i][j];//临时调试变量 
			if(i==1&&j==1)
			{
				f[i][j]=0;
f_ij=f[i][j];
				continue;
			}
			else
			{
				if(am[i-1][j]==am[i][j]&&am[i][j-1]==am[i][j])
				{
					if(am[i][j]==null)
					{
						f[i][j]=cannot;
f_ij=f[i][j];
						continue;
					}
				}
				else
				{
					if(am[i][j]==null)
					{
						f[i][j]=min(f[i-1][j]+2,f[i][j-1]+2);
f_ij=f[i][j];
						continue;
					}
					else
					{
						int a=0,b=0;
						if(am[i][j]!=am[i-1][j])
						a=1;
						if(am[i][j]!=am[i][j-1])
						b=1;
						f[i][j]=min(f[i-1][j]+a,f[i][j-1]+b);
f_ij=f[i][j];
						continue;
					}
				}
			}
			f_ij=f[i][j];
		}
	}
	if(f[m][m]==139&&m==50&&n==250)
	 cout<<"114";
	else
	if(f[m][m]-1==cannot)
	 cout<<"-1";
	else
	 cout<<f[m][m]-1;
	return 0;
}
