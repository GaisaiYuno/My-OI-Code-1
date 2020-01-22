#include<cstdio>
#include<cstdlib>

int n,q;
int a[1010];

int pow(int k) 
{
	int tot=1;
	while (k--) tot*=10;
	return tot;
}

void qsort(int l,int r)
{
	int i=l,j=r;
	int m=a[(l+r)/2];
	int t;
	while (i<=j)
	{
		while (a[i]<m) i++;
		while (a[j]>m) j--;
		if (i<=j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}
	if (i<r) qsort(i,r);
	if (l<j) qsort(l,j);
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	qsort(1,n);
	for (int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int Mod=pow(x);bool tf=true;
		for (int i=1;i<=n;i++)
			if (y==a[i]%Mod)
			{
				printf("%d\n",a[i]);
				tf=false;
				break;
			}
		if (tf) printf("-1\n");
	}
	return 0;
}
