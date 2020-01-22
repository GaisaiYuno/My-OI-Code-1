#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;

struct node
{
	int front,nex;
}graph[300004],graph2[300004];
int tail=100000;
stack <int> s;

int end[100001];
int deg[100001];
int start;
int nend=0;

//1——奇数，2——偶数，3——均可
char vis1[100001];
char vis2[100001];
int vis[100001];
bool vis3[100001];

inline void read(int &x)
{
	x=0;char ch=getchar();bool flag=0;
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') flag=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	if(flag) x=-x;
}

void dfs(int start)
{
//	printf("dfs1(%d)\n",now);
	bool nozero=true;
	//非递归DFS，防止MLE 
	s.push(start);
	while(!s.empty())
	{
		int now=s.top();
		s.pop();
		vis[now]=true;
		if(deg[now]==0) nozero=false;
		for(int i=graph[now].nex;i;i=graph[i].nex)
		{
			if(!vis[graph[i].front])
			{
				s.push(graph[i].front);
			}
		}
	}
	if(nozero) 
	{
		puts("Draw");
		exit(0);
	}
}

void dfs1(int start)
{
//	printf("dfs1(%d)\n",now);
	s.push(start);
	while(!s.empty())
	{
		int now=s.top();
		s.pop();
		for(int i=graph[now].nex;i;i=graph[i].nex)
		{
			if(vis1[graph[i].front]==3) continue;
			if(vis1[now]==3)
			{
				vis1[graph[i].front]=3;
				s.push(graph[i].front);
				//dfs1(graph[i].front);
			}
			else if(vis1[now]==1)
			{
				if(vis1[graph[i].front]==2) continue;
				vis1[graph[i].front]|=2;
				s.push(graph[i].front);
				//dfs1(graph[i].front);
			}
			else
			{
				if(vis1[graph[i].front]==1) continue;
				vis1[graph[i].front]|=1;
				s.push(graph[i].front);
				//dfs1(graph[i].front);
			}
		}
	}
}

void dfs2(int start)
{
//	printf("dfs2(%d)\n",now);
	s.push(start);
	while(!s.empty())
	{
		int now=s.top();
		s.pop();
		for(int i=graph2[now].nex;i;i=graph2[i].nex)
		{
			if(vis2[graph2[i].front]==3) continue;
			if(vis2[now]==3)
			{
				vis2[graph2[i].front]=3;
				s.push(graph2[i].front);
				//dfs2(graph2[i].front);
			}
			else if(vis2[now]==1)
			{
				if(vis2[graph2[i].front]==2) continue;
				vis2[graph2[i].front]|=2;
				s.push(graph2[i].front);
				//dfs2(graph2[i].front);
			}
			else
			{
				if(vis2[graph2[i].front]==1) continue;
				vis2[graph2[i].front]|=1;
				s.push(graph2[i].front);
			}
		}
	}
}

int finish[100001];
int nfin=0;

void dfs3(int now)
{
	vis[now]=true;
	for(int i=graph[now].nex;i;i=graph[i].nex)
	{
		if(!vis[graph[i].front])
		{
			dfs3(graph[i].front);
		}
	}
	finish[++nfin]=now;
}

bool circle(int now)
{
	memset(vis,0,sizeof(vis));
	//只DFS一次——特殊情况5：环路不可到达 
	dfs3(now);
	for(int i=nfin;i;i--)
	{
		vis3[finish[i]]=true;
		//cout<<finish[i]<<" ";
		for(int p=graph2[finish[i]].nex;p;p=graph2[p].nex)
		{
			//一个强连通分量中存在不只一个点——存在环路 
			//vis[graph2[p].front]]——特殊情况6：原本不可到达的节点在图反转后可到达 
			if(vis[graph2[p].front]&&!vis3[graph2[p].front])	return true;
		}
	}
	//cout<<endl;
	return false;
}

void output(int from)
{
//	printf("output(%d)\n",now);
	memset(vis,0,sizeof(vis));
	bool zero=true;
	int now=from;
	int n=1;
	while(true)
	{
		printf("%d ",now);
		if(deg[now]==0) break;
		vis[now]++;
		int contimes=1;
		for(int i=graph[now].nex;true;i=graph[i].nex)
		{
			if(!i) i=graph[now].nex;
			//printf("(%d,%d)",contimes,vis[now]);
			if(n==1)
			{
				if(vis2[graph[i].front]&1)
				{
					if(vis[now]==contimes)
					{
						now=graph[i].front;
						n=2;
						break;
					}
					//特殊情况3：处理环路 
					else
					{
						contimes++;
						continue;
					}
				}
			}
			else
			{
				if(vis2[graph[i].front]&2)
				{
					if(vis[now]==contimes)
					{
						now=graph[i].front;
						n=1;
						break;
					}
					else
					{
						contimes++;
						continue;
					}
				}
			}
		}
	}
}

int main()
{
	int v,e;
	read(v);read(e);
	for(int i=1;i<=v;i++)
	{
		int n,to;
		read(n);
		deg[i]=n;
		if(n==0)
		{
			end[++nend]=i;
		}
		else
		{
			graph[i].nex=++tail;
			while(n--)
			{
				read(to);
				graph[tail].front=to;
				graph[tail].nex=tail+1;
				++tail;
			}
			graph[--tail].nex=0;
		}
	}
	tail=100000;
	for(int i=1;i<=v;i++)
	{
		for(int p=graph[i].nex;p;p=graph[p].nex)
		{
			int tmp=graph2[graph[p].front].nex;
			graph2[graph[p].front].nex=++tail;
			graph2[tail].front=i;
			graph2[tail].nex=tmp;
		}
	}
	read(start);
	if(nend==0)
	{
		puts("Draw");
		return 0;
	}
	//特殊情况1：处理图不联通 
	dfs(start);
	vis1[start]=1;
	dfs1(start);
	bool iswin=false;
	for(int i=1;i<=nend;i++)
	{
		//特殊情况2：处理出度为零的点不可到达 
		if(vis1[end[i]]!=1&&vis1[end[i]]) iswin=true;
		vis2[end[i]]=1;
		dfs2(end[i]);
	}
	if(iswin)
	{
		puts("Win");
		output(start);
		return 0;
	}
	//特殊情况4：处理存在可以Lose的点，但存在环路 
	if(circle(start))
	{
		puts("Draw");
		return 0;
	}
	puts("Lose");
	return 0;
}

