#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=300005;

int a[maxn],cur;
int n,m,tpe;
int mn[maxn<<2];

void pushup(int tmp)
{
	mn[tmp]=min(mn[tmp<<1],mn[tmp<<1|1]);
}
void build(int tmp,int l,int r)
{
	if (l==r)
	{
		mn[tmp]=a[++cur];
		return;
	}
	int mid=(l+r)>>1;
	build(tmp<<1,l,mid);
	build(tmp<<1|1,mid+1,r);
	pushup(tmp);
}
int qry(int tmp,int l,int r,int x,int y)
{
	if (x<=l && r<=y) return mn[tmp];
	
	int mid=(l+r)>>1,ret=2e9;
	if (x<=mid) ret=min(ret,qry(tmp<<1,l,mid,x,y));
	if (y>mid) ret=min(ret,qry(tmp<<1|1,mid+1,r,x,y));
	return ret;
}

int solve(int x,int y)
{
	int ret=0,tmp;
	for (int i=x; i<y; i++)
		for (int j=i+1; j<=y; j++)
		{
			if (i==j-1) ret++;
			else 
			{
				bool flag=false; tmp=min(a[i],a[j]);
				for (int k=i+1; k<=j-1; k++)
					if (a[k]>=tmp)
					{
						flag=true;
						break;
					}
				if (!flag) ret++;
			}
		}
	return ret;
}

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&tpe);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
		
	int x,y;
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",solve(x,y));
	}
	
	return 0;
}
