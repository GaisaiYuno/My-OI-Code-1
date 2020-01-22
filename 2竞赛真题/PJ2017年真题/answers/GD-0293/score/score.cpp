#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double a,b,c;
	cin>>a>>b>>c;
	double sum;
	sum=a*0.2+b*0.3+c*0.5;
	cout<<sum<<endl;
	return 0;
}
