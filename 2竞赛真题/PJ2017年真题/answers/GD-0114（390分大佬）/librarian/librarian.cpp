#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[1100];
int b[1100],c[1100];
int cmp(const void *xx,const void *yy)
{
	int n1=*(int *)xx;
	int n2=*(int *)yy;
	if(n1>n2) return 1;
	else return -1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&b[i],&c[i]);
	}
	qsort(a+1,n,sizeof(int),cmp);
	for(int i=1;i<=q;i++)
	{
		bool bk=false;int d=1;
		for(int j=1;j<=b[i];j++)
		{
			d*=10;
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]%d==c[i])
			{
				printf("%d\n",a[j]);
				bk=true;
				break;
			}
		}
		if(bk==false)
		{
			printf("-1\n");
		}
	}
	return 0;
}
