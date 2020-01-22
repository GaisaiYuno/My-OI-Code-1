#include<cstring>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a,b,c;

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",a/10*2+b/10*3+c/10*5);
	fclose(stdin);fclose(stdout);
	return 0;
}

