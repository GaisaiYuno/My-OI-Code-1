#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c;
double d;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	d=a*0.2+b*0.3+c*0.5;
	printf("%d",(int)d);
	fclose(stdin);
	fclose(stdout);
	return 0;
	//RP++
}
