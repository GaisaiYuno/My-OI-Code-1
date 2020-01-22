#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,t;
struct mat
{
	int r,c;
	int a[35][35];
	mat()
	{
		r=c=0;
		memset(a,0,sizeof(a));
	}
};
mat operator * (mat a,mat b)
{
	mat c;
	c.r=a.r,c.c=b.c;
	for(int i=1; i<=a.r; i++)
	{
		for(int u=1; u<=b.c; u++)
		{
			for(int j=1; j<=a.c; j++)
			{
				c.a[i][u]+=a.a[i][j]*b.a[j][u];
				c.a[i][u]%=2017;
			}
		}
	}
	return c;
}
//the node with id n+1 is Xplode
mat base;
mat waiting;
mat ksm(mat a,int b)
{
	mat ans=a;
	b--;
	while(b)
	{
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main()
{
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	cin>>n>>m;
	base.r=base.c=n+1;
	for(int i=0; i<m; i++)
	{
		int x,y;
		cin>>x>>y;
		base.a[x][y]=base.a[y][x]=1;
	}
	for(int i=1; i<=n+1; i++)
	{
		base.a[i][i]=1;
		base.a[i][n+1]=1;
	}
	waiting.r=1;
	waiting.c=n+1;
	waiting.a[1][1]=1;
	cin>>t;
	mat huaji=waiting*ksm(base,t);
	int ans;
	for(int i=1; i<=n+1; i++)
	{
		ans+=huaji.a[1][i];
	}
	cout<<ans%2017;
}
