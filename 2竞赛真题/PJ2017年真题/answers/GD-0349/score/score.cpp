#include<iostream>
#include<cstdio>
using namespace std;
double a,b,c,g;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	g=a*0.2+b*0.3+c*0.5;
	printf("%0.0f",g);
	return 0;
}
