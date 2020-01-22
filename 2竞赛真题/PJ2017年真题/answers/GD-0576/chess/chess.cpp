#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int big=500000;
int m,n,a[110][110],b[110][110],ans=-1;
int h[110][110];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

void f(int x,int y,int cl,int sum)
{
	//if(x<1||x>m||y<1||y>m) return;
	if(x==1&&y==1)
	{
		if(ans==-1) ans=sum;
		else ans=min(ans,sum);
		h[x][y]=1;
		return;
	}
	//if(b[x][y]!=big) return b[x][y];
	h[x][y]=0;
	int k,nx,ny,tot;
	for(int i=0; i<4; i++)
	{
		k=sum;
		nx=x+dx[i];
		ny=y+dy[i];
		if( (a[x][y]!=0||a[nx][ny]!=0)&&nx>0&&nx<=m&&ny>0&&ny<=m&&h[nx][ny]==1 )
		{
			if(a[x][y]!=0&&a[nx][ny]!=0)
			{
				if(a[x][y]!=a[nx][ny]) k++;
				f( nx,ny,a[nx][ny],k);
			}
			else if(a[x][y]==0)
			{
				if(cl!=a[nx][ny]) k++;
				f( nx,ny,a[nx][ny],k);
			}
			else if(a[nx][ny]==0)
			{
				k=k+2;
				f(nx,ny,cl,k);
			}
		}
	}
	h[x][y]=1;
	//cout<<x<<' '<<y<<endl;
	return;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1; i<=m; i++)
	    for(int j=1; j<=m; j++)
	    {
	    	a[i][j]=0;
	    	//b[i][j]=1;
	    	h[i][j]=1;
	    }
	int x,y,c;
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d %d",&x,&y,&c);
		a[x][y]=c+1;
	}
	//cout<<f(m,m,a[m][m]);
	f(m,m,a[m][m],0);
	/*for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=m; j++) cout<<a[i][j]<<' ';
	  	cout<<endl;
	}*/
	/*cout<<endl<<endl;
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=m; j++) cout<<b[i][j]<<' ';
	  	cout<<endl;
	}*/
	//cout<<endl<<endl;
	/*for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=m; j++) cout<<h[i][j]<<' ';
	  	cout<<endl;
	}*/
	cout<<ans;
	return 0;
}
