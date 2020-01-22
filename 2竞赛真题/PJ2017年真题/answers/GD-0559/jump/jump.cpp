#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,i,x,s[100000],f[100000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=0;i<n;i++)
	{
		cin>>x>>s[i];
		if (s[i]>0) f[i]=f[i-1]+s[i];
		else f[i]=f[i-1];
	}
	if (f[n]<k) cout<<-1<<endl;
	return 0;
}
