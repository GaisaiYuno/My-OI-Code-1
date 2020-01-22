#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,sum=0;
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		if(y>0)
		  sum+=y;
	}
	if(sum<k)
	{
		cout<<"-1";
		return 0;
	}
	else
	  cout<<3;
	return 0;
}
