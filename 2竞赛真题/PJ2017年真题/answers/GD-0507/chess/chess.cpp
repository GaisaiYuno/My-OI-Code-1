#include<cstdio>
#include<cstring>	
int m,n,flag=0;
int a[110][110];
bool ma[110][110]; 
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ans=2147483647;
int minn(int x,int y) { return x<y?x:y; }
void dfs(int x,int y,int mon,int col,int can)
{
	//printf("%d %d %d\n",x,y,mon);
	if(x==m && y==m) { flag=1; ans=minn(ans,mon); return ; } 
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];	
		
		if(nx>=1 && nx<=m && ny>=1 && ny<=m && ma[nx][ny])
		{
			if(a[nx][ny]==-1)
			{
				if(can==1) { ma[nx][ny]=0; dfs(nx,ny,mon+2,col,0); ma[nx][ny]=1; }
			}
			else
			{
				ma[nx][ny]=0;
				if(a[nx][ny]==col) dfs(nx,ny,mon,col,1);
				else dfs(nx,ny,mon+1,a[nx][ny],1);		
				ma[nx][ny]=1;
			}
		}
	}
	return ;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);	
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) { a[i][j]=-1; ma[i][j]=1; }
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c);
		a[x][y]=c;
	}
	/*for(int i=1;i<=m;i++) 
	{
		for(int j=1;j<=m;j++) 
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	ma[1][1]=0;
	dfs(1,1,0,a[1][1],1);
	
	if(flag==1) printf("%d",ans);
	else printf("-1");
	return 0;
}
/*
3 6
1 1 1
2 1 1
2 2 1
2 3 0
3 2 1
3 3 1
*/
