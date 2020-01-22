#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c,s;
int main()
{
	freopen ("score.in","r",stdin);
	freopen ("score.out","w",stdout);
	cin>>a>>b>>c;
	s=a*2+b*3+c*5;
	cout<<s/10;
	return 0;
}
