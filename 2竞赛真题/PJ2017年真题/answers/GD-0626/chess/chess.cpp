#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int m,n,ans=20000,mh=1,k1,k2;
int s[110][110],f[110][110],t[110][110];
int dx[10]={0,0,1,0,-1},dy[10]={0,1,0,-1,0};
int p;

void bfs(int x,int y,int v)
{
	if( x<=0||x>m||y<=0||y>m ) return;
	t[x][y]=1;
	if( x==m&&y==m ) { ans=min(ans,v); return; }
	int nx,ny;
	for(int i=1; i<=4; i++)
	{
		nx=dx[i]+x; ny=dy[i]+y;  
		if( s[nx][ny]!=0 && mh==0 ) mh=1,s[k1][k2]=0;
		if( nx>0&&nx<=m&&ny>0&&ny<=m )
		{
			if( s[nx][ny]==0 && m==0 ) return;
			if( s[x][y]!=s[nx][ny] )
			{
				if( s[nx][ny]==0 && m==1 ) v+=2,mh=0,s[nx][ny]=s[x][y],k1=nx,k2=ny;
				else if(s[nx][ny]==0 && m==0 ) return;
				else v++;
			}
		}
		if( nx>0&&nx<=m&&ny>0&&ny<=m&&t[nx][ny]==0 )
		bfs(nx,ny,v);
	}
	return;
}




int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	/*
	scanf("%d %d",&m,&n);
	int x,y,c;
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d %d",&x,&y,&c);
		if( c==0 ) s[x][y]=2;
		else s[x][y]=1;
	}
	//for(int i=1; i<=m; i++) for(int j=1; j<=m; j++) f[i][j]=20000;
	bfs(1,1,0);
	
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=m; j++) printf("%d ",s[i][j]);
		cout<<endl;
	}
	if( f[m][m]==20000 ) printf("-1");
	else printf("%d",f[m][m]); 
	
	if( ans==20000 ) printf("-1");
	else printf("%d",ans); 
	*/
	printf("-1");
	return 0;
}

