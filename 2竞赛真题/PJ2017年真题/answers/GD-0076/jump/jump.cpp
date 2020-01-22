#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,s[500000+10],ans,dis;
long long k,x[500000+10],sum,num;
bool g=0;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%d",&x[i],&s[i]);
		if(s[i]>0) sum+=s[i];
	}
	if(sum<k) cout<<-1<<endl;
	else
	{
		sum=dis=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]>0)
			{
				sum+=s[i];
				if(abs(x[i]-dis)>ans) ans=abs(x[i]-dis);
				dis=x[i];
				if(sum>=k)
				{
					cout<<abs(ans-d)<<endl;
					g=1;
					break;
				}
			}
		}
		if(sum<k&&!g) cout<<-1<<endl;
	}
	return 0;
}
