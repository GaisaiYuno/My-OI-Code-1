#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,d,k,f[10000001],point[5000001],dis[5000001];
bool check(int g)
{
	memset(f,0,sizeof(f));
	int maxn,minn,maxx=-9999999;
	if(d>g)
	{
		minn=d-g;
		maxn=d+g;
	}
	else
	{
		minn=1;
		maxn=d+g;
	}
	dis[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
			if(dis[i]-dis[j]<=maxn&&dis[i]-dis[j]>=minn)
				maxx=max(maxx,f[j]);
		if(maxx==-9999999)
			f[i]=-99999999;
		else
			f[i]=point[i]+maxx;
		maxx=-9999999;
	}
	for(int i=1;i<=n;i++)
		maxx=max(maxx,f[i]);
	if(maxx>k)
		return true;
	else
		return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(dis,0,sizeof(dis));
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
		cin>>dis[i]>>point[i];
	int l=0,r=1000000001,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	if(l==1000000001)
		cout<<-1<<endl;
	else
		cout<<l<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
