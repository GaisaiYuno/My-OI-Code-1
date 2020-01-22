#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500005],b[500005],v;
long long sum;
long long check(int mid)
{
	long long  ma_x=0;
	int g[100005];
	long long  d[100005];
	for(int i=0;i<=100000;i++) g[i]=0;
	for(int i=1;i<=n;i++) d[a[i]]=b[i];
	g[0]=1;
	for(int i=0;i<=n;i++)
	{
		if(g[a[i]]==1) 
		{
//			cout<<1<<" ";
			for(int j=0;j<=mid*2;j++)
			{
				if(d[a[i]+v-mid+j]!=0) 
				{
					d[a[i]+v-mid+j]=d[a[i]]+d[a[i]+v-mid+j];
					ma_x=max(ma_x,d[a[i]+v-mid+j]);
					g[a[i]+v-mid+j]=1;
				} 
			}
		}
	}
	return ma_x;
}
int main()
{

	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>v>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(b[i]>0) sum+=b[i];
	}	
	if(sum<k) 
	{
		cout<<-1;
		return 0;
	}
	else 
	{
		for( int i=0;i<=a[n];i++)
		{
	
			if(check(i)>=k)
			{
				cout<<i;
				return 0;
			}
		}
	}
	cout<<-1;
	return 0;
}
