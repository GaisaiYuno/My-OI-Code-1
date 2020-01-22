#include<cstdio>
#include<cstdlib>
#include<cstring>

struct node{int x,y,c,f;};
node q[1000010];
int fx[4]={0,1};
int fy[4]={1,0};
bool v[110][110];
int a[110][110];
int n,m,ans=999999999;
int st,ed;
bool bj=false;

void bfs()
{
	st=1;ed=2;
	q[1].x=1;q[1].y=1;q[1].c=0;q[1].f=0;v[1][1]=false;
	while(st!=ed)
	{
		for(int i=0;i<2;i++)
		{
			int xx=q[st].x+fx[i];
			int yy=q[st].y+fy[i];
			if(xx<1 || xx>m || yy<1 || yy>m || !v[xx][yy]) continue;
			if(a[q[st].x][q[st].y]==-1 && a[xx][yy]==-1) continue;
			q[ed].x=xx;q[ed].y=yy;q[ed].f=st;v[xx][yy]=false;
			if(a[q[st].x][q[st].y]==0)
			{
				if(a[xx][yy]==0) q[ed].c=q[st].c;
				if(a[xx][yy]==1) q[ed].c=q[st].c+1;
				if(a[xx][yy]==-1) q[ed].c=q[st].c+2;
			}
			if(a[q[st].x][q[st].y]==1)
			{
				if(a[xx][yy]==1) q[ed].c=q[st].c;
				if(a[xx][yy]==0) q[ed].c=q[st].c+1;
				if(a[xx][yy]==-1) q[ed].c=q[st].c+2;
			}
			if(a[q[st].x][q[st].y]==-1)
			{
				int z,f;
				f=q[st].f;
				z=a[q[f].x][q[f].y];
				if(z==a[xx][yy]) q[ed].c=q[st].c;
				else q[ed].c=q[st].c+1;
			}
			if(xx==m && yy==m)
			{
				bj=true;
				if(q[ed].c<ans) ans=q[ed].c;
			}
			ed++;
		}
		st++;
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&m,&n);
	memset(a,-1,sizeof(a));
	memset(v,true,sizeof(v));
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c);
		a[x][y]=c;
	}
	bfs();
	if(bj) printf("%d",ans);
	else printf("-1");
}
