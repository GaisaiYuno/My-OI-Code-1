#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())

using namespace std;

inline int IN(){
	char c;Rin x=0;for(;oo<48;);
	for(;c>47;oo)x=(x<<3)+(x<<1)+c-48;return x;
}

int n,m,i,j,k,u,v,ans,tot;
int p[2000005],fa[2000005],size[2000005],a[2000005];

int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void Union(int u,int v){u=get(u);v=get(v);fa[u]=v;}

int main()
{
//	freopen("conch.in","r",stdin);
//	freopen("conch.out","w",stdout);
	scanf("%d%d",&k,&m);
	for(i=1;i<=k;++i)
	{
		u=IN();v=IN();
		if(u>n)n=u;if(v>n)n=v;
		p[u]=v;p[v]=u;
	}
	ans=m;
	for(i=1;i<=n;++i)fa[i]=i;
	for(i=1;i<=n;++i)
	if(p[i])
	{
		for(j=p[i]+1;!p[j]&&j<=n;++j);
		if(j<=n)Union(i,j);
	}
	for(i=1;i<=n;++i)if(p[i])++size[get(i)];
	for(i=1;i<=n;++i)if(p[i])break;
	k=i;
	for(i=1;i<=n;++i)
	if(p[i]&&fa[i]==i)
	{
		if(i==get(k))ans+=size[i];
		else a[++tot]=size[i];
	}
	sort(a+1,a+tot+1);
	for(i=tot;i>=1&&m;--i,--m)ans+=a[i]+1;
	ans+=m/2*2;
	printf("%d\n",ans);
}
