#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,i,j,k;
long long t[10],a[1005],b,c;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	t[1]=10;t[2]=100;t[3]=1000;t[4]=10000;t[5]=100000;t[6]=1000000;t[7]=10000000;t[8]=100000000;
	for (i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	for (i=1;i<=m;i++)
	  {
	  	k=0;
	    cin>>b>>c;
	    for (j=1;j<=n;j++)
	      if ((a[j]%t[b])==c) 
	        {
	        	cout<<a[j]<<endl;
	        	k=1;
	        	break;
	        }
	    if (k==0) cout<<-1<<endl;
	  }
	return 0;
}
