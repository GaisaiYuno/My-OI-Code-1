#include<cstdio>
#include<iostream>
#include<cstring>
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",a*2/10+b*3/10+c*5/10);
	return 0;
}
