#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,p;
double ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	ans=n*0.2+m*0.3+p*0.5;
	printf("%d",(int)ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
