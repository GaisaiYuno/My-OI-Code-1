#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<string>
#include<cstring>
using namespace std;
long n,q,s1i[1005],b[1005],o,abc;
string s[1005],s1[1005];
string cs(long cc)
{
	string a,b;
	long t=0;
	while(cc!=0)
	{
		a+=cc%10+'0';
		cc/=10;t++;
	}
	for(int i=t-1;i>=0;i--)
	{b+=a[i];}
	return b;
}
long bs(string cc)
{
	long b=0,t=0;
	while(t<cc.size())
	{
		b=b*10+cc[t]-'0';
		t++;
	}
	return b;
}
string as(long ii,long a,long b)
{
	string ans;
	for(int i=a;i<=b;i++)
	{ans+=s[ii][i];}
	return ans;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	for(int i=1;i<=q;i++)
	cin>>s1i[i]>>s1[i];
	for(int i=1;i<=n;i++)
	b[i]=bs(s[i]);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	s[i]=cs(b[i]);
	for(int j=1;j<=q;j++)
	{
		o=0;
		for(int i=1;i<=n;i++)
		{
		if(s1i[j]>=s[i].size())abc=0;
		else abc=s[i].size()-s1i[j];
		if(as(i,abc,s[i].size()-1)==s1[j]){cout<<s[i]<<endl;o=1;break;}
	}
		if(o==0)cout<<"-1\n";
	}
	return 0;
}

