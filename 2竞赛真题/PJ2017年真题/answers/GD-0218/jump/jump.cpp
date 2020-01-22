#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,s,k,ss,ma,mi,p,c,m,f[500005],a[500005],b[500005];
void hs(int kk,int pp,int cc)
{
	if(kk>n)
	{
		if(s>=k&&(ss<ma||p==0))
		{
			p=1;
			ma=ss;
		}
		return;
	}
	hs(kk+1,pp,cc);
	s=s+b[kk];
	f[kk]=1;
	ss=pp;
	if(a[kk]-c>m&&a[kk]-c-m>ss) ss=a[kk]-c-m;
	if(a[kk]-c<m&&m-(a[kk]-c)>ss) ss=m-(a[kk]-c);
	c=a[kk];
	hs(kk+1,ss,c);
	f[kk]=0;
	s=s-b[kk];
	ss=pp;
	c=cc;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(b[i]>0) s=s+b[i];
		ss=ss+b[i];
		if(a[i]-a[i-1]!=m) p=1;
	}
	if(s<k)
	{
		cout<<"-1";
		return 0;
	}
	if(p==0&&ss>=k) 
	{
		cout<<"0";
		return 0;
	}
	s=0;
	ss=0;
	p=0;
	hs(1,0,0);
	cout<<ma;
	return 0;
}
