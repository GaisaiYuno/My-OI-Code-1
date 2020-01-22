#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	cout<<a*0.2+b*0.3+c*0.5;
	return 0;
}
