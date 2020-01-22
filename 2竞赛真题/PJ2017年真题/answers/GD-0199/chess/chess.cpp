#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<deque>
using namespace std;
int m,n,ans=2000000;
int a[110][110],b[110][110];
int aa[110][110];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void sfind(int x,int y,int sum,bool k)
{
	if (x==m&&y==m)
	{
		ans=min(ans,sum);
		return;
	}
	else 
	{
		for (int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if (nx>=1&&nx<=m&&ny>=1&&ny<=m&&b[nx][ny]==0)
			{	
				if (a[nx][ny]!=-1)
				{
					if (a[x][y]==a[nx][ny])
					{
						b[nx][ny]=1;
						if (a[x][y]!=aa[x][y]) a[x][y]=-1;
						sfind(nx,ny,sum,true);
						b[nx][ny]=0;
					}
					else if (a[x][y]!=a[nx][ny])
					{
						b[nx][ny]=1;  
						if (a[x][y]!=aa[x][y]) a[x][y]=-1;
						sfind(nx,ny,sum++,true);
						b[nx][ny]=0;
					}
				}
				else 
				{
					if (k)
					{
						b[nx][ny]=1;  a[nx][ny]=a[x][y];
						sfind(nx,ny,sum+=2,false);  
						b[nx][ny]=0;  a[nx][ny]=-1;
						b[nx][ny]=1;  a[nx][ny]=1-a[x][y];
						sfind(nx,ny,sum+=2,false);
						b[nx][ny]=0;  a[nx][ny]=-1;
					}		
				}
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
	memset(a,-1,sizeof(a));
	memset(aa,-1,sizeof(aa));
	for (int i=1;i<=n;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		a[x][y]=c;
		aa[x][y]=c;
	}
	sfind(1,1,0,true);
	if (ans!=2000000) cout<<ans-3;
		else cout<<-1;
	return 0;
}
