#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
//	freopen("score.in","r",stdin);
//	freopen("score.out","w",stdout);
	int a[3],ans;
	cin>>a[0]>>a[1]>>a[2];
	a[0]*=0.2;
	a[1]*=0.3;
	a[2]*=0.5;
	ans=a[0]+a[1]+a[2];
	if(a[1]==0)
	cout<<ans;
	else
	cout<<ans+1;
	return 0;
}
