#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int ans=0;
	int a,b,c;
	cin>>a>>b>>c;
	ans=ans+(a*2/10);
	ans=ans+(b*3/10);
	ans=ans+(c*5/10);
	cout<<ans<<endl;
	return 0;
}
