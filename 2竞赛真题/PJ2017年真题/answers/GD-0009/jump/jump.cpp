#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d,k;
int w[500000+200],poi[500000+200];
int used[500000+200];
bool bz;
void dfs(int x,int g,int sum)
{
	if(bz)
		return;
	if(sum>=k)
	{
		bz=1;
		return;
	}
	if(x>=n)
		return;
	int l,r,t=x+1,maxn=-999999,next=0;
	if(g<d)
	{
		l=d-g;
		r=d+g;
		
	}
	else
	{
		l=1;
		r=d+g;
	}
	if(x!=0)
	{
		l+=w[x];
		r+=w[x];
	}
	while(w[t]<=r&&t<=n)
	{
		if(l<=w[t])
		{
			dfs(t,g,sum+poi[t]);
		}
		t++;
	}
		
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long long maxn=0;
	scanf("%d %d %d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&w[i],&poi[i]);
		if(poi[i]>0)
			maxn+=(long long)poi[i];
	}
	
	if((long long)maxn<k)
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<=w[n];i++)
	{
		dfs(0,i,0);
		if(bz)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
}
