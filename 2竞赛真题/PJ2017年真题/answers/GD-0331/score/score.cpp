#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double a,b,c,s;
	cin>>a>>b>>c;
	a=a*0.2;
	b=b*0.3;
	c=c*0.5;
	s=a+b+c;
	cout<<s;
	return 0;
}
