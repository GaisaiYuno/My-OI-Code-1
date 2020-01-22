#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
long a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a*=0.2;
	b*=0.3;
	c*=0.5;
	cout<<a+b+c;
	return 0;
}
