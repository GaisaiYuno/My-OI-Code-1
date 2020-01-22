#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n,m,ln;string a[1005],s1,s2,Min;char s[100];
string min1(string s,string st)
{
	if (s.size()>st.size())return st;
	if (s.size()<st.size())return s;
	if (s<st)return s;else return st;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		a[i]=s;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d %s",&ln,s);
		s1=s;Min="zzzzzzzzzzzz";int z=0;
		for (int j=1;j<=n;j++)
		if (a[j].size()>=ln)
		{
			s2="";
			for (int k=a[j].size()-ln;k<a[j].size();k++)
			  s2+=a[j][k];
			if (s2==s1){Min=min1(Min,a[j]);z=1;}
		}
		if (z==0)printf("-1\n");else cout<<Min<<endl;
	}
	return 0;
}
