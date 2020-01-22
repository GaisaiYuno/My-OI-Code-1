#include<bits/stdc++.h>
using namespace std;
int n,d,k,w[600000],i,sum,maxx,v,c,t[600000],b=0x3f,f[10000];
bool z[1000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(i=1;i<=n;i++)
	{
		int y;
		scanf("%d%d",&t[i],&y);
		w[i]=y;
		if(y>0)sum+=y;
		maxx=max(maxx,t[i]-v);
		v=t[i];
		c=max(t[i],c);
		b=min(t[i],b);
	}
	if(sum<k)
	{
		printf("-1");
		return 0;
	}
	if(d>=c)
	{
		printf("-1");
		return 0;
	}
	for(i=1;i<=c-d;i++)
	{
		int j,p,o;
		memset(f,0,sizeof(f));
		for(j=1;j<=n;j++)if(w[j]!=0)f[j]=w[j];
		for(j=1;j<=n;j++)
		for(p=j;p<=n;p++)if(t[j]-t[p]>d+i)
		{
			o=p;
			break;	
		}
		for(j=1;j<n;j++)
		{
			for(p=j+1;p<=n;p++)
			if(t[p]-t[j]<=d+i&&t[p]-t[j]>=d-i)
			f[p]=max(f[p],f[j]+w[p]);
		}
		for(int j=1;j<=o;j++)if(f[j]>=k)
		{
			cout<<i;
			return 0;
		}
	}
}
