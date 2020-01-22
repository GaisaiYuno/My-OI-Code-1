#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[1005],d[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int n,q,b,c;
bool qw;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=q;i++)
	  {
	    cin>>b>>c;
	    qw=false;
	    for (int j=1;j<=n;j++)
	      if (a[j]%d[b]==c) 
	        {
	        	cout<<a[j]<<endl;
	        	qw=true;
	        	break;
	        }
	    if (!qw) cout<<-1<<endl;
      }
    return 0;
}
