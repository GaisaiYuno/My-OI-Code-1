#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;
int n,d,k,l,r,mid,a[1000000],b[1000000],f[1000000],tree[5000000];
int ml,mr;
bool t;
void build(int l,int r,int h)
{
	tree[h]=-10000000;
	if (l==r)return;
	int m=(l+r)/2;build(l,m,h*2);build(m+1,r,h*2+1);
}
void chang(int l,int r,int h,int y)
{
	if (l>y||r<y)return;if (l==r){tree[h]=f[y];return;}
	int m=(l+r)/2;chang(l,m,h*2,y);chang(m+1,r,h*2+1,y);
	tree[h]=max(tree[h*2],tree[h*2+1]);
}
int che(int l,int r,int h,int x,int y)
{
	if (l>y||r<x)return -10000000;if (x<=l&&r<=y){return tree[h];}
	int m=(l+r)/2;return max(che(l,m,h*2,x,y),che(m+1,r,h*2+1,x,y));
}
bool check(int x)
{
	int l=max(1,d-x),r=x+d;build(0,n,1);
	f[0]=0;chang(0,n,1,0);
	for(int i=1;i<=n;i++)
	{
		f[i]=-10000000;int xx=a[i]-r,y=a[i]-l;
		mr=0;int r=i;
		while (mr+1<r)
		{
			int mid=(mr+r)/2;
			if (a[mid]<=y)mr=mid;else r=mid;
		}
		ml=i-1;r=-1;
		while (r+1<ml)
		{
			int mid=(ml+r)/2;
			if (xx<=a[mid])ml=mid;else r=mid;
		}
		if (xx<=a[ml]&&a[mr]<=y)
		f[i]=max(f[i],che(0,n,1,ml,mr)+b[i]);
		if (f[i]>=k)return true;
		if (f[i]!=-10000000)chang(0,n,1,i);
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	l=-1;r=a[n]+d;
	while (l+1<r)
	{mid=(l+r)/2;if (check(mid)){r=mid;t=true;}else l=mid;}
	if(t)cout<<r;else cout<<-1;
	return 0;
}
