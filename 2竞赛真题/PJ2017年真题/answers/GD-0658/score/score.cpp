#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

double a,b,c,ans,a1,b1,c1;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	cin>>a>>b>>c;
	
	a1=a*0.2;
	b1=b*0.3;
	c1=c*0.5;
	
	cout<<a1+b1+c1<<endl;
	return 0;
}
