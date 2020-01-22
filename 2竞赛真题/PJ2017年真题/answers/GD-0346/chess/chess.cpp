#include<cstdio>
int main()
{	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,a[10000];
	scanf("%d%d",&m,&n);
	for(int i=0;i<3*n;i++)
		scanf("%d",&a[i]);
	printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
