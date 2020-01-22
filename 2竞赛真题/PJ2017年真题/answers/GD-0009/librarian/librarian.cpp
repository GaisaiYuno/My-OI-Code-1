#include<cstdio>
#include<cstring>
using namespace std;
int n,q;
int book[2000][50],need[2000][50],num[2000];
bool bz;
void qsort(int l,int r)
{
	int i,j,mid,temp;
	i=l,j=r;
	mid=num[(l+r)/2];
	while(i<=j)
	{
		while(num[i]<mid)i++;
		while(num[j]>mid)j--;
		if(i<=j)
		{
			temp=num[i],num[i]=num[j],num[j]=temp;
			i++,j--;
		}
	}
	if(i<=r)qsort(i,r);
	if(l<=j)qsort(l,j);
}
int pan(int x,int y)
{
	int l=book[x][0],r=need[y][0];
	int t=need[y][0];
	for(int i=0;i<t;i++)
		if(book[x][l-i]!=need[y][r-i])
			return 0;
	return 1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	qsort(1,n);
	for(int i=1;i<=n;i++)
	{
		int t=0,x=num[i];
		int ar[2000];
		while(x/10>0)
		{
			t++;
			ar[t]=x%10;
			x/=10;
		}
		if(x!=0)
		{
			t++;
			ar[t]=x;
		}
		book[i][0]=t;
		for(int j=1;j<=t;j++)
			book[i][j]=ar[t-j+1];
	}
	for(int i=1;i<=q;i++)
	{
		char s[1000];
		int len;
		scanf("%d",&len);
		scanf(" %s",&s);
		need[i][0]=len;
		for(int j=1;j<=len;j++)
			need[i][j]=s[j-1]-'0';
	}
	for(int i=1;i<=q;i++)
	{
		bz=0;
		for(int j=1;j<=n;j++)
		{
			if(book[j][0]>=need[i][0])
			{
				if(pan(j,i)==1)
				{
					printf("%d\n",num[j]);
					bz=1;
					break;
				}
			}
		}
		if(!bz)
		{
			printf("-1\n");
		}
	}
}
