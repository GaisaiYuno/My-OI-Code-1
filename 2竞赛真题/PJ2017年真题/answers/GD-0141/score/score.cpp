#include<iostream>
#include<cstdio>
using namespace std;
double a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	printf("%0.0f",a*0.2+b*0.3+c*0.5);
	return 0;
}
