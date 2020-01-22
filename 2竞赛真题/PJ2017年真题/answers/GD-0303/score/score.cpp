#include<iostream>
#include<fstream>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a*20/100;
	b=b*30/100;
	c=c*50/100;
	cout<<a+b+c<<endl;
	return 0;
}
