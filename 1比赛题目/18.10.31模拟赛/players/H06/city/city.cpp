/*我相信暴力出奇迹*/
/*O(mlogm+an)过百万 暴力碾标算*/
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define re register int
#define fast static int
using namespace std;
typedef long long ll;
int read()
{
	re x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=10005;
const int Maxn=1000005;
const int INF=0x3f3f3f3f;
bool vis[Maxn];
int Search(int lpos,int rpos)
{
	int l=lpos,r=rpos,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(vis[mid])
		{
			l=mid+1;
		} else {
			r=mid-1;
		}
	}
	return l-1;
}
int n,m,a[Size];
struct Building
{
	int l,r;
} w[Size];
inline bool comp(Building x,Building y)
{
	if(x.l!=y.l)	return x.l<y.l;
	return x.r>y.r;
}
int mina,maxa,minl,maxr;
void init()
{
	n=read();
	m=read();
	mina=minl=INF;
	maxa=maxr=-1;
	for(re i=1; i<=n; i++)
	{
		a[i]=read();
		if(a[i]<mina)	mina=a[i];
		if(a[i]>maxa)	maxa=a[i];
	}
	for(re i=1; i<=m; i++)
	{
		w[i].l=read();
		w[i].r=read();
		if(w[i].l<minl)	minl=w[i].l;
		if(w[i].r>maxr)	maxr=w[i].r;
	}
	sort(w+1,w+1+m,comp);
	for(re i=1; i<=m; i++)
	{
		for(re j=max(w[i-1].r,w[i].l); j<=w[i].r; j++)
		{
			vis[j]=true;
		}
	}
}
inline bool Query(int pos)
{
	return pos>=0 && pos<=maxr && vis[pos];
}
int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	init();
	int d=0,s=0;
	for(re j=1; j<=n; j++)
	{
		if(Query(a[j]))
		{
			s++;
		}
	}
	for(re i=minl-maxa; i<=maxr-mina; i++)
	{
		int sum=0;
		for(re j=1; j<=n; j++)
		{
			if(Query(a[j]+i))
			{
				sum++;
			}
		}
		if(sum>s)
		{
			s=sum,d=abs(i);
		} else if(sum==s) {
			d=min(d,abs(i));
		}
//		printf("%d %d %d\n",i,d,s);
	}
	printf("%d %d\n",d,s);
	return 0;
}
