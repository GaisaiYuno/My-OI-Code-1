#include<bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=2*a+3*b+5*c;
	ans/=10;
	cout<<ans;
	return 0;
}
