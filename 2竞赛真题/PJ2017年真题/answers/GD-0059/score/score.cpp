#include<iostream>
#include<cstdio>
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
	int sum=a*2+b*3+c*5;
	cout<<sum;
	return 0;
}
