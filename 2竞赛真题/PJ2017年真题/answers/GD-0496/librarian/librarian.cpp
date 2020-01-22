#include<cstdio>
#include<algorithm>
using namespace std;
int book[1000],need[1000],len[1000],k=0;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	scanf("%d%d", &n, &q);
	for(int i=0;i<n;i++)
	scanf("%d", &book[i]);
	for(int i=0;i<q;i++)
	{
		scanf("%d%d", &len[i],&need[i]);
	}
	sort(book,book+q-1);
	while(k<q)
	{
		
		int ans=1,count=-1;
		for(int i=0;i<len[k];i++)
		ans*=10;
		for(int i=0;i<n;i++)
		{
			if((book[i]%ans)==need[k])
			{
				count=book[i];
				break;
			}	
		}
		printf("%d\n", count);
		k++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
