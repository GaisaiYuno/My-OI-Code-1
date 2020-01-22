#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
int n,q,p,cd;
long long ts[1005],pd,bm,t;
int main()
{
	freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1; i<=n; i++)
	  cin>>ts[i];
	sort(ts+1,ts+1+n);
	for (int i=1; i<=q; i++)
	{
		p=0;
		cin>>cd>>bm;
		pd=1;
		for (int j=1; j<=cd; j++)
		  pd=pd*10;
		for (int j=1; j<=n; j++)
		{
			t=ts[j]%pd;
			if (t==bm) {cout<<ts[j]<<endl; p=1; break;}
		}
		if (p==0) cout<<-1<<endl;
	}
	return 0;
}
	
