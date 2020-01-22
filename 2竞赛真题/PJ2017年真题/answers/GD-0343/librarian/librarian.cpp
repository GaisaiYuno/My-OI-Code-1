#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
int i,j,k,n,q,a;
string st[1005],sw;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
    	cin>>st[i];
    }
    for(i=1;i<=q;i++)
    {
    	int x=0;
    	string e="";
    	cin>>a>>sw;
    	for(j=1;j<=n;j++)
    	{
    		string s;
    		for(k=st[j].size()-a;k<st[j].size();k++)
    		s+=st[j][k];
    		if (s==sw&&x==0) {e=st[j];x=1;}
    		if (s==sw&&x==1) {if (e.size()>st[j].size()) e=st[j];
			                 if (e.size()==st[j].size()&&e>s) e=st[j];}           
    	}
    	if (x==0) cout<<-1<<endl;else cout<<e<<endl;
    }
	return 0;

}
