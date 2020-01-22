#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
/*****************************************/	
	double a,b,c;
	int d;
	cin>>a>>b>>c;
	a=a*0.2;
	b=b*0.3;
	c=c*0.5;
	d=a+b+c;
	cout<<d;
/*****************************************/	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
