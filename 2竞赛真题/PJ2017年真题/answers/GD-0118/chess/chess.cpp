#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#define oo 2000000000
using namespace std;
queue <int> que;
struct EDGE{
	int t,next,len;
}e[10000005];
int cur,head[1005],dis[1005],vis[1005],x[1005],y[1005],c[1005],Start,End,m,n;
void Add(int a,int b,int c)
{
	cur++;
	e[cur].t=b;
	e[cur].next=head[a];
	e[cur].len=c;
	head[a]=cur;
}
void SPFA()
{
	que.push(Start);
	for (int i=1;i<=m;i++)
		dis[i]=oo;
	dis[Start]=0;
	while (!que.empty())
	{
		int now=que.front();
		vis[now]=false;
		int h=head[now];
		while (h!=-1)
		{
			int t=e[h].t;
			if (dis[now]+e[h].len<dis[t])
			{
				dis[t]=dis[now]+e[h].len;
				if (!vis[t])
				{
					que.push(t);
					vis[t]=true;
				}
			}
			h=e[h].next;
		}
		que.pop();
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
		c[i]++;
		if (x[i]==1&&y[i]==1) Start=i;
		if (x[i]==n&&y[i]==n) End=i;
	}
	if (End==0)
	{
		m++;
		End=m;
		x[m]=n;
		y[m]=n;
	}
	memset(head,-1,sizeof(head));
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			if (i!=j)
			{
				if (abs(x[i]-x[j])+abs(y[i]-y[j])==1)
					if (c[i]==c[j])
						Add(i,j,0);
					else
						Add(i,j,1);
				if (abs(x[i]-x[j])+abs(y[i]-y[j])==2)
					if (c[i]==c[j])
						Add(i,j,2);
					else
						Add(i,j,3);
			}
	SPFA();
	if (dis[End]!=oo) printf("%d",dis[End]);else printf("-1");
	return 0;
}
