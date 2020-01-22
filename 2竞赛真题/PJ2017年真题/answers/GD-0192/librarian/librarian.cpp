#include<cstdio>
using namespace std;
int a[1010],s[11];
void qsort(int l,int r)
{
	int i=l,j=r,mid=a[(l+r)/2],t;
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;j--;
		}
	}
	if(i<r) qsort(i,r);
	if(l<j) qsort(l,j);
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,j=0,need,len,k=1;
	bool haveFind_theBook;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	qsort(1,n);
	for(i=0;i<11;i++) s[i]=1;
	for(i=1;i<=n;i++)
	{
		while(a[i]>=k)
		{
			j++;s[j]=i;
			k=k*10;
		}
	}
	while(q--)
	{
		scanf("%d%d",&len,&need);
		if(len==0)
		{
			printf("-1\n");
			continue;
		}
		k=1;haveFind_theBook=false;
		for(i=1;i<=len;i++) k=k*10;
		for(i=s[len];i<=n;i++)
		{
			if(a[i]%k==need)
			{
				haveFind_theBook=true;
				printf("%d\n",a[i]);
				break;
			}
		}
		if(!haveFind_theBook) printf("-1\n");
	}
	return 0;
}
