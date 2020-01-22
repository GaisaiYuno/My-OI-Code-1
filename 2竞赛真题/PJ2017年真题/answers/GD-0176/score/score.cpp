#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	a=a*0.2;
	b=b*3/10;
	c=c*0.5;
	cout<<a+b+c<<endl;
	return 0;
}
