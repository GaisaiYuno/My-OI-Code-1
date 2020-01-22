#include <iostream>
#include <cstdio>
using namespace std;
	int a,b,c,sco=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);

	cin>>a>>b>>c;
	sco=a*0.20+b*0.30+c*0.50;
	cout<<sco;
	return 0;
}
