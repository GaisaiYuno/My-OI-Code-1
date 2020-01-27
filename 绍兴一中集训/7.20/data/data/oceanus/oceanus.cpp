#include <cstdio>
#include <algorithm>

using namespace std;

const int inf=1000000000;

int edge[2000000],next[2000000],first[600000];
int b[600000],g[600000],h[600000];
pair <int,int> p[600000];
int i,j,k,l,m,n,r,s,t,v,w,x,y,sum_edge;

inline int fastscanf()
{
	int t=0;
	char c=getchar();
	while (! ((c>47) && (c<58)))
		c=getchar();
	while ((c>47) && (c<58))
		t=t*10+c-48,c=getchar();
	return t;
}

inline void addedge(int x,int y)
{
	sum_edge++,edge[sum_edge]=y,next[sum_edge]=first[x],first[x]=sum_edge;
	return;
}

inline void dfs(int x,int y,int u,int v)
{
	if (h[x]<h[u])
		v=u,u=x;
	else
		if (h[x]<h[v])
			v=x;
	k++;
	p[k]=make_pair(u,v);
	for (int i=first[x];i!=0;i=next[i])
		if (edge[i]!=y)
			dfs(edge[i],x,u,v);
	return;
}

inline bool cmp1(pair <int,int> x,pair <int,int> y)
{
	if (h[x.first]!=h[y.first])
		return h[x.first]>h[y.first];
	if (x.first!=y.first)
		return x.first<y.first;
	return h[x.second]>h[y.second];
}

inline bool cmp2(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("oceanus_5_kill_2.in","r",stdin);
	n=fastscanf();
	for (i=1;i<=n;i++)
		h[i]=fastscanf();
	h[n+1]=inf;
	for (i=1;i<n;i++)
	{
		x=fastscanf(),y=fastscanf();
		addedge(x,y),addedge(y,x);
	}
	m=fastscanf();
	for (i=1;i<=m;i++)
		g[i]=fastscanf();
	if (m>n)
	{
		printf("-1");
		return 0;
	}
	dfs(1,n+1,n+1,n+1);
	sort(p+1,p+n+1,cmp1);
	sort(g+1,g+n+1,cmp2);
	for (i=1;i<=n;i++)
		if (h[p[i].first]<g[i])
			t=i;
	printf("%d\n",t);
	freopen("oceanus_5_kill_2.out","w",stdout);
	for (i=1,w=1;i<=n;i=j)
	{
		for (j=i;p[i].first==p[j].first;j++);
		if ((j>t) && (j-i>=l))
		{
			s=0;
			for (k=i;k<j;k++)
			{
				if (k-i+1<=l)
					r=b[k-i+1];
				else
					r=g[w+k-i-l];
				if (r>h[p[k].second])
					break;
				s=max(s,r-h[p[k].first]);
			}
			if (k==j)
			{
				printf("%d",s);
				return 0;
			}
		}
		for (k=i;k<j;k++,w++)
			for (;(w<=n) && (g[w]>h[p[k].first]);w++)
				l++,b[l]=g[w];
	}
	printf("-1");
	return 0;
}
