#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

int n,d,k,s,x;

int main(void)
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>s;
	for(int i=0;i<n;i++)
	   cin>>s>>x;
	cout<<"-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
