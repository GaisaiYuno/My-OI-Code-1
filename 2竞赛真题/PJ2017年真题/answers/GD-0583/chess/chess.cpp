#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[101][101],f[101][101],b[101][101],a1[101][101];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n;++i)
	{
		int x,y,c;
		cin>>x>>y>>c;
		a[x][y]=c+1;
	}
	f[1][1]=0;
	for(int i=2;i<=m;++i)
	{
		int z=f[1][i-1],y=0;
		if(z==-1) y=1;
		if(a[1][i])
		{
			if(z!=-1&&a[1][i-1]!=a[1][i])
			{
				if(a[1][i-1]!=0) z++;
				else if(a1[1][i-1]!=a[1][i]&&a1[1][i]!=3) z++;
			}
		}
		if(!a[1][i])
		{
			if(z!=-1&&a[1][i-1]!=0)
			{
				a1[1][i]=a[1][i-1];
				z+=2;
			}
			else y=1;
		}
		if(!y) f[1][i]=z;
		else f[1][i]=-1;
	}
	for(int i=2;i<=m;++i)
	{
		int z=f[i-1][1],y=0;
		if(z==-1) y=1;
		if(a[i][1])
		{
			if(z!=-1&&a[i-1][1]!=a[i][1])
			{
				if(a[i-1][1]!=0) z++;
				else if(a1[i-1][1]!=a[1][i]&&a1[i-1][1]!=3) z++;
			}
		}
		if(!a[i][1])
		{
			if(z!=-1&&a[i-1][1]!=0)
			{
				 z+=2;
				 a1[i][1]=a[i-1][1];
			}
			else y=1;
		}
		if(!y) f[i][1]=z;
		else f[i][1]=-1;
	}
	for(int i=2;i<=m;++i)
	{
		for(int j=2;j<=m;++j)
		{
			int z=f[i][j-1],s=f[i-1][j],x=0,y=0;
			if(z==-1) y=1; if(s==-1) x=1;
			if(a[i][j]!=0)
			{				
				if(z!=-1&&a[i][j-1]!=a[i][j]) 
				{
					if(a[i][j-1]!=0) z+=1;
					else if(a1[i][j-1]!=a[i][j]&&a1[i][j-1]!=3) z++;
				}
				if(s!=-1&&a[i-1][j]!=a[i][j])
				{
					if(a[i-1][j]!=0) s+=1;
					else if(a1[i-1][j]!=a[i][j]&&a1[i-1][j]!=3) s++;
			    }
			}
			else
			{
				if(z!=-1&&a[i][j-1]==a[i][j]) y=1;
				else if(z!=-1&&a[i][j-1]!=a[i][j]) z+=2;
				if(s!=-1&&a[i-1][j]==a[i][j]) x=1;
				else if(s!=-1&&a[i-1][j]!=a[i][j]) s+=2;
			}
			if(y==0&&x==1) 
			{
				f[i][j]=z;a1[i][j]=a[i][j-1];
			}
			else if(x==0&&y==1)
			{
				f[i][j]=s;a1[i][j]=a[i-1][j];
			}
			else if(x==1&&y==1) f[i][j]=-1;
			else if(z<s)
			{
				f[i][j]=z;a1[i][j]=a[i][j-1];
			}
			else if(s<z)
			{
				f[i][j]=s;a1[i][j]=a[i-1][j];
			}
			else
			{
				f[i][j]=s;a1[i][j]=3;
			}
		}
	}
	cout<<f[m][m]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
