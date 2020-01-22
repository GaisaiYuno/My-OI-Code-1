#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	float a,b,c;
	float count;
	scanf("%f%f%f",&a,&b,&c);
	count=0.2*a+0.3*b+c/2;
	printf("%0.0f",count);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
