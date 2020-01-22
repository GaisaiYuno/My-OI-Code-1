#include<cstdio>
#include<iostream>
using namespace std;
int l[100001],a[100001],n,d,k,f1,f2,f3,w1,w2;
void cmain(int i)
{
	w1=0;
	w2=0;
	f2=0;
	f1=0;
	f3=0;
	for (int j=1;j<=n;j++)
	{
		if (l[j]>=w1+max(1,d-i) && l[j]<=w1+d+i) {f1+=a[j];w1=l[j];}
		if (l[j]>=w2+max(1,d-i) && l[j]<=w2+d+i && a[j]>=0) {
			f2+=a[j];w2=l[j];
			if (f2>f1)
			{
				f1=f2;
				w1=w2;
			}
		}
		else if(l[j]<w2+max(1,d-i) || l[j]>w2+d+i) {w2=w1;f2=f1;}
		f3=max(max(f1,f2),f3);
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);	
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&a[i]);
	for (int i=1;i<=l[n];i++)
	{
		cmain(i);
		if (f3>=k) {printf("%d",i); return 0;}
	}
	printf("-1");
	return 0;
}
