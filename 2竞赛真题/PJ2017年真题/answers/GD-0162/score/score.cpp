#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,ss;
int main()
{
	freopen ("score.in","r",stdin);
	freopen ("score.out","w",stdout);
	cin>>a>>b>>c;
	ss+=a*2/10;
	ss+=b*3/10;
	ss+=c*5/10;
	cout<<ss;
	return 0;
}
