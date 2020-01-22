#include <iostream>
#include <cstdio>
using namespace std;
long long a[1000000],b[1000],c[1000000],s,i,n,q;
int main()
{
	cin>>n>>q;
	for (i=1;i<=n;i++)
	 	cin>>a[i];
	for (i=1;i<=n;i++)
	 	cin>>b[i]>>c[i];
	for (i=1;i<=n;i++)
	 {
	 	if (a[i]==c[i]) s=a[i];
	 	
	 	
	 	cout<<s;
	 } 
	 	
}
