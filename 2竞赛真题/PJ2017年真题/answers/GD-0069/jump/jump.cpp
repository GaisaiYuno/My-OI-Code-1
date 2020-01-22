#include<iostream>
#include<cstdio>
using namespace std;
int n,d,MIN,dis[500005],val[500005],f[500005];
bool check(int mid)
{
	int beg,end;
	beg=max(1,d-mid);
	end=min(d+mid,dis[n]);
	for(int i=1;i<=n;i++)	f[i]=-1;
	f[0]=0;
	for(int i=0;i<=n;i++)
		if(f[i]!=-1)
			for(int j=i+1;j<=n;j++)
				if(dis[i]+end>=dis[j]&&dis[i]+beg<=dis[j])
				{
					f[j]=max(f[j],f[i]+val[j]);
					if(f[j]>=MIN)	return true;
				}
	return false;
}
int main()
{
//	cout<<(sizeof(dis)+sizeof(val)+sizeof(f))/(1024*1024)<<endl;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&MIN);
	for(int i=1;i<=n;i++)	scanf("%d%d",&dis[i],&val[i]);
	int L,R;
	L=0;R=dis[n];
	while(L+1<R)
	{
		int mid;
		mid=(L+R)/2;
		if(check(mid))	R=mid;
		else L=mid;
	}
	if(check(R))	printf("%d",R);
	else printf("-1");
	return 0;
}
