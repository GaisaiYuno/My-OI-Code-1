#include<iostream>
#include<cstdio>
using namespace std;

int a,b,c;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a*2/10;
	b=b*3/10;
	c=c*5/10;
	cout<<a+b+c;
	return 0;
}
