#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int a,b,c;
double s;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	s=a*0.2+b*0.3+c*0.5;
	if (s>100) printf("100");
	else cout<<(int)s;
	return 0;
}
