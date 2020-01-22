#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,d,t,l[500001],a[500001],f[500001],sum;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&t);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d%d",&l[i],&a[i]);
		if (a[i]>0) sum+=a[i];
	}
	if (sum<t)
	{
		printf("-1\n");
		return 0;
	}
	int le=0,ri=1000000000;
	while (le<ri)
	{
		int mid=(le+ri)/2,now=0,p=0;
		sum=0;
		memset(f,0,sizeof(f));
		int ma=d+mid,mi=(d>mid)?d-mid:1;
		for (int i=1;i<=n;i++)
		{
			int Max=-200000000,now=0;
			if (l[i]-l[i-1]>ma) break;
			for (int j=i-1;l[i]-l[j]<=ma&&j>=0;j--)
				if (l[i]-l[j]>=mi&&Max<=f[j]) 
				{
					Max=f[j];
					now=j;
				}
			if (l[i]-l[now]>=mi) f[i]=a[i]+Max; else f[i]=Max;
		}
		int ans=0;
		for (int i=0;i<=n;i++)
			if (ans<f[i]) ans=f[i];
		if (ans>=t) ri=mid;
		else le=mid+1;
	}
	printf("%d\n",le);
	fclose(stdin);
	fclose(stdout);
}
