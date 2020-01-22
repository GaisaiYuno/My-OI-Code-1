#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	int A,B,C,n;
	scanf("%d%d%d",&A,&B,&C);
	n=A/10*2+B/10*3+C/10*5;
	printf("%d",n);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
