#include<cstdio>
#include<cstdlib>
#include<cstring>
int n,q;
int a[1010];
char s[110];
int ans;

void qsort(int l,int r)
{
	int i,j,m,t;
	i=l;j=r;
	m=a[(l+r)/2];
	while (i<=j)
	{
		while (a[i]<m) i++;
		while (a[j]>m) j--;
		if (i<=j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			i++,j--;
		}
	}
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}

bool pd(int l)
{
	int z=0,t=1;
	for (int i=0;i<l;i++)
	{
		z=z*10+s[i]-'0';
		t=t*10;
	}
	for (int i=1;i<=n;i++)
		if (a[i]%t==z)
		{
			ans=i;
			return true;
		}
	return false;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	qsort(1,n);
	int l;
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&l);
		scanf("%s",s);
		if (pd(l)==false) printf("-1\n");
		else printf("%d\n",a[ans]);
	}
	return 0;
}
/*
10 10
1
2
3
4
5
6
7
8
9
10
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
2 10 
*/
