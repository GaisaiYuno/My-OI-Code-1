#include<cstdio>

inline int getint()
{
	int r=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
		f=c=='-'?-f:f,c=getchar();
	while (c>='0'&&c<='9')
		r=(r<<3)+(r<<1)+(c^'0'),c=getchar();
	return r*f;
}
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	printf("%d\n",getint()/10*2+getint()/10*3+getint()/10*5);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
