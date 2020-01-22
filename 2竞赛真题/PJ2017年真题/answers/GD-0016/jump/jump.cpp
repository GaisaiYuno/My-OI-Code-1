#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int pd=0;
long long n,d,k,longdis=-1;
long long jl[10000000],mark[500010],f[10000000];
bool check(long long mid)
{
	memset(f,0,sizeof(f));
	long long s,b=d+mid;
	if(mid<d) s=d-mid;
	else s=1;
	for(long long i=s;i<=longdis;i++)
	{
		long long maxn=-1000000000;
		for(long long j=i-b;j<=i-s;j++)
			if(j>=0&&f[j]>maxn) maxn=f[j];
		f[i]=maxn;
		if(jl[i]) f[i]+=mark[jl[i]];
		if(f[i]>=k) 
		{
			pd=1;
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long long dis;
	cin>>n>>d>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>dis>>mark[i];
		jl[dis]=i;
		if(dis>longdis) longdis=dis;
	}
	long long x=-1,y=longdis+1;
	while(x+1<y)
	{
		long long mid=(x+y)/2;
		if(check(mid)) y=mid;
		else x=mid;
	}
	if(pd==1) cout<<y<<endl;
	else cout<<-1<<endl;
	return 0;
}
