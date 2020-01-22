#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
long long n,d,k,cinn,a[500005],score,s=0,money,_long,maxx,t=0;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%lld%lld%lld",&n,&d,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&cinn);
		cin>>score;
		a[cinn]=score;
		if(score>0)
		{
			s+=score;
			if(cinn>maxx)
				maxx=cinn;
		}
	}
	if(s<k)
	{
		printf("%d",-1);
		return 0;
	}
	int b=0;
	for(int i=1;i<=maxx;i++)
	{
		if(a[i]!=0)
		{
			t=b;
			b=i;
		}
		money=max(money,b-t+1);
	}
	_long=money;
	money-=d;
	t=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=0)
		{
			for(int j=i+1;j<i+_long;j++)
				if(a[j]!=0)
				{
					t=j;
					if(t==0)
					{
						i=t;
						break;
					}
					else if(a[j]>a[t])
						t=j;
				}
			if(t==i)
				for(int j=i+_long+1;a[j]==0;j++)
				{
					money++;
					t=j;
				}
			i=t;
		}
	printf("%d",money);
	return 0;
}
