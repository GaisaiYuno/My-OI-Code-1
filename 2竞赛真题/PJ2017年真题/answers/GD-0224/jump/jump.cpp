#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct A
{
	int len,num;
}a[1000005];
int n,m,k,d,f[1000005],p[1000005];
int check(int g)
{
	memset(f,0,sizeof(f));
	memset(p,0,sizeof(p));
	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		int l=i-1;
		while(a[i].len<=a[l].len+(d+g)&&l>=0)
		{
		
			if(a[l].len+max(d-g,1)>a[i].len) l--;
			if(a[i].len>a[l].len+(d+g)) break;
		
			if(l<0) break;
			//	cout<<l<<endl;
			if(p[l])
			{
				if(p[i]==0) 
			{
			f[i]=f[l]+a[i].num;	
			p[i]=1;
			}
			else f[i]=max(f[i],f[l]+a[i].num);
			}
			l--;
			if(f[i]>=k) return 1;
		}
	//	cout<<f[i]<<endl;
	}
	return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++) cin>>a[i].len>>a[i].num;
	if(check(0)) 
	{
		cout<<0;
		return 0;	
	}
	int l=0,r=1000000001;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
//	cout<<r;
	if(check(r)) cout<<r;
	else cout<<-1;
	return 0;
}
