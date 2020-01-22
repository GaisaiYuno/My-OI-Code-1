#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
long long n,m,k,t,o,p;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	t=n*2/10+m*3/10+k*5/10;
	printf("%lld",t);
	return 0;	
}
