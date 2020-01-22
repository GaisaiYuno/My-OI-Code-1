#include <iostream>
#include  <cstdio>
using namespace std;
int a,b,c,l,k,o,a1,b1,c1;
int main()
{
	freopen ("score.in","r",stdin);
	freopen ("score.out","w",stdout);
	cin>>a>>b>>c;
	a1=a/10*2;
	b1=b/10*3;
	c1=c/10*5;
	cout<<a1+b1+c1;
	return 0;
}
