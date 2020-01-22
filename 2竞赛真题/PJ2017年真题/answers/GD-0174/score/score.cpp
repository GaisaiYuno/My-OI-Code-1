#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
double a,b,c,aa,bb,cc;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	aa=a*0.2;
	bb=b*0.3;
	cc=c*0.5;
	cout<<aa+bb+cc;
}
