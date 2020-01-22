#include <cstdio>
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int x,y,z;
	double k=0;
	scanf("%d %d %d",&x,&y,&z);
	k=x*0.2+y*0.3+z*0.5;
	printf("%d",(int)k);
	return 0;
}
