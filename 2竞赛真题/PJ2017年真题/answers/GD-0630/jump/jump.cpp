#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,k,a[500000],b[500000],mine,e;long long be,o;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=0;i<n;i++)
	{
		int x,y;
		scanf("\n");
		scanf("%d%d",&a[i],&b[i]);
		if (b[i]>0) be+=a[i];o+=b[i];
		if (i!=0) mine=max(mine,a[i]-e);
		e=a[i];
	}
	mine-=d;
	if (be<k) cout<<-1;
	else 
	{
    	cout<<mine;
	}
	return 0;
}
