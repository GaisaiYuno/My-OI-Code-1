#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,s=0,x,y,z;
	cin>>a>>b>>c;
	x=a/10*2;
	y=b/10*3;
	z=c/10*5;
	s=x+y+z;
	cout<<s<<endl;
	return 0;
}
