#include<iostream>
#include<cstdio>
using namespace std;
struct noip{
	int x=0,s=0,back=0;
}a[500001];
int n,d,k,b=0,c=0,i=0,j=0,x=0,y=0,z=0,ans=0;
long long all1=0,all=0;
int redo()
{
	for (i=1;i<=n;i++)
	{
		z=a[i].back-d;
		ans=z>ans?z:ans;
	}
	return ans;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (i=1;i<=n;i++) 
	{
		scanf("%d%d",&a[i].x,&a[i].s);
		a[i].back=a[i].x-a[i-1].x;
		if (a[i].s>=0) all1+=a[i].s;
		all+=a[i].s;
	}
	if (all1<k) 
	{
		cout<<"-1";
		return 0;
	}
    cout<<redo();
	return 0;
}
