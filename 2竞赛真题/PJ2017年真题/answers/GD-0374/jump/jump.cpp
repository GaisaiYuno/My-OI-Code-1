#include<iostream>
#include<cstdio>
using namespace std;

struct tnode{
	int jl,v;
}a[500001],f[500001];

int n,d,p,sum=0;

int check(int mid)
{
	int s,t,ans=0;
	if(mid>=d) s=1;
	else s=d-mid;
	t=mid+d;
	for(int i=1;i<=n;i++)
		f[i].jl=a[i].jl;
	for(int i=1;i<=n;i++)
		f[i].v=-2000000000;
	for(int i=0;i<=n;i++)
	{
		if(f[i].v || i==0)
		{	
			for(int k=i+1;k<=n;k++)
				for(int j=s;j<=t;j++)
					if(f[i].jl+j==f[k].jl) 
					{
						f[k].v=max(f[k].v,f[i].v+a[k].v);
					}
		}
		ans=max(ans,f[i].v);
	}
	if(ans<=p) return true;
	return false;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].jl>>a[i].v;
		if(a[i].v>0) sum+=a[i].v;
	}
	if(sum<p) cout<<-1;
	else
	{
		int lb=0,ub=n+d+10,mid;
		while(lb+1<ub)
		{
			mid=(lb+ub)/2;
			if(check(mid)) lb=mid;
			else ub=mid;
		}
		cout<<ub;
	}
	return 0;
}
