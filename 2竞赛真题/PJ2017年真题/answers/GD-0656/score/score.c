#include <stdio.h>

int main(void)
{
	int a,b,c;
	
	FILE* pin = fopen("score.in","r");
	FILE* pout = fopen("score.out","w");
	fscanf(pin,"%d%d%d",&a,&b,&c);
	fprintf(pout,"%d",2*a/10 + 3*b/10 + 5*c/10);
	return 0;
}
