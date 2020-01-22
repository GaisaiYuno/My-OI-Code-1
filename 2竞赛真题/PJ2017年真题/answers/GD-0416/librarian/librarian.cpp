#include<cstdio>
#include<cstring>
using namespace std;
int n,q,m=0;
char Book[1002];
struct Library
{
	int l=0;
	char nb[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
}r[1002],b[1002];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	getchar();
	for (int i=1;i<=n;i++)
	{
		for (b[i].l=1;;b[i].l++)
		{
			scanf("%c",&b[i].nb[b[i].l]);
			if (b[i].nb[b[i].l]=='\n')
			{
				b[i].l--;
				break;
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&r[i].l);
		getchar();
		for (int k=1;k<=r[i].l;k++) scanf("%c",&r[i].nb[k]);
	}
	for (int i=1;i<=q;i++)
	{
		for (int k=1;k<=n;k++)
		{
			int j;
			if (b[k].l<r[i].l) continue;
			for (j=b[k].l-r[i].l+1;j<=b[k].l;j++)
			{
				if (b[k].nb[j]!=r[i].nb[j-b[k].l+r[i].l]) break;
			}
			if (j==(b[k].l+1))
			{
				if (m==0) m=k;
				else
				{
					if ((b[k].l==b[m].l)&&(strcmp(b[m].nb,b[k].nb)>0)) m=k;
					else if (b[m].l>b[k].l) m=k;
				}
			}
		}
		if (m!=0) for (int p=1;p<=b[m].l;p++) printf("%c",b[m].nb[p]);
		else printf("-1");
		printf("\n");
		m=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
