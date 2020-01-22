#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[500001],b[500001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,t=0,s=0;
	cin>>n>>d>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i];
		if(b[i]>0) t+=b[i];
	}
	if(t<d)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		cout<<abs(a[i]-a[i-1]-d)<<endl;
		s=max(s,abs(a[i]-a[i-1]-d));
	}
	cout<<s<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
