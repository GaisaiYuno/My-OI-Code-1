#include<iostream>
#include<fstream>
using namespace std;
int m,n,x,y,c,s;
int a[100+10][100+10];
int b[100+10][100+10];
void f(int t1,int t2,int r,int g,int jsq)
{
    	if (b[t1][t2]>r)
	{
		b[t1][t2]=r;
	}
	else
	{
		return ;
	}
	if (t1>m||t2>m)
	{
		return;
	}
	if (t1==m&&t2==m)
	{
		if (r<s)
		{
			s=r;
		}
		return;
	}
	if (g==a[t1+1][t2])
	{
		
		f(t1+1,t2,r,g,0);
	}
	else
	{
		if (a[t1+1][t2]==0)
		{
			if (jsq==0)
			{
				f(t1+1,t2,r+2,1,1);
			   f(t1+1,t2,r+2,2,1);
			}
		}
		else
		{
			cout<<r;
			f(t1+1,t2,r+1,a[t1+1][t2],0);
		}
	}
		if (g==a[t1][t2+1])
	{
		f(t1,t2+1,r,g,0);
	}
	else
	{
		if (a[t1][t2+1]==0)
		{
			if (jsq==0)
			{
				f(t1,t2+1,r+2,1,1);
			   f(t1,t2+1,r+2,2,1);
			}
		}
		else
		{
			f(t1,t2+1,r+1,a[t1][t2+1],0);
		}
	}
	if (t2>1)
	{
		if (g==a[t1][t2-1])
	{
		f(t1,t2-1,r,g,0);
	}
	else
	{
		if (a[t1][t2-1]==0)
		{
			if (jsq==0)
			{
				f(t1,t2-1,r+2,1,1);
			   f(t1,t2-1,r+2,2,1);
			}
		}
		else
		{
			f(t1,t2-1,r+1,a[t1][t2-1],0);
		}
	}
	}
	if (t1>1)
	{
		if (g==a[t1-1][t2])
	{
		f(t1-1,t2,r,g,0);
	}
	else
	{
		if (a[t1-1][t2]==0)
		{
			if (jsq==0)
			{
				f(t1-1,t2,r+2,1,1);
			   f(t1-1,t2,r+2,2,1);
			}
		}
		else
		{
			f(t1-1,t2,r+1,a[t1-1][t2],0);
		}
	}
	}
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		if (c==0)
		{
			a[x][y]=1;
		}
		if (c==1)
		{
			a[x][y]=2;
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m;j++)
		{
			b[i][j]=100000000;
		}
	}
	s=100000000;
	f(1,1,0,a[1][1],0);
	if (s==100000000)
	{
		cout<<"-1";
	}
	else
	{
		cout<<s<<endl;
	}
	return 0;
}
