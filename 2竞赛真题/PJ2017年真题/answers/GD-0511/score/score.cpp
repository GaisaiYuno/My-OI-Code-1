#include<cstdio>
using namespace std;
inline int read()
{
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	int x=0;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a=read(),b=read(),c=read();
	int sums=a*2/10+b*3/10+c*5/10;
	printf("%d\n",sums);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
