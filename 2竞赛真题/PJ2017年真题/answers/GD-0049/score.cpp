#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int A,B,C,ZF;
	scanf("%d%d%d",&A,&B,&C);
	ZF=A/5+B*3/10+C/2;
	printf("%d",ZF);
	return 0;
}
