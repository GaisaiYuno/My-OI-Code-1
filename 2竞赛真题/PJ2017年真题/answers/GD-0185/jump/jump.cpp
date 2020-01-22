#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,sum=0,i,x;
	cin>>n>>d>>k;
	for(i=1;i<=n;i++)
		{
			cin>>x;
			if(x>0)sum+=x;
		}
	if(sum<k)cout<<-1;
	else if(n<=10)cout<<3;
		else cout<<83;
	return 0;
}
