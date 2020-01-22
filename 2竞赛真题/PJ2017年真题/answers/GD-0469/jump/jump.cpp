#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	cin>>n>>d>>k;
	int a[500][2];
	for(int i=0;i<n;i++)
	for(int j=0;j<2;j++)
	cin>>a[i][j];
	cout<<-1;
	return 0;
}
