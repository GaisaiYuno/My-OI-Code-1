#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int n,d,k,i,a[10005],s[10005],su,sum,ans,q;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (i=1; i<=n; i++)
	{
		scanf("%d%d",&a[i],&s[i]);
		if (s[i]>0) su+=s[i];
	}
	if (su<k) {cout<<-1;return 0;}
	i=0;
	while (ans<k)
	{
		i++;
		if (s[i]>=0||s[i]<0&&s[i]+s[a[i]+a[i]-a[i-1]]>=0)
		{
			ans+=s[i];
			sum=a[i]-a[i-1];
		}
	}
	cout<<sum;
	return 0;
}
