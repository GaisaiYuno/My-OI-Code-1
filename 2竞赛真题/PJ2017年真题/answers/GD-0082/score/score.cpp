#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	long long ans=0,a=0,b=0,c=0;
	scanf("%d%d%d",&a,&b,&c);
	ans=a/10*2+b/10*3+c/10*5;
	printf("%d",ans);
	return 0;
}
