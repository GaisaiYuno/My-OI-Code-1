#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,g,sum,q[500005],w[500005],a,b,x[500005],c;
bool y[500005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1; i<=n; ++i)
	{
		cin>>q[i]>>w[i];
		if(w[i]>0) sum+=w[i];
	}
	if(sum<k) cout<<-1;
	else
	{
	sum=0;
	g=-1;
	while(sum<k)
	{
		++g;
		sum=0;
		if(g<d) {a=d-g;b=d+g;}else{a=1;b=d+g;}
		for(int i=1; i<=n; ++i)
		{
			y[i]=false;
			x[i]=0;
		}
		for(int i=1; i<=n; ++i)
		{
			if(a<=q[i]&&q[i]<=b) {c=w[i];y[i]=true;}
			for(int j=1; j<i; ++j)
			if(a<=q[i]-q[j]&&q[i]-q[j]<=b&&y[j]) {c=max(c,w[i]+x[j]);y[i]=true;}
			if(y[i]){x[i]=c;sum=max(sum,x[i]);}
			if(sum>=k) break;
		}
	}
	cout<<g;
	}
	return 0;
}
