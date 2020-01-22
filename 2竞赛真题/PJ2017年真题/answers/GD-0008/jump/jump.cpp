#include<iostream>
#include<cstdio>
using namespace std;
long long x[500001],f[500001];
int s[500001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long long n,d,k,s1=0;
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>s[i];
		if(s[i]>0)
		s1+=s[i];
	}
	if(s1<k)
	{
		cout<<-1<<endl;
	}
	else
	{
		long long l=0,r=x[n],j,ans;
		long long mid;
		while(l<r)
		{
			mid=(l+r)/2;
			ans=0;
			for(int i=0;i<=n;i++)
			f[i]=0;
			for(int i=1;i<=n;i++)
			{
				j=1;
				while(x[i]-d+mid>=x[i-j]&&x[i]-d-mid<=x[i-j]&&j<=i)
				{
					f[i]=max(f[i],f[i-j]+s[i]);
					j++;
				}
				ans=max(ans,f[i]);
				if(ans<=0)
				break;
			}
			if(ans>0)
			r=mid;
			else
			l=mid+1;
		}
		cout<<l<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
