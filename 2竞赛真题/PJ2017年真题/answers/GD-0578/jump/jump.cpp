#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int w1,g,n,d,k,x,y,a[1000000+5],ma1,ma,s,w,p,p1,q1,q;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		a[x+1]=y;
		ma1=max(ma1,ma1+y);
		ma=max(ma,x+1);
	}
	if (ma1<k) {cout<<-1;return 0;}
	s=0;
	while (w<n)
	{
		s+=a[w];
		if (s>=k) break;
		w+=d;
	}
	if (s>=k) {cout<<0;return 0;}
	s=0;w=0;
	g=1;
	while (g<d)
	{
		p=d-g;q=d+g;
		p1=p;q1=p;
		while (p1<ma)
		{
			w=0;
			for (int i=q1;i<=q1+q+1;i++) 
			if (a[i]>=0&&(i-p1>p||i-p1<q)){w=1;q1=i+1;break;}
			s+=a[q1-1];
			if (s>k){w1=1;break;}
			if (w==0)p1++;
			if (q1>=ma) 
			{
				p1++;q1=p1;
				if (s>=k){w1=1;break;}
				else s=0;
			}
		}
		g++;
		if (w1==1)break;
	}
	if (w1==1) {cout<<g;return 0;}
	w=0;
	while (1)
	{
		p=1;q=d+g;
		p1=p;q1=p;
		while (p1<ma)
		{
			w=0;
			for (int i=q1;i<=q1+q+1;i++) if (a[i]>=0){w=1;q1=i+1;break;}
			s+=a[q1-1];
			if (s>k){w1=1;break;}
			if (w==0)p1++;
			if (q1>=ma) 
			{
				p1++;q1=p1;
				if (s>=k){w1=1;break;}
				else s=0;
			}
		}
		g++;
		if (w1==1)break;
	}
	cout<<s;
	return 0;
}
