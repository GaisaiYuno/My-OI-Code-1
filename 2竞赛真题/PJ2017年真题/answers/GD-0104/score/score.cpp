#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	int d=a*0.2+b*0.3+c*0.5+0.1;
	cout<<d;
	return 0;
}
