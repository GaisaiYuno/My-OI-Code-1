#include <cstdio>
using namespace std;
int A,B,C;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	printf("%d",A/5+B/10*3+C/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
