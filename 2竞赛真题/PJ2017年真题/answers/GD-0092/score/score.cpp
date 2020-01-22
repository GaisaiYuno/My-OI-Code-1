#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int h,a,b,c;
	double d;
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	d=a*0.2+b*0.3+c*0.5;
	h=d/1;
	cout<<h;	
	return 0;
}
