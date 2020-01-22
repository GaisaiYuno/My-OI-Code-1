#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n,d,k,ans=100000000;
struct I
{
	int l;
	int s;
}blank[500010];
void ks(int socre,int now,int xn1,int xn2,int now2)
{
	if(socre>=k)
	{
		if(xn2-d<ans) ans=d-xn1;
		return;
	}
	if(xn1<1) return;
	if(now2==n) return;
	for(int i=now2+1;i<=n;++i)
	{
		if(blank[i].l-now>=xn1&&blank[i].l-now<=xn2)
			ks(socre+blank[i].s,blank[i].l,xn1,xn2,i);
		else
		{
			if(blank[i].l-now<xn1)
				ks(socre+blank[i].s,blank[i].l,blank[i].l-now,d+d-blank[i].l+now,i);
			else
				ks(socre+blank[i].s,blank[i].l,d-blank[i].l+now+d,blank[i].l-now,i);
		}
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&blank[i].l,&blank[i].s);
	ks(0,0,d,d,0);
	if(ans==100000000) ans=-1;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
