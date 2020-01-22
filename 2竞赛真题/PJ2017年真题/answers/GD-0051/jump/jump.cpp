#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,a[500100],s[500100],lo=0,hi,mid,h,ob;
bool check()
{
	int ans=0,t=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]-a[t]>mid+d)
		{
			int lt=t,la=-123456789;
			for(int j=t+1;j<i;j++)
			{
				if(a[j]-a[t]>=h)
				{
					if(s[j]>=0)
					{
						lt=j;
						break;
					}
					if(s[j]>la||(s[j]==la&&j>lt))
					{
						lt=j;
						la=s[j]; 
					}
				}
			}
			t=lt;
			ans+=s[t];
		}
		while(i==n&&t!=n)
		{
			int lt=t,la=-123456789;
			for(int j=t+1;j<=i;j++)
			{
				if(a[j]-a[t]>=h)
				{
					if(s[j]>=0)
					{
						lt=j;
						break;
					}
					if(s[j]>la||(s[j]==la&&j>lt))
					{
						lt=j;
						la=s[j]; 
					}
				}
			}
			if(lt==t) break;
			t=lt;
			ans+=s[t];
		}
	}
	if(ans>=k) return true;
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		if(s[i]>0) ob+=s[i];
	}
	if(ob<k)
	{
		cout<<-1<<endl;
		return 0;
	}
	hi=a[n]+1;
	while(lo+1<hi)
	{
		mid=(lo+hi)/2;
		h=d-mid;
		if(h<=0) h=1;
		if(check()) hi=mid;
		else lo=mid;
	}
	cout<<lo+1<<endl;
	return 0;
}
