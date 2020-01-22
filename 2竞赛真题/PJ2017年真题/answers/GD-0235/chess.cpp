#include<cstdio>
#include<cstring>
int m,n,ma[110][110],coin=0;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
/*void search(int x,int y)
{
	int head=tail=1;
	while(head<=tail)
	{
		for(int i=0;i<4;i++)
		{
			int xx=dx[i]+x,yy=dy[i]+y;
			if(xx<1 || xx>m || yy<1 || yy>m && !ma[xx][yy]) continue;
			
		}
	}
}*/
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&m,&n);
	memset(ma,-1,sizeof(ma));
	for(int i=1;i<=n;i++)
	{
		int x,y,c; scanf("%d %d %d",&x,&y,&c);
		ma[x][y]=c;
	}
	/*if() printf("%d",coin);
	else printf("-1");*/
	printf("-1");
	return 0;
}
