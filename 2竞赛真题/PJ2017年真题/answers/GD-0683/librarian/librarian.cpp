#include<cstdio>
using namespace std;
int ten(int x)
{
	int ans=1,i;
	for (i=1;i<=x;i++)
	{
		ans=ans*10;
	}
	return ans;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,j,b[1010];
	int l,m,w=0,k=0,min;
	scanf("%d %d",&n,&q);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for (i=1;i<=q;i++)
	{
		k=0;min=2e9;w=0;
		scanf("%d %d",&l,&m);
		for (j=1;j<=n;j++)
		{
			if (b[j]%ten(l)==m) 
			{
				k++;
				if (b[j]<min) min=b[j];
			}
		}
		if (k>0) printf("%d\n",min);
		else printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
