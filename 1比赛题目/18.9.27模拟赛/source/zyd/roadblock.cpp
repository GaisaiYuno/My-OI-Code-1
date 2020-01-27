#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<queue>
#define re register
#define fast static
using namespace std;
typedef long long ll;
int read()
{
	re int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=200005;
struct Edge
{
	ll u,v,w,next;
} w[Size<<2];
struct Node
{
	ll id,dist;
	friend inline bool operator < (const Node x,const Node y)
	{
		if(x.dist!=y.dist)	return x.dist>y.dist;
		return x.id<y.id;
	}
};
fast int n,m,cnt,head[Size];
void AddEdge(int u,int v,ll wei)
{
	cnt++;
	w[cnt].u=u;
	w[cnt].v=v;
	w[cnt].w=wei;
	w[cnt].next=head[u];
	head[u]=cnt;
}
fast ll dist[Size];
void Dijkstra(int s,int pos)
{
	w[pos].w<<=1;
	w[pos+1].w<<=1;
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	priority_queue<Node> Q;
	Q.push((Node){s,0});
	while(!Q.empty())
	{
		int x=Q.top().id;	Q.pop();
		for(re int i=head[x]; i; i=w[i].next)
		{
			int nxt=w[i].v;
			if(dist[x]+w[i].w<dist[nxt])
			{
				dist[nxt]=dist[x]+w[i].w;
				Node tmp=(Node){nxt,dist[nxt]};
				Q.push(tmp);
			}
		}
	}
	w[pos].w>>=1;
	w[pos+1].w>>=1;
}
void init()
{
	n=read();
	m=read();
	for(int i=1; i<=m; i++)
	{
		int a=read();
		int b=read();
		int c=read();
		AddEdge(a,b,c);
		AddEdge(b,a,c);
	}
}
int main()
{
	freopen("roadblock.in","r",stdin);
	freopen("roadblock.out","w",stdout);
	init();
	Dijkstra(1,cnt+1);
	ll bef=dist[n],ans=0;
	for(int i=1; i<=cnt; i+=2)
	{
		Dijkstra(1,i);
		if(dist[n]-bef>ans)
		{
			ans=dist[n]-bef;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*

*/
