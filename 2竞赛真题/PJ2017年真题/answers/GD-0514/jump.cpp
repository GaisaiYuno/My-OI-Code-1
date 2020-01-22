#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int n,d,k,now,ans,l,r,m;
int x[500055],s[500055];
int jisuan(int now,int q,int w)
{
	//printf("%d\n",now);
	if(q>x[n])return 0;
	if(now>ans)ans=now;
	if(m<d)
	{
		int t=-327679,p=0;
		for (int i=q+1;i<=n;i++)
		{
			
			if(x[i]>w+d+m)break;
			else 
			if(x[i]>=w+d-m)
			{
					now+=s[i];
					jisuan(now,i,x[i]);
					now-=s[i];
			}
		}
	}
	else 
	{
		int t=-327679,p=0;
		for (int i=q+1;i<=n;i++)
		{
			
			if(x[i]>w+d+m)break;
			else 
			if(x[i]>=w)
			{
				now+=s[i];
				jisuan(now,i,x[i]);
				now-=s[i];
			}
		
		if(p!=0)
		{
	
		now+=t;
		jisuan(now,p,x[p]);
		}
	}
}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",x+i,s+i);
		if(s[i]>0)now+=s[i];
	}
	//printf("%d %d",now,k);
	if(now<k)
	{
		printf("-1");
		return 0;
	}
	 l=1;
	 r=x[n];
	 m=(l+r)/2;
	while (r>l)
	{
		ans=0;
		jisuan(0,0,0);
		//printf("%d %d\n",m,ans);
		if(ans>=k)
		{
			r=m;
			m=(l+r)/2;
		}
		else 
		{
			l=m+1;
			m=(l+r)/2;
		}
	}
	cout<<m;
}
