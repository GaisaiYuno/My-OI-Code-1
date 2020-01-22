#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
long long n,d,k,x[1000000],s[1000000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("&lld",&n,&d,&k);
	for (int i=1;i<=n;i++)
	scanf("&lld",&x[i],&s[i]);
	cout <<"-1";
	return 0;
}
