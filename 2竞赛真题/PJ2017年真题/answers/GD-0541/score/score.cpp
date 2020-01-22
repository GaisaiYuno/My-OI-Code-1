#include<cstdio>
#define sr c=getchar()
#define input read()
#define pd (c<'0'||c>'9')
using namespace std;
int z,x,q;
int a,b,c;
int ans;
int read()
{
	char c;int d=1,f=0;
	while (sr,pd) if (c=='-') d=-1;f=f*10+c-48;
	while (sr,!pd) f=f*10+c-48;
	return d*f;
}
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	z=input;x=input;q=input;
    a=z*20;b=x*30;c=q*50;
    ans=(a+b+c)/100;
	printf("%d",ans);
	return 0;
}
