#include<cstdio>
using namespace std;
int j,k,l,add;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&j,&k,&l);
	add=j*2/10+k*3/10+l*5/10;
	printf("%d",add);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

