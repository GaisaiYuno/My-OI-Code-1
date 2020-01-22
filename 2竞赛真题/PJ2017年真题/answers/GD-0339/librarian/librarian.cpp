#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

int n,q;
int book[1001],want,l;
bool check;

int cal(int x,int l)
{
	int c=1;
	for(int k=1;k<=l;k++)
	{
		c=c*10;
	}
	return x%c;
} 

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&book[i]);
	}
	sort(book+1,book+n+1);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&want);
		check=false;
		for(int j=1;j<=n;j++)
		{
			if(cal(book[j],l)==want) 
			{
				printf("%d\n",book[j]);
				check=true;
				break;
			}
		}
		if(check==false) printf("-1\n");
	}
}
