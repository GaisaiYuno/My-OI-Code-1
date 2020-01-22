#include<cstdio>
#include<cstring>
int x[501],c[501];
void dfs(int l,int r)
{
	int x=l,y=r,m=c[(x+y)/2];
	while(x<=y)
	{
		while(c[x]>m) x++;
		while(c[y]<m) y--;
		if(x<=y)
		{
			int t=c[x]; c[x]=c[y]; c[y]=t;
			x++; y--;
		}
	}
	if(x<r) dfs(x,r);
	if(y>l) dfs(l,y);
}
int main()
{
	freopen("jump.in","r",stdin);
freopen("jump.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&c[i]);
	}
	dfs(1,n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]>0) ans+=c[i];
		else break;
	}
	if(ans<k) printf("-1");
	else printf("2");
	return 0;
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
