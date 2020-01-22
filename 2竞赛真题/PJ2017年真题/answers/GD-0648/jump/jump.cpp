#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
	int x,y,z;
}a[500005];
int n,d,k;
bool ck(int g)
{
	int p=0;
	for(int i=1;i<=n;i++)
	{
		a[i].z=-2000000000;
		for(int j=p;j<i;j++)
		{
			//a[i].z=a[i].y;
			if(a[i].x-a[j].x<max(1,d-g))break;
			if(a[i].x-a[j].x>d+g)
			{
				p=j;
				continue;
			}
			a[i].z=max(a[i].z,a[j].z+a[i].y);
		}
		if(a[i].z==-2000000000)return 0;
		if(a[i].z>=k)return 1;
	}
	return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	a[0].x=0;a[0].y=0;
	int l=0,r=a[n].x;
	while(l<r)
	{
		int mid=(l+r)/2;
		//cout<<ck(mid)<<endl;
		if(ck(mid))r=mid;
		else l=mid+1;
	}
	if(ck(l))printf("%d",l);
	else printf("-1");
	return 0;
}
