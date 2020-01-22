#include<iostream>
#include<cstdio>
#include<cmath>
#include<fstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<iomanip> 
using namespace std;
int a[1020],ans,s1,n,q,s,i,j,l,l1,s2;
string b;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for (i=0;i<q;i++)
	{
		cin>>s>>b;
		s1=1;
		for (j=0;j<n;j++)
		{
			l=a[j];
			l1=s-1;
			do 
			{
				s1=l%10;
				s2=b[l1]-'0';
				if (b[l1]-'0'!=s1) {s1=-1;break;}
				l/=10;
				l1--;
			}
			while (l1>-1);
			if (s1!=-1) {ans=a[j];break;}
		}
		if (s1==-1) cout<<s1<<endl;
			else cout<<ans<<endl;
	}
	
	return 0;
}
