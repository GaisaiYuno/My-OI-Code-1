#include<iostream>
#include<fstream>
using namespace std;
double a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a*0.2;
	b=b*0.3;
	c=c*0.5;
	cout<<a+b+c;
}
