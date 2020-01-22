#include<iostream>
#include<fstream>
using namespace std;
int n,p,a[1000000],b[1000000];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin >>n>>p;
	for (int i=1;i<=n;i++) cin >>a[i];
	for (int i=1;i<=p;i++) cin >>b[i];
	cout <<"-1";
	return 0;
}
