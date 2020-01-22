#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int a,b,c,s;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a/10*2;
	b=b/10*3;
	c=c/10*5;
	s=a+b+c;
	cout<<s;
	return 0;
}
