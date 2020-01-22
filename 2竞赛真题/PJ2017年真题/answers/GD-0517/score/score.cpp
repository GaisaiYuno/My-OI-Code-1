#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double a,b,c,ans;
	cin>>a>>b>>c;
	ans=a*20/100+b*30/100+c*50/100;
	printf("%.0lf",ans);
	return 0;
}
