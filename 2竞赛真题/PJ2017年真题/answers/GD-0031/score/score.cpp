#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	double sum;
	cin>>a>>b>>c;
	sum=0.2*a+0.3*b+0.5*c;
	cout<<sum<<endl;
	
	return 0;
}
