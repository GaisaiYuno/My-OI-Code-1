#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n,q,i,j,k,x,o,s[10000],a2[10000],s2,mi=999999999;
string a[10000],b,st;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++) 
	{
		cin>>a[i];
		s[i]=a[i].size();
		x=1;for (j=s[i]-1;j>=0;j--) {a2[i]+=(a[i][j]-48)*x;x*=10;}
	}
	for (i=1;i<=q;i++) 
	{	
		cin>>o; cin>>b;
		s2=b.size();mi=999999999;
		for (j=1;j<=n;j++)
		{
			st="";
			for (k=s[j]-s2;k<s[j];k++) st=st+a[j][k];
			if (b==st) if (a2[j]<mi) mi=a2[j]; 
		}
		if (mi!=999999999) cout<<mi<<endl; else cout<<-1<<endl;
	}
}
