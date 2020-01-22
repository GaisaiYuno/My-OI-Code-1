#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
using namespace std;
long long s[1005],lenb,b,n,m,ans,d,k,z;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin >>n>>m;
    for (int i=1;i<=n;i++)
     {
     	cin >>s[i];
     	d=max(d,s[i]);
     }   
    for (int i=1;i<=m;i++)
     {
     	cin >>lenb>>b;
     	k=1;
     	z=-1;
     	for (int j=1;j<=lenb;j++)
     	 k=k*10;
		ans=d; 
     	for (int j=1;j<=n;j++)
     	 if (s[j]%k==b)
     	  {
     	  	ans=min(ans,s[j]);
     	  	z=1;
     	  }
     	if (z==-1)
     	cout <<z<<endl;
     	else
        cout <<ans<<endl;
     }
	return 0;
}

