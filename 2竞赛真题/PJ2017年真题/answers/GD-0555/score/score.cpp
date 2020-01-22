#include<iostream>
#include<cstdio>
using namespace std;
double a,b,c,sum;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	sum+=a*0.2;
	sum+=b*0.3;
	sum+=c*0.5;
	cout<<sum;
	return 0;
}
