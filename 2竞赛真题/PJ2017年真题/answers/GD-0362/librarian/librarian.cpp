#include<cstdio>

using namespace std;

int n,q;
int books[1005],readers,numlen,index;
int mul[10];

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);	
	
	books[0] = 10000005;
	mul[0] = 1;
	for (int i = 1; i < 10 ; i++) mul[i] = mul[i - 1] * 10;
	
	scanf("%d %d",&n,&q);
	for (int i = 1; i <= n; i++) scanf("%d",&books[i]);
	for (int i = 0; i < q; i++) 
	{
		scanf("%d %d",&numlen,&readers);
		index = 0;
		for (int j = 1; j <= n; j++)
		 if (books[j] % mul[numlen] == readers && books[j] < books[index]) 
		  index = j;
		if (index == 0) printf("-1\n");
		else printf("%d\n",books[index]);
	}
	return 0;
}
