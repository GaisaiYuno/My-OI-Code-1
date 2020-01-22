#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100005;
const int inf=1e9;

int n;
int a[maxn],sum[maxn],tot,f[maxn],cnt;
double ans;

int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		tot+=a[i];
	}
	double tmp1,tmp2;
	for (int i=1; i<=n; i++)
	{
		tmp1=(double)tot/(double)n;
		tmp2=(double)(tot-a[i])/(double)(n-1);
		if (tmp1-tmp2>0.00001) 
			f[i]=1;
		else f[i]=-1;
	}
	
	int mx=-inf,tmp=-1,ms,me,st;
	for (int i=2; i<=n-1; i++)
	{
		if (tmp<0) tmp=0,st=i;
		tmp+=f[i];
		if (tmp>mx) mx=tmp,ms=st,me=i;
	}
	
	cnt=0;
	for (int i=ms; i<=me; i++)
		cnt+=a[i];
	
	ans=(double)(tot-cnt)/(double)(n-me+ms-1);
	printf("%.3lf\n",ans);
		
	return 0;
}
