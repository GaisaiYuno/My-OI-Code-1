#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long n,d,k,l=0,r=0,a[500010],scr[500010],num[500010];
int check(long long g)
{
	memset(num,-127/3,sizeof(num));
	for (int i=1;a[i]<=d+g&&i<=n;++i)
		if (a[i]>=d-g&&a[i]>0)
			num[i]=scr[i];
	for (int i=1;i<=n;++i)
	{
		if (num[i]-k>=0)
			return 1;
		for (int j=i+1;a[j]<=d+g+a[i]&&j<=n;++j)
			if (a[j]>=a[i]+d-g&&a[j]>a[i])
				if (num[j]<num[i]+scr[j])
					num[j]=num[i]+scr[j];
	}
	return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i]>>scr[i];
		
		if (a[i]>r) r=a[i];
	}int flag=1;
	while (l<=r)
	{
		long long mid=l+r>>1;
		if (check(mid)) r=mid-1,flag=0;
		else l=mid+1;
	}
	cout<<(flag?-1:l)<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
