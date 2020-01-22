#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,q,a[1005],b[1005],c[1005],ans,i,j,k;
int sum;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin >> n >> q ; ans=10000005; sum=1;
	for (i=1;i<=n;i++) cin >> a[i] ; 
	for (i=1;i<=q;i++) 
	{
	     cin >> b[i] >> c[i] ;
	     for (int k=1;k<=b[i];k++) sum*=10;
	     for (j=1;j<=n;j++)
	      {
	      	if (a[j]%sum==c[i]) 
	      	   if (a[j]<ans) ans=a[j]; 
	      }
	    if (ans==10000005) cout<< "-1" << endl ;  
	    else cout << ans << endl ; 
		ans=10000005; sum=1;
    }
	return 0; 
}
