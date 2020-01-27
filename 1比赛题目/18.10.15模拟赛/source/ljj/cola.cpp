#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int p=2017;

struct edges{
	int next,to;	
};
int head[maxn],ip;

void add(int u,int v)
{
	ed[++ip].next=head[u];
	ed[ip].to=v;
	head[u]=ip;
}

int n,m,t;

void dfs(int u,int dep)
{
	if (dep==t) return;
}

int main()
{
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int x,y;
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	
	dfs(1,0);
	
	return 0;
}
