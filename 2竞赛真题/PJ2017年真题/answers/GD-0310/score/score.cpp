#include<cstdio>
using namespace std;
int _ans=0;
int a,b,c;

int main(void)
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	_ans=a*2+b*3+c*5;
	printf("%d\n",_ans/10);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
