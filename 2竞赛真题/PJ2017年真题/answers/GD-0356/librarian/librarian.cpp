#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,book[1001],book1[1001],need1,need2,ans[1001],counts;

bool my_comp(const int &a,const int &b)
{
	return a<b;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	memset(book1,0,sizeof(book1));
	for(int i=1;i<=n;i++)scanf("%d",&book[i]);
	sort(book+1,book+n+1,my_comp);
	for(int i=1;i<=n;i++)
	{
		need1=book[i];
		while(need1>=10)
		{
			need1/=10;
			book1[i]++;
		}
		book1[i]++;
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&need1,&need2);
		ans[i]=-1;
		for(int j=1;j<=n;j++)
		{
			if(book1[j]==need1&&book[j]==need2)
			{
				ans[i]=book[j];
				break;
			}
			else if(book1[j]>need1)
			{
				counts=1;
				for(int w=1;w<=need1;w++)counts*=10;
				if(book[j]%counts==need2)
				{
				ans[i]=book[j];
				break;
				}
			}
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}
