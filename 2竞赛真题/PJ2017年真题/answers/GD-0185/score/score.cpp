#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double a,b,c,sum;
	cin>>a>>b>>c;
	sum=a*0.2+b*0.3+c*0.5;
	cout<<sum;
	return 0;
}
