#include <iostream>
#include <cstdio>
using namespace std;
int n,d,k,a[500001],b[500001],bt[500001],f[500001],i,j,je,ans,an,anoans;
int abs(int a)
{
	if (a<0) return 0-a-an;
	else return a-an;
}
int mi(int a,int b)
{
	if (a>b) return b;
	else return a;
}
int ma(int a,int b)
{
	if (a<b) return b;
	else return a;
}
void qs(int l,int h)
{
	int i=l,j=h,m1=f[(l+h)/2],m2=bt[(l+h)/2],t;
	if (l>=h) return;
	do
	{
		while (bt[i]<m1||bt[i]==m1&&f[i]>m2) i++;
		while (bt[j]>m1||bt[j]<m1&&f[j]<m2) j--;
		if (i<=j)
		{
			t=bt[i];bt[i]=bt[j];bt[j]=t;
			t=f[i];f[i]=f[j];f[j]=t;
			i++;j--;
		}
	}
	while (i<=j);
	qs(i,h);
	qs(l,j);
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	i=1;
	scanf("%d%d",&a[i],&b[i]);
	if (b[i]>0) ans+=b[i];
	anoans+=b[i];
	an=ma(an,abs((a[i]-a[i-1])-d));
	if (ans>k) ans=k;
	for (i=2;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if (b[i]>0) ans+=b[i];
		anoans+=b[i];
		if (b[i-1]<0)
		{
			j++;
			bt[j]=abs((a[i]-a[i-1])-d);
			f[j]=b[i];
		}
		else
		an=ma(an,abs((a[i]-a[i-1])-d));
		if (ans>k) ans=k;
		if (anoans>k) anoans=k;
	}
	if (ans<k)
	{
		printf("-1");
		return 0;
	}
	if (anoans==k)
	{
		printf("%d",an);
		return 0;
	}
	ans=anoans;
	je=j;
	qs(1,je);
	j=1;
	while (bt[j]<=an&&ans<k)
	{
		ans-=f[j];
		if (ans>k) ans=k;
		j++;
	}
	if (ans==k)
	{
		printf("%d",an);
		return 0;
	}
	anoans=ans;
	for (i=j;i<=je;j++)
	if (i!=j||bt[i]==bt[i-1])
	{
		an=ma(an,bt[i]);
		ans-=f[i];
		if (ans>k)
		{
			printf("%d",an);
			return 0;
		}
	}
	else
	ans=anoans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	//RP++
}
