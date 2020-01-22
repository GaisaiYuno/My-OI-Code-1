#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int x[1000],s[1000];
bool flag=false;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,sum=0;
	cin>>n>>d>>k;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>s[i];
		sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		sum+=s[i];
		if(sum>=k)flag=true;
	}
	if(flag==false)
	{
	cout<<"-1";
	cout<<endl;
	return 0;
}
}
