#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,b[15],f,l;
string st,ss,mi;
char ch;
struct library
{
	int l;
	string st;
} a[1005];
string min(string st,string ss)
{
	if (st.size()<ss.size()) return st;
	if (ss.size()<st.size()) return ss;
	if (st==ss) return st;
	for (int i=0;i<st.size();i++)
	{
		if (st[i]<ss[i]) return st;
		if (st[i]>ss[i]) return ss;
	}
}
bool cmp(library a,library b)
{
	if (a.l!=b.l) return a.l<b.l;
	else return a.st<b.st;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	ch=getchar();
	for (int i=1;i<=n;i++)
	{
		getline(cin,st);
		a[i].st=st;
		a[i].l=st.size();
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&l);
		ch=getchar();
		getline(cin,st);
		mi="999999999";
		for (int j=1;j<=n;j++)
		{
			f=1;
			for (int k=a[j].l-l;k<a[j].l;k++)
			  ss=ss+a[j].st[k];
			if (ss==st) mi=min(mi,a[j].st);
			ss="";
		}
		if (f==0||mi=="999999999") cout<<-1<<endl;
		else cout<<mi<<endl;
		f=0;
	}
	return 0;
}
