#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int a,b,c,s,aa,bb,cc;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	aa=a*20/100;
	bb=b*30/100;
	cc=c*50/100;
	s=aa+bb+cc;
	printf("%d",s);
	return 0;
}
