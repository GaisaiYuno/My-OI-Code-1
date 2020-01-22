#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=500005;
const long long INF=1e11;
int n,d,k,ok=0;
long long dis[MAXN],mark[MAXN],f[MAXN];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;	
	for(int i=1;i<=n;i++)	
		cin>>dis[i]>>mark[i];
	
	for(int g=0;g<=n;g++)
	{
		int mina,maxa;
		if(g<d)	
		{
			mina=max(d-g,1);
			maxa=d+g;
		}
		else	
		{
			mina=1;
			maxa=d+g;
		}
		for(int i=1;i<=n;i++)	f[i]=-INF;
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(dis[i]-dis[j]<mina)	continue;
				if(dis[i]-dis[j]>maxa)	break;
				f[i]=max(f[i],f[j]+mark[i]);
			}
		}
		long long ans=-INF;
		for(int i=1;i<=n;i++)	
			ans=max(ans,f[i]);
		
		if(ans>=k)
		{
			cout<<g<<endl;
			ok=1;
			break;
		}
	}
	if(ok==0)	cout<<-1<<endl;	
	return 0;
}
