#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,ans=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=0;
	ans+=a/10*2;
	ans+=c/10*5;
	ans+=b/10*3;
	cout<<ans;
	return 0;
}
