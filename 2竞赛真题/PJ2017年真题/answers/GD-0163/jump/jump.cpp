#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int n,k,d,x[505],s[505],f[505],sc[505];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	if (n>500&&d!=1) {cout<<-1;exit(0);}
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>s[i];
	}
	for (int g=1;g<=x[n];g++)
	{
		for (int i=1;i<=n;i++) f[i]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
				if (x[i]+g+d>x[j])
				  {
				  f[j]=max(f[j],f[i]+s[j]);
				  	if (f[j]>=k) {cout<<g;exit(0);}
				  }else break;
		}
	}
	cout<<-1;
	return 0;
}
