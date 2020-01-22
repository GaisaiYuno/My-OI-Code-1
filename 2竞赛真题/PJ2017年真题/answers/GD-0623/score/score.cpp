#include<cstdio>
#include<cstring>
using  namespace  std;
int  a=0,b=0,c=0,s=0;
int  main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	s=a/10*2+b/10*3+c/10*5;
	printf("%d\n",s);
	return  0;
}

