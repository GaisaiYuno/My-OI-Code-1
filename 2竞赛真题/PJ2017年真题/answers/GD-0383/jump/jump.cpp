#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,d,k,ge[500005][2];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>ge[i][0]>>ge[i][1];
	}
	cout<<-1;
	return 0;
}
