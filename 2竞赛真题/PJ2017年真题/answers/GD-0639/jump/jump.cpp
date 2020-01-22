#include<cstdio>
#include<iostream>
using namespace std;
inline int getint()
{
	int r=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
		f=c=='-'?-f:f,c=getchar();
	while (c>='0'&&c<='9')
		r=(r<<3)+(r<<1)+(c^'0'),c=getchar();
	return r*f;
}
int f[500001],x[500001],s[500001],n,d,k;
bool check(int g)
{
	int j,cnt=0,temp;
	f[1]=s[1];
	for (int i=2;i<=n;++i)
	{
		f[i]=s[i],temp=0;
		for (j=i-1;x[i]-x[j]<max(1,d-g)&&j>=1;--j);
		for (;x[i]-x[j]<=d+g&&j>=1;--j)
			temp=max(temp,f[j]);
		f[i]+=temp;
		cnt=max(cnt,f[i]);
	}
	return cnt>=k;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=getint(),d=getint(),k=getint();
	int l=0,r,t1=0x7fffffff,t2=-0x7fffffff,mid;
	for (int i=1;i<=n;++i)
		x[i]=getint(),s[i]=getint(),t1=min(t1,x[i]),t2=max(t2,x[i]);
	r=t2-t1;
	while (l<=r)
	{
		mid=l+r>>1;
		if (check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	if (l+1<t2-t1)
		printf("%d\n",l+1);
	else
		puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
