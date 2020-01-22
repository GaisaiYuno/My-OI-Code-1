#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	int ans=a*2/10+b*3/10+c*5/10;
	if(ans>100)cout<<100;
	else cout<<ans;
	return 0;
}
