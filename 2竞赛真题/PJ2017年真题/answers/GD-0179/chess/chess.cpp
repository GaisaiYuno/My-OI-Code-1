#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int a[1000][1000];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,m,x,y,c,i,j,b1=1,b2=1,s=0;
	bool flag=true;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		if(c==0)
		{
			a[x][y]=1;
		}
		if(c==1)
		{
			a[x][y]=2;
		}
	}
	while(b1!=m&&b2!=m)
	{
		if(a[b1][b2+1]!=0||a[b1+1][b2]!=0)
		{
			if(a[b1][b2+1]!=0&&a[b1+1][b2]!=0)
			{
				if(a[b1][b2+1]==a[b1][b2])
				{
					b2=b2+1;
				}
				if(a[b1+1][b2]==a[b1][b2])
				{
					b1=b1+1;
				}
			}
			if(a[b1][b2+1]==0)
			{
				if(a[b1+1][b2]!=a[b1][b2])
				{
					s=s+1;
					b1=b1+1;
					flag=false;
					if(a[b1][b2]==1)
					{
						a[b1][b2]=2;
					}
					else a[b1][b2]=1;
				}
				else b1=b1+1;
			}
			if(a[b1+1][b2]==0&&flag==true)
			{
				if(a[b1][b2+1]!=a[b1][b2])
				{
					s=s+1;
					b2=b2+1;
					if(a[b1][b2]==1)
					{
						a[b1][b2]=2;
					}
					else a[b1][b2]=1;
				}
				else b2++;
			}
		}
		if(a[b1][b2+1]==0&&a[b1+1][b2]==0)
		{
			if(a[b1][b2+2]!=0)
			{
				s=s+2;
				b2++;
			}
			if(a[b1+2][b2]!=0)
			{
				s=s+2;
				b1++;
			}      
			if(a[b1+1][b2+1]!=0)
			{
				s=s+2;
				b1++;
			}
			if(a[b1+1][b2+1]==0&&a[b1][b2+2]==0&&a[b1+2][b2]==0)
			{
				cout<<"-1";
				return 0;
			}
		}
	}
	cout<<s;
	return 0;
}
