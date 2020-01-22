#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;
int n,q,msy;
string st[1000+10],reader;
string t,tt;
bool b=false;
void px()
{
	for (int i=1;i<n;i++)
	  for (int j=i+1;j<=n;j++)
	    {
	    	t=st[i];
	    	tt=st[j];
	    	if (t.size()>tt.size()) swap(st[i],st[j]);
	    	if (t.size()==tt.size())
	          if (tt<t) swap(st[i],st[j]);
		}
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	  cin>>st[i];
    px();
	for (int i=1;i<=q;i++)
	  {
	  cin>>msy;
	  cin>>reader;
	  b=false;
	    for (int i=1;i<=n;i++)
	      if (st[i].find(reader,0)!=-1)
		  if (st[i].find(reader,0)==st[i].size()-reader.size())
		    {cout<<st[i]<<endl; b=true; break;}
	  if (b==false) cout<<-1<<endl;
	  }
	return 0;
}
