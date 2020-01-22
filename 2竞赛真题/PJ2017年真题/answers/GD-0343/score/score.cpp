#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
int a,b,c,a1,a2,a3;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	a1=a/5;
	a2=b*30/100;
	a3=c/2;
	printf("%d",a1+a2+a3);
	return 0;
}
