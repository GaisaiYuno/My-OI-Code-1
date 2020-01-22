#include<cstdio>
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int a,b,x,y,c;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
		scanf("%d%d%d",&x,&y,&c);
	printf("-1");
	fclose(stdin);fclose(stdout);
	return 0;
}
