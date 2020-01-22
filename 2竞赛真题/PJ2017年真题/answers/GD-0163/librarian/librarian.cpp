#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int n,q,len[1000+5],f,t;
string a[1000+5],b[1000+5];
char ch;
bool cmp(string x,string y)
{
	if (x.size()!=y.size()) return x.size()<y.size();
	else return x<y;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	cin>>n>>q;
	ch=getchar();
	for (int i=1;i<=n;i++) getline(cin,b[i]);
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=q;i++)
	{
		cin>>len[i];
		cin>>a[i];
		ch=getchar();
		t=-1;
		bool p=true;
		for (int j=1;j<=n;j++)
		  if (b[j].size()>=len[i])
		  {
		  	f=0;p=true;
		  	for (int k=b[j].size()-len[i];k<b[j].size();k++)
		  	{
		  	  if (a[i][f]!=b[j][k]) {p=false;break;}
		  	  f++;
		    }
		    if (p==true) {t=j;break;}
		  }
		if (p==true) cout<<b[t]<<endl; else cout<<-1<<endl;
	}
	return 0;
}
