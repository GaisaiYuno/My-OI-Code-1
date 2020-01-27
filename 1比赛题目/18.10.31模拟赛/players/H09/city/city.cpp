#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=10005;
const int maxd=1000005;

struct building{
	int l,r;
} blk[maxn],b[maxn];

int n,m,tot,cur;
int a[maxn],ans[maxd*6];

bool cmp(building x,building y)
{
	return x.l<y.l;
}

int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1; i<=m; i++)
		scanf("%d%d",&blk[i].l,&blk[i].r);
	sort(blk+1,blk+m+1,cmp);
	
	tot=m; cur=1;
	b[cur].l=blk[1].l,b[cur].r=blk[1].r;
	for (int i=2; i<=m; i++)
	{
		if (blk[i].l<=b[cur].r)
		{
			tot--;
			b[cur].r=max(b[cur].r,blk[i].r);
		}
		else 
		{
			cur++;
			b[cur].l=blk[i].l; b[cur].r=blk[i].r;
		}
	}
	sort(b+1,b+tot+1,cmp);
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=tot; j++)
		{
			int x=b[j].l-a[i],y=b[j].r-a[i]; 
			ans[x+maxd]++; ans[y+maxd+1]--;
		}
	}
	
	for (int i=1; i<=2*maxd; i++)
		ans[i]+=ans[i-1];
	
	int d=1e9,s=0; 
	for (int i=0; i<=2*maxd; i++)
		if (ans[i]>s) 
		{
			d=abs(i-maxd);
			s=ans[i];
		}
		else if (ans[i]==s)
			d=min(d,abs(i-maxd));
	
	printf("%d %d\n",d,s);
	
	return 0;
}
