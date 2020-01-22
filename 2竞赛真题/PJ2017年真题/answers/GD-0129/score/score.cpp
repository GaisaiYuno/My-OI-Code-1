#include<cstring>
#include<string>
#include<fstream>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cwchar>
#include<cwctype>
#include<limits>
using namespace std;
int main()
{
     int a=0,b=0,c=0;
	freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	a=a/10*2;
	b=b/10*3;
	c=c/10*5;
	cout<<a+b+c;
	return 0;
}
