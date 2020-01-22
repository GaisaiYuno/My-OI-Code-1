#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	float a,b,c;
	cin>>a>>b>>c;
	
	int total;
	a=a*0.2;
	b=b*0.3;
	c=c*0.5;
	total=a+b+c;
	cout<<total;
	
	
	
	return 0;
	
	
}
