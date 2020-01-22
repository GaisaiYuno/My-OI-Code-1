#include<cstdio>
#include<cstring>
#define skq(x) ((x)>0?(x):-(x))
int M=0,n,m,s,e,x[1010],y[1010],col[1010],head[1010],dis[1010],exist[1010],q[100010];
struct ed{int to,nxt,val;}edge[4000010];
void addedge(int u,int v,int w){
	edge[++M]=(ed){v,head[u],w};head[u]=M;
	edge[++M]=(ed){u,head[v],w};head[v]=M;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(dis,127/3,sizeof(dis));
	memset(head,0,sizeof(head));
	memset(exist,0,sizeof(exist));
	scanf("%d%d",&m,&n);e=0;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&x[i],&y[i],&col[i]);
		if (x[i]==1&&y[i]==1) s=i;
		if (x[i]==m&&y[i]==m) e=i;
		for (int j=1;j<i;++j)
		{
			if (skq(x[i]-x[j])+skq(y[i]-y[j])==1)
				addedge(i,j,skq(col[i]-col[j]));
			if (skq(x[i]-x[j])+skq(y[i]-y[j])==2)
				addedge(i,j,skq(col[i]-col[j])+2);
		}
	}
	if (!e)
	{
		e=++n;
		for (int j=1;j<n;++j)
			if (skq(m-x[j])+skq(m-y[j])==1)
				addedge(n,j,2);
	}
	int hd=0,tail=1,flag=1;
	q[1]=s;exist[s]=1;dis[s]=0;
	while (hd<tail)
	{
		hd=hd%10000+1;
		int u=q[hd],v;
		exist[u]=0;
		for (int i=head[u];i;i=edge[i].nxt)
		{
			v=edge[i].to;
			if (dis[u]+edge[i].val<dis[v])
			{
				dis[v]=dis[u]+edge[i].val;
				if (v==e) flag=0;
				if (!exist[v])
				{
					tail=tail%10000+1;
					q[tail]=v;
					exist[v]=1;
				}
			}
		}
	}
	printf("%d\n",flag?-1:dis[e]);
	fclose(stdin);fclose(stdout);
	return 0;
}
