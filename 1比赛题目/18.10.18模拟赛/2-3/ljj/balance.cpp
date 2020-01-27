#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=100005;

struct data{
	int x,y;
} a[maxn];

int n,ans,mx;

int check(int xb,int yb)
{
	int ret,cc1,cc2,cc3,cc4;
	cc1=cc2=cc3=cc4=ret=0;
	for (int i=1; i<=n; i++)
	{
		if (a[i].x<xb && a[i].y<yb) cc1++;
		else if (a[i].x<xb && a[i].y>yb) cc2++;
		else if (a[i].x>xb && a[i].y<yb) cc3++;
		else if (a[i].x>xb && a[i].y>yb) cc4++;
	}
	ret=max(ret,cc1);
	ret=max(ret,cc2);
	ret=max(ret,cc3);
	ret=max(ret,cc4);
	return ret;
}

int main()
{
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		mx=max(a[i].x,mx); mx=max(a[i].y,mx); 
	}
	
	ans=1e9;
	int tmp; 
	for (int x=2; x<mx; x+=2)
	{
		for (int y=2; y<mx; y+=2)
		{
			tmp=check(x,y);
			ans=min(ans,tmp);
		} 
	}
	printf("%d\n",ans);
		
	return 0;
}
