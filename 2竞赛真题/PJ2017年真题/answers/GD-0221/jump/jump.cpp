#include<bits/stdc++.h>
using namespace std;
int n,d,k,tot=0,g,mx,i;
int x[1000000],s[10000000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(i=1;i<=n;i++)
	{
		cin>>x[i]>>s[i];
		tot+=s[i];
		mx=x[i];
	}
	x[0]=0;
	if(tot<k)
	{
		cout<<"-1";
		return 0;
	}
	tot=0;
	for(g=1;g<=mx;g++)
	{
		if(g<d)
		{
			for(i=1;i<=n;i++)
			{
				if(x[i]-x[i-1]>=d-g&&x[i]-x[i-1]<=d+g) tot+=s[i];
				if(tot>=k)
				{
					cout<<g;
					return 0;
				}
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				if(x[i]-x[i-1]>=1&&x[i]-x[i-1]<=d+g) tot+=s[i];
				if(tot>=k)
				{
					cout<<g;
					return 0;
				}
			}
		}
	}
}
