#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=300005;
const int inf=1e9;

int n,k,cur;
int d[maxn];
int mx[maxn<<2],mn[maxn<<2];

void pushup(int tmp)
{
	mx[tmp]=max(mx[tmp<<1],mx[tmp<<1|1]);
	mn[tmp]=min(mn[tmp<<1],mn[tmp<<1|1]);
}
void build(int tmp,int l,int r)
{
	if (l==r)
	{
		mn[tmp]=mx[tmp]=d[++cur];
		return;
	}
	int mid=(l+r)>>1;
	build(tmp<<1,l,mid);
	build(tmp<<1|1,mid+1,r);
	pushup(tmp);
}
int qrymx(int tmp,int l,int r,int x,int y)
{
	if (x<=l && r<=y) return mx[tmp];
	int mid=(l+r)>>1,ret=-inf;
	if (x<=mid) ret=max(ret,qrymx(tmp<<1,l,mid,x,y));
	if (y>mid) ret=max(ret,qrymx(tmp<<1|1,mid+1,r,x,y));
	return ret;
}
int qrymn(int tmp,int l,int r,int x,int y)
{
	if (x<=l && r<=y) return mn[tmp];
	int mid=(l+r)>>1,ret=inf;
	if (x<=mid) ret=min(ret,qrymn(tmp<<1,l,mid,x,y));
	if (y>mid) ret=min(ret,qrymn(tmp<<1|1,mid+1,r,x,y));
	return ret;
}

bool check(int len)
{
	for (int i=1; i+len-1<=n; i++)
	{
		if (qrymx(1,1,n,i,i+len-1)-qrymn(1,1,n,i,i+len-1)<=k) 
			return true;
	}
	return false;
}

int main()
{
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++)
		scanf("%d",&d[i]);
	
	build(1,1,n);
	
	int l=0,r=n+1,mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	
	return 0;
}
