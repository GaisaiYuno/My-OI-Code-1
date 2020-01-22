#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
string s[1005];
int c[1005],dd[1005],e[1005];
bool cmp(string a,string b)
{
	if (a.size()!=b.size()) return a.size()<b.size();
	if (a.size()==b.size()) return a<b;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int p,flag,n,q,a,b,ns;
	string x;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	   cin>>s[i];
	sort(s+1,s+1+n,cmp);
	int pp=0,t=0;
	for (int i=1;i<=n;i++)
	  {
	  	for (int j=s[i].size()-1;j>=0;j--)
	  	  {
	  	    c[i]=c[i]*10+(s[i][j]-'0');
	  	  }
	  }
	for (int i=1;i<=q;i++)
	  {
	  	int le=0;
	  	flag=0;
	  	ns=0;
	  	cin>>a>>b;
		while (b!=0) ns=ns*10+(b%10),b/=10;
	  	for (int j=1;j<=n;j++)
	  	  {
	  	  	int d=c[j];
	  	  	p=0;
	  	  	while (d!=0)
	  	  	  {
	  	  	 	if (d==ns) {p=1;break;}
	  	  	    d/=10;
	  	  	  }
	  	    if (p==1) {flag=1;cout<<s[j]<<endl;break;}
	  	  }
	  	if (flag==0) cout<<-1<<endl;
	  }
	return 0;
}
