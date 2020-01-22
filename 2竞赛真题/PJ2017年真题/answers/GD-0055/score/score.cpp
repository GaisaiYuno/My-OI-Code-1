#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double a,b,c;
	cin>>a>>b>>c;
	a=a/100*20;
	b=b/100*30;
	c=c/100*50;
	cout<<a+b+c<<endl;
	return 0;
}
