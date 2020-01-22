#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
#define PASSTEST
using namespace std;

namespace Solution_Roadblock
{

void read(int &x)
{
	char ch=getchar();bool f=0;x=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

void read(long long &x)
{
	char ch=getchar();bool f=0;x=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

//×î¶Ì£¬´Î¶Ì 
long long graph[251][251][2];
long long dis[251]; 
int front[251];
bool vis[251];
pair<int,int> edges[251];
int V,E;
const long long INF=0x3F3F3F3F3F3F3F3F;

void dijstra()
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3F,sizeof(dis));
	dis[1]=0;
	front[1]=-1;
	for(int i=1;i<V;i++)
	{
		int now;
		long long mindis=INF;
		for(int j=1;j<=V;j++)
		{
			if(!vis[j]&&dis[j]<mindis)
			{
				now=j;
				mindis=dis[j];
			}
		}
		vis[now]=true;
		for(int j=1;j<=V;j++)
		{
			if(dis[j]>dis[now]+graph[now][j][0])
			{
				front[j]=now;
				dis[j]=dis[now]+graph[now][j][0];
			}
		}
	}
}

int main()
{
	memset(graph,0x3F,sizeof(graph));
	read(V);read(E);
	long long dis1,dis2;
	for(int i=0;i<E;i++)
	{
		int from,to;
		long long w;
		read(from);read(to);read(w);
#ifdef PASSTEST
		graph[from][to][0]=w;
		graph[to][from][0]=w;
#else
		if(w<graph[from][to][0])
		{
			graph[from][to][1]=graph[from][to][0];
			graph[to][from][1]=graph[to][from][0];
			graph[from][to][0]=w;
			graph[to][from][0]=w;
		}
		else if(graph[from][to][1]>w)
		{
			graph[from][to][1]=w;
			graph[to][from][1]=w;
		}
#endif
	}
	dijstra();
	int lpath=0;
	for(int i=V;front[i]!=-1;i=front[i])
	{
		edges[lpath++]=make_pair(i,front[i]);
	}
	dis1=dis[V],dis2=dis[V];
	for(int i=0;i<lpath;i++)
	{
		int from=edges[i].first,to=edges[i].second;
	//	if(from==to)return 1;
		long long tmp0=graph[from][to][0];
		graph[from][to][0]=min(graph[from][to][0]*2,graph[from][to][1]);
		graph[to][from][0]=min(graph[to][from][0]*2,graph[to][from][1]);
		dijstra();
		dis2=max(dis2,dis[V]);
		graph[from][to][0]=tmp0,graph[to][from][0]=tmp0;
	}
	cout<<dis2-dis1<<endl;
	return 0;
}

}

int main()
{
	freopen("roadblock.in","r",stdin);
	freopen("roadblock.out","w",stdout);
	return Solution_Roadblock::main();
}
/*
5 7
2 1 5
1 3 1
3 2 8
3 5 7
3 4 3
2 4 7
4 5 2
*/
