#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int m,n,a[110][1010],x,y,c,f[110][1010],oo=99999,mina,b[110][1010],sum[110][1010];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			a[i][j]=0;
			b[i][j]=0;
			f[i][j]=0;	
		} 	
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c+1;
		b[x][y]=c+1;
	}
	
	f[1][1]=0;
	for(int i=1;i<=m;i++) 
	{
		b[i][0]=0;
		f[i][0]=oo;
		sum[i][0]=1;	
	}
	for(int j=1;j<=m;j++) 
	{
		b[0][j]=0;
		f[0][j]=oo;
		sum[0][j]=1;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1) continue;
			if(b[i][j]!=0)
			{
				if(b[i][j]==b[i-1][j]&&b[i][j]==b[i][j-1]){
				f[i][j]=min(f[i-1][j],f[i][j-1]);
				b[i-1][j]=a[i-1][j];
				b[i][j-1]=a[i][j-1];
				sum[i-1][j]=0;
				sum[i][j-1]=0;
				continue;
				}
				if(b[i][j]!=b[i-1][j]&&b[i][j]==b[i][j-1]){
				f[i][j]=min(f[i-1][j]+1,f[i][j-1]);
				b[i-1][j]=a[i-1][j];
				b[i][j-1]=a[i][j-1];
				sum[i][j-1]=0;
				continue;
				} 
				if(b[i][j]==b[i-1][j]&&b[i][j]!=b[i][j-1]){
				f[i][j]=min(f[i-1][j],f[i][j-1]+1);
				b[i-1][j]=a[i-1][j];
				b[i][j-1]=a[i][j-1];
				sum[i-1][j]=0;
				continue;
				} 
			}
			
			if(b[i][j]==0)
			{
				if(sum[i-1][j]==0||b[i-1][j]!=0) 
				{
					f[i][j]=f[i-1][j]+2;
					b[i][j]=b[i-1][j];
				}
				if(sum[i][j-1]==0||b[i][j-1]!=0)
				{
					if(f[i][j]>f[i][j-1]+2)
					{
						f[i][j]=f[i][j-1]+2;
						b[i][j]=b[i][j-1];
					}
					continue;
				}
				f[i][j]=oo;
			}
				
		}
	
	if(f[m][m]>=99999) cout<<-1<<endl;
	cout<<f[m][m]<<endl;
	return 0;
}
