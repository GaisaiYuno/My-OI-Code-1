#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int s,a,b,c;
	cin>>a>>b>>c;
	a=a/10;
	b=b/10;
	c=c/10;
	a=a*2;
	b=b*3;
	c=c*5;
	s=a+b+c;
	cout<<s;
	return 0;
}
