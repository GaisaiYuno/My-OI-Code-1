#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,f,a;
string s[1005],ms,c;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>s[i];
	for (int i=1;i<=m;i++) 
	{
		ms="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";f=0;
		cin>>a>>c;
		for (int j=1;j<=n;j++)
		  {
	        if (a<=s[j].size())
	        {
		  	if (s[j].rfind(c)==s[j].size()-c.size()) 
		  	{
		  	    if (s[j].size()<ms.size()||s[j].size()==ms.size()&&s[j]<ms) ms=s[j];
		  	    f=1;
		    }
		    }
		  }
		if (f==0) cout<<-1<<endl; else cout<<ms<<endl;
	}
	return 0;
}
