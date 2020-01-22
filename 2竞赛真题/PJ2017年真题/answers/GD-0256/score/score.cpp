#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double a,b,c,ans;
	scanf("%lf%lf%lf",&a,&b,&c);
	ans=a*0.2+b*0.3+c*0.5;
	printf("%d",int(ans));
	return 0;
}
