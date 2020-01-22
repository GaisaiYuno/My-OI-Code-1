#include<iostream>
#include<stdio.h>
using namespace std;
long long a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a/=10;
	b/=10;
	c/=10;
	cout<<a*2+b*3+c*5;
	return 0;
}
