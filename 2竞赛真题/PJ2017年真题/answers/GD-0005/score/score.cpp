#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int d=a*2/10+b*3/10+c*5/10;
	printf("%d",d);
	return 0;
}
