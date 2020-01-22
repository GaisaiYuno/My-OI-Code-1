#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,s;
	scanf("%d%d%d",&a,&b,&c);
	a=a/10;
	b=b/10;
	c=c/10;
	a*=2;
	b*=3;
	c*=5;
	s=0;
	s+=a;
	s+=b;
	s+=c;
	printf("%d",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
