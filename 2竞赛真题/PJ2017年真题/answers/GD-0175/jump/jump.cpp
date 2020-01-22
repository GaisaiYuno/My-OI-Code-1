#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 1<<29
using namespace std;

int ans,n,d,k,x[1000],s[1000],p[1000],i,l,r,mid,kkk=0;

int work(int dis)
{
	int x=0,sum=0,fw=0,i,ans=0;
	if (dis<d) fw=d-dis; else fw=1;
	while (x<n)
	{
		int Max=-INF,pos=0,sum=0;
		for (i=x+1; i<=n; i++)
		{
			sum+=p[i];
			if (sum>dis+d) break;
			if (s[i]>0) {pos=i;Max=s[i];break;}
			if (s[i]>Max && sum>=fw) {Max=s[i];pos=i;}
		}
		ans+=Max;x=pos;
	}
	if (ans>=k)
	{
		kkk=1;
		return 1;
	}else return 0;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (i=1; i<=n; i++) scanf("%d%d",&x[i],&s[i]),p[i]=x[i]-x[i-1];
	l=1;r=x[n]-d;
	while (l<r)
	{
		mid=(l+r)>>1;
		if (work(mid)==1) r=mid; else l=mid+1;
	}
	if (kkk==0) printf("-1\n");else printf("%d\n",l);
	fclose(stdin);fclose(stdout);
	return 0;
}
