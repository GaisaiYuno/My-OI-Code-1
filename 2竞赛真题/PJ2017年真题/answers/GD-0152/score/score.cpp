#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	double d=0;
	cin>>a>>b>>c;
	d=a*2.0/10.0+b*3.0/10.0+c*5.0/10.0;
	cout<<d;
	return 0;
}
