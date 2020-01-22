#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,k,loc[500050],a[500050];
bool checkk(int minn,int maxx)
{
	int next,i,now=0,sum=0,maxxx;
	bool f;
	while (now<n)
	{
		maxxx=-2147483647;
		f=false;
		for (i=now+1;i<=n;i++)
		{
			if (loc[i]-loc[now]<minn) {continue;}
			if (loc[i]-loc[now]>maxx) {break;}
			if (a[i]>=maxxx)
			{
				f=true;
				maxxx=max(maxxx,a[i]);
				next=i;
			}
		}
		if (!f) {break;}
		sum+=maxxx;
		now=next;
	}
	if (sum>=k) {return true;}
	return false;
}
int main()
{
	int d,i,l,r,mid;
	bool f=false;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (i=1;i<=n;i++) {scanf("%d%d",&loc[i],&a[i]);}
	l=0;
	r=n;
	while (r>l)
	{
		mid=(l+r)/2;
		if(checkk(max(1,d-mid),d+mid)) {r=mid;f=true;}
		else {l=mid+1;}
	}
	if (f) {printf("%d",mid);}
	else {printf("-1");}
	return 0;
}
