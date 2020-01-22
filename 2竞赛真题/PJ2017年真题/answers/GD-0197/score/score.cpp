#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
float a,b,c,s;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%f%f%f",&a,&b,&c);
	s=a*0.2+b*0.3+c*0.5;
	cout<<s;
	return 0;
}
