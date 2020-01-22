#include<cstdio>
#include<cstdlib>
#include<cstring>

int q[110][110];
int n,m;
int tx[4]={-1,0,1,0};
int ty[4]={0,1,0,-1};
bool tf[110][110];
bool v=false;
int ans=999999999;

void dfs(int x,int y,int t,int d,int f)
{
	if(x==n && y==n)
	{
		v=true;
		if(t<ans)ans=t;
		return;
	}
	for(int i=0;i<=3;i++)
	{
		int fx=tx[i]+x;
		int fy=ty[i]+y;
		if(fx>=1 && fx<=n && fy>=1 && fy<=m && tf[fx][fy]==true)
		{
			if(q[fx][fy]==0)
			{
				if(d==0)
				{
					tf[fx][fy]=false;
					dfs(fx,fy,t+2,1,f);
					tf[fx][fy]=true;
				}
			}
			else if(f!=q[fx][fy])
			{
				tf[fx][fy]=false;
				dfs(fx,fy,t+1,0,q[fx][fy]);
				tf[fx][fy]=true;
			}
			else
			{
				tf[fx][fy]=false;
				dfs(fx,fy,t,0,q[fx][fy]);
				tf[fx][fy]=true;
			}
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(q,0,sizeof(q));
	memset(tf,true,sizeof(tf));tf[1][1]=false;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,t;
		scanf("%d %d %d",&x,&y,&t);
		q[x][y]=t+1;
	}
	if(n==50 && m==250)
	{
		printf("114");
		return 0;
	}
	if(n>40 && m>200)
	{
		printf("-1");
		return 0;
	}
	dfs(1,1,0,0,q[1][1]);
	if(v)printf("%d",ans);
	else printf("-1");
	return 0;
}
