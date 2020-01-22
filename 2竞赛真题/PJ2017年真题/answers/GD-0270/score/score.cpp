#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	a/=10;
	b/=10;
	c/=10;
	a*=2;
	b*=3;
	c*=5;
	cout<<a+b+c;
	return 0;
}
