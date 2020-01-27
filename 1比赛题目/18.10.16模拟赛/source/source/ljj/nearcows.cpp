#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=100005;

inline int read()
{
	int ret=0; char ch=getchar();
	while (!(ch>='0' && ch<='9')) ch=getchar();
	while (ch>='0' && ch<='9') ret=ret*10+(ch-'0'),ch=getchar();
	return ret;
}

struct edges{
	int next,to;
} ed[maxn<<2];
int head[maxn],ip;

void add(int u,int v)
{
	ed[++ip].next=head[u]; 
	ed[ip].to=v;
	head[u]=ip;
}

int n,k;
int fa[maxn],f[maxn][25],a[maxn];

void dfs(int u,int father)
{
	int v;
	fa[u]=father;
	f[u][0]=a[u];
	for (int i=head[u]; i; i=ed[i].next)
	{
		v=ed[i].to;
		if (v!=father)
		{
			dfs(v,u);
			for (int j=1; j<=k; j++)
				f[u][j]+=f[v][j-1];
		}
	}
}

int main()
{
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	
	n=read(); k=read();
	int x,y;
	for (int i=1; i<n; i++)
	{
		x=read(); y=read();
		add(x,y);
		add(y,x);
	}
	
	for (int i=1; i<=n; i++)
		a[i]=read();
	
	dfs(1,0);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=k; j++)
			f[i][j]+=f[i][j-1];
	
	int ans,ck,now;
	for (int i=1; i<=n; i++)
	{
		ans=f[i][k];
		ck=k;
		now=i;
		while (now!=0 && ck>0)
		{
			ck--;
			ans+=f[fa[now]][ck];
			if (ck!=0) ans-=f[now][ck-1];
			now=fa[now];
		}
		if (i==1) ans+=f[i][k-2];
		printf("%d\n",ans);
	}
	
	return 0;
}
