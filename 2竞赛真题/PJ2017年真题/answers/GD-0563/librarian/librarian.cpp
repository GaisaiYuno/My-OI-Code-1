#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,p;
int books[1100];
int ans[1100];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=1100;++i) ans[i-1]=-1;
	for(int i=1;i<=n;++i) scanf("%d",&books[i]);
	sort(books+1,books+n+1);
	for(int i=1;i<=p;++i)
	{
		int l,num,x=1;
		scanf("%d%d",&l,&num);
		for(int j=1;j<=l;++j)
			x*=10;
		for(int j=1;j<=p;++j)
			if(books[j]%x==num)
			{
				ans[i]=books[j];
				break;
			}
	}
	for(int i=1;i<=p;++i)
		printf("%d\n",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
