#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,x[500100],s[500100],l,r,m,t1;
bool hua(int t)
{
	int ml=d-t,mr=d+t;
	if (ml<1) ml=1;
	int st=0,en=0,ans=0;
	while(st<n)
	{
		int t2=0;
		for (int i=st+1;i<=n;i++)
		{
			if (x[i]-x[st]>mr)
			{
				en=i-1;
				t2=1;
				break;
			}
		}
		if (t2==0&&x[n]-x[st]>=ml&&x[n]-x[st]<=mr) en=n;
		else if (en<=st||t2==0) if (ans<k) return false; else return true;
		int t1=-2147483648,tk;
		for (int i=st+1;i<=en;i++)
		{
			if (x[i]-x[st]>=ml&&x[i]-x[st]<=mr)
			{
				if (s[i]>0)
				{
					ans+=s[i];
					tk=i;
					break;
				}
				if (s[i]<=0&&t1<=s[i])
				{
					t1=s[i];
					tk=i;
				}
			}
		}	
		ans+=t1;
		st=tk;
		if (ans>=k) return true;
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
		if (s[i]>0) t1+=s[i];
	}
	if (t1<k)
	{
		printf("-1");
		return 0;
	}
	l=0;
	r=d-1;
	while (l<r)
	{
		m=(l+r)/2;
		if (hua(m)) r=m; else l=m+1;
	}
	printf("%d",r);
	return 0;
}
