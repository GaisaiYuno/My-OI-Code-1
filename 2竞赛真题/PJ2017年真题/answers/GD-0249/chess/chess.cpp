#include<iostream>
#include<cstdio>
using namespace std;
const int xx[4]={1,-1,0,0},yy[4]={0,0,1,-1};
int n,m,x1,y1,p1,a[105][105],s[105][105],f[105][105],n1,x[100001],y[100001],cx[100001],cy[100001],cp[100001],p[100001],tt;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x1>>y1>>p1;
		a[x1][y1]=p1+1;
	}
	s[1][1]=1;
	n1++;
	x[n1]=1;y[n1]=1;p[n1]=0;
	while(n1>0)
	{
		int n2=n1;
		for(int i=1;i<=n1;i++)
		{
			cx[i]=x[i];
			cy[i]=y[i];
			cp[i]=p[i];
		}
		n1=0;
		for(int i=1;i<=n2;i++)
			for(int j=0;j<4;j++)
			if(cx[i]+xx[j]<=m&&cx[i]+xx[j]>0&&cy[i]+yy[j]<=m&&cy[i]+yy[j]>0&&(cp[i]==0||a[cx[i]+xx[j]][cy[i]+yy[j]]!=0))
			{
				if(a[cx[i]+xx[j]][cy[i]+yy[j]]==0)
				{
					if(s[cx[i]+xx[j]][cy[i]+yy[j]]==0||f[cx[i]+xx[j]][cy[i]+yy[j]]>f[cx[i]][cy[i]]+2)
					{
						f[cx[i]+xx[j]][cy[i]+yy[j]]=f[cx[i]][cy[i]]+2;
						s[cx[i]+xx[j]][cy[i]+yy[j]]=1;
						n1++;
						x[n1]=cx[i]+xx[j];
						y[n1]=cy[i]+yy[j];
						p[n1]=a[cx[i]][cy[i]];
					}
				}
				else
				{
					tt=1;
					if(a[cx[i]+xx[j]][cy[i]+yy[j]]==a[cx[i]][cy[i]]||(cp[i]==a[cx[i]+xx[j]][cy[i]+yy[j]]&&cp[i]!=0)) tt=0;
					if(s[cx[i]+xx[j]][cy[i]+yy[j]]==0||f[cx[i]+xx[j]][cy[i]+yy[j]]>f[cx[i]][cy[i]]+tt)
					{
						f[cx[i]+xx[j]][cy[i]+yy[j]]=f[cx[i]][cy[i]]+tt;
						s[cx[i]+xx[j]][cy[i]+yy[j]]=1;
						n1++;
						x[n1]=cx[i]+xx[j];
						y[n1]=cy[i]+yy[j];
						p[n1]=0;
					}
				}
			}
	}
	if(s[m][m]==1)cout<<f[m][m];else cout<<-1;
	return 0;
}
