#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
struct node
{
	int x,y,s;bool k;
};
bool cmp(node x,node y)
{
	return x.s<y.s;
}
int map[1100][1100],f[1100][1100],n,m;
void dfs(int x,int y,bool k)
{
	node a[4];
	for(int i=0;i<=3;i++)
	{
		int xx=x+dx[i],yy=y+dy[i],ss;bool kk;
		if(xx<1||xx>m||yy<1||yy>m)ss=-1;
		else if((k==false)&&map[xx][yy]==0)ss=-1;
		else
		{
			if(map[xx][yy]==0)kk=false,ss=2;
			else
			{
				kk=true;
				if(map[xx][yy]==map[x][y])ss=0;
				else ss=1;
			}
		}
		a[i].x=xx;a[i].y=yy;a[i].s=ss;a[i].k=kk;
	}
	sort(a,a+4,cmp);
	for(int i=0;i<=3;i++)
	{
		if(a[i].s==-1)continue;
		if(a[i].k==false)
		{
			{
				int ss=a[i].s+f[x][y];
				if(ss<f[a[i].x][a[i].y])
				{
					map[a[i].x][a[i].y]=map[x][y];
					f[a[i].x][a[i].y]=ss;
					dfs(a[i].x,a[i].y,a[i].k);
					map[a[i].x][a[i].y]=0;
				}
			}
			{
				int ss=a[i].s+f[x][y]+1;
				if(ss<f[a[i].x][a[i].y])
				{
					map[a[i].x][a[i].y]=map[x][y]*(-1);
					f[a[i].x][a[i].y]=ss;
					dfs(a[i].x,a[i].y,a[i].k);
					map[a[i].x][a[i].y]=0;
				}
			}
		}
		else
		{
			int ss=a[i].s+f[x][y];
			if(ss<f[a[i].x][a[i].y])
			{
				f[a[i].x][a[i].y]=ss;
				int t;t=map[x][y];
				if(k==false)
				{
					map[x][y]=0;
				}
				dfs(a[i].x,a[i].y,a[i].k);
				if(k==false)map[x][y]=t;
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(map,0,sizeof(map));
	for(int i=1;i<=n;i++)
	{
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		if(c==1)map[x][y]=1;
		else map[x][y]=-1;
	}
	memset(f,63,sizeof(f));f[1][1]=0;
	dfs(1,1,true);
	if(f[m][m]==1061109567)printf("-1\n");
	else printf("%d\n",f[m][m]);
	return 0;
}
