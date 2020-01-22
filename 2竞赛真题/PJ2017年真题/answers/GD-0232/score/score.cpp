#include <cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	printf("%d",A/10*2+B/10*3+C/10*5);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
