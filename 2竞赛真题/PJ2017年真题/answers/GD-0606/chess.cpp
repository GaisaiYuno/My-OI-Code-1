#include <iostream>
#include <cstdio>
using namespace std;
int a[1001][1001],c[1001][1001],s[1001][1001],p1,p2,p3,p4;
int chess(int x1,int y1,int x2,int y2,int cr1,int cr2,int sum)
{
	if (cr1==cr2) return sum;
	if (cr1+cr2==3) return sum+1;
	if (cr1+cr2!=3)
		if (a[x1][y1]!=1)
			{
				a[x2][y2]=1;
				c[x2][y2]=cr1;
				return sum+2;
			} else 
				return -1;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,x,y,b,k1,k2,k3,k4,t1,t2;
	cin>>m>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y>>b;
		if (b==1) c[x][y]=2;
		if (b==0) c[x][y]=1;
	}
	s[1][1]=0;
	for (int i=2;i<=n;i++)
	{
		if (s[1][i-1]==-1) s[1][i]=-1;
			else s[1][i]=chess(1,i-1,1,i,c[1][i-1],c[1][i],s[1][i-1]);
	}
	for (int i=2;i<=n;i++)
	{
		if (s[i-1][1]==-1) s[i][1]=-1;
			else s[i][1]=chess(i-1,1,i,1,c[i-1][1],c[i][1],s[i-1][1]);
	}
	for (int i=2;i<=n;i++)
		for (int j=2;j<=n;j++)
		{
			k1=s[i-1][j];
			k2=s[i][j-1];
			k3=c[i-1][j];
			k4=c[i][j-1];
			if ((k1==-1)&&(k2==-1)) s[i][j]=-1;
			if ((k1==-1)&&(k2!=-1)) s[i][j]=chess(i,j-1,i,j,k4,c[i][j],s[i][j-1]);
			if ((k1!=-1)&&(k2==-1)) s[i][j]=chess(i-1,j,i,j,k3,c[i][j],s[i-1][j]);
			if ((k1!=-1)&&(k2!=-1))
				{
					t1=chess(i-1,j,i,j,k3,c[i][j],s[i-1][j]);
					t2=chess(i,j-1,i,j,k4,c[i][j],s[i][j-1]);
					if ((t1==-1)&&(t2==-1)) s[i][j]=-1;
					if ((t1==-1)&&(t2!=-1)) s[i][j]=t2;
					if ((t1!=-1)&&(t2==-1)) s[i][j]=t1;
					if ((t1!=-1)&&(t2!=-1)) s[i][j]=min(t1,t2);
				}
		}
	cout<<s[m][m];
	return 0;
}
