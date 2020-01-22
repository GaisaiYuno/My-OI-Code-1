#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a/10*2;
	b=b/10*3;
	c=c/10*5;
	ans=a+b+c;
	cout<<ans;
	return 0;
}
