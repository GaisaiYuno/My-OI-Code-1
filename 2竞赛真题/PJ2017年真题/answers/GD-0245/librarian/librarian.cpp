#include<cstdio>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,book[1001],q,ws,want,t,wow;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&book[i]);
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n-i;j++)
		{
			if(book[j]>book[j+1])
			{
				t=book[j];
				book[j]=book[j+1];
				book[j+1]=t;
			}
		}
	for(int i=1;i<=q;i++)
	{
		t=0;
		wow=1;
		scanf("%d%d",&ws,&want);
		for(int i=1;i<=ws;i++)
			wow*=10;
		for(int i=1;i<=n;i++)
		{
			if(want==book[i]%wow)
			{
				printf("%d\n",book[i]);
				i=n;
				t=1;
			}
		}
		if(t==0)
			printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
