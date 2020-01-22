#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,l,ma,le,a[1000+5],k,f,p;
char ch;
string sst,s[1000+5];
struct data 
{int a;string s;};
data st[1000+5];
bool cmp(data a,data b)
{
	return a.s<b.s;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
	   cin>>st[i].s;
	   sst=st[i].s;
	   l=sst.size();
	   ma=max(ma,l);
	}
	for(int i=1;i<=n;i++) 
	{
		sst=st[i].s;
		l=sst.size();
		if(l<ma)
		{
			for(int j=1;j<=ma-l;j++) st[i].s='0'+st[i].s;
		}
		st[i].a=ma-l;
	}
	sort(st+1,st+1+n,cmp);
	for(int i=1;i<=q;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>ch;
			s[i]+=ch;
		}
	}
	for(int i=1;i<=q;i++)
	{
		f=0;
		for(int j=1;j<=n;j++)
		{
			sst=st[j].s;
			p=sst.find(s[i]);
			l=s[i].size();
			le=sst.size();
			if(le>l&&le-p==l) 
			{
			   f=1;
			   for(int z=st[j].a;z<le;z++) cout<<sst[z];
			   cout<<endl;
			   break;
			}
		}
		if(f==0) cout<<-1<<endl;
	}
	return 0;
}
