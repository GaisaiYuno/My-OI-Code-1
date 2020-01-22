#include<iostream>
#include<cstdio>
using namespace std;
int a;
double ans=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d",&a);
	ans+=a*0.2;
	scanf("%d",&a);
	ans+=a*0.3;
	scanf("%d",&a);
	ans+=a*0.5;
	int m=ans;
	printf("%d",m);
	return 0;
}
