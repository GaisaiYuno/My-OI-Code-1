#include<iostream>
#include<cstdio>
using namespace std;
long m,n,b,c,k,i,j,p,a[105][105],d[105][105],f[105][105];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(j=1;j<=m;++j)
		f[j][0]=99999999,f[0][j]=99999999;
	for(i=1;i<=n;++i)
	{
		cin>>b>>c>>k;
		a[b][c]=k+1;
		d[b][c]=k+1;
	}
	if(m==n&&n==1) {cout<<0;return 0;}
	f[1][1]=0;
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=m;j++)
		{
			if(i==1&&j==1) continue;
			if((f[i-1][j]>f[i][j-1]&&f[i][j-1]!=-1)||(f[i-1][j]==-1&&f[i][j-1]!=-1))
			{
				p=1;
				if(a[i][j]!=a[i][j-1]&&a[i][j]!=0)
				{
					f[i][j]=f[i][j-1]+1; 
				}
				else if(a[i][j]!=a[i][j-1]&&a[i][j]==0)
				 {
				 	f[i][j]=f[i][j-1]+2;
				 	d[i][j]=a[i][j-1];
				 }
				else if(a[i][j]!=a[i][j-1]&&a[i][j-1]==0)
				{
					f[i][j]=f[i][j-1];
					if(d[i][j]!=d[i][j-1]) f[i][j]+=1;
				}
				else if(a[i][j]==a[i][j-1]&&a[i][j]!=0)
				  f[i][j]=f[i][j-1];
				else if(a[i][j]==a[i][j-1]&&a[i][j]==0)
				  f[i][j]=-1;
			}
			else if((f[i-1][j]<f[i][j-1]&&f[i-1][j]!=-1)||(f[i][j-1]==-1&&f[i-1][j]!=-1))
			{
				p=1;
				if(a[i][j]!=a[i-1][j]&&a[i][j]!=0)
				{
					f[i][j]=f[i-1][j]+1;
				}
				else if(a[i][j]!=a[i-1][j]&&a[i][j]==0)
				{
					f[i][j]=f[i-1][j]+2;
					d[i][j]=a[i-1][j];
				}
				else if(a[i][j]!=a[i-1][j]&&a[i-1][j]==0)
				{
					f[i][j]=f[i-1][j];
					if(d[i][j]!=d[i-1][j]) f[i][j]+=1;
				}
				else if(a[i][j]==a[i-1][j]&&a[i][j]!=0)
				 f[i][j]=f[i-1][j];
				else if(a[i][j]==a[i-1][j]&&a[i][j]==0)
				  f[i][j]=-1;
			}
			else if(f[i-1][j]==f[i][j-1])
			{
			    if(a[i][j]!=a[i-1][j]&&a[i-1][j]==0)
				{
					f[i][j]=f[i-1][j];
					if(d[i][j]!=d[i-1][j]) f[i][j]+=1;
				}
			}
		}
	}
	if(a[m-1][m]==0&&(a[m-2][m]==0&&a[m-1][m-1]==0))	k=1;
	  if(k==1&&a[m][m-1]==0&&(a[m-1][m-1]==0&&a[m][m-2]==0)) {cout<<-1;return 0;}
	else cout<<f[m][m];
	return 0;
}
