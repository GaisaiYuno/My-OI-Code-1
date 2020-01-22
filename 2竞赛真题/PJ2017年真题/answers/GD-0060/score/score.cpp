#include<cstdio>
#include<math.h>
int a,b,c,tot;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	tot=round(a*0.20+b*0.30+c*0.50);
	printf("%d",tot);
	return 0;
	
}
/*ac*/
