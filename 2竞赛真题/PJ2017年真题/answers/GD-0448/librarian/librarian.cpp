#include<cstdio>
#include<algorithm>
using namespace std;
const int p[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int b[1002],l,w,a;
int main()
{
	int n,q,i,j;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for (i=0;i<n;i++)
		scanf("%d",&b[i]);
	sort(b,b+n);
	for (i=0;i<q;i++)
	{
		scanf("%d %d",&l,&w);
		a=-1;
		for (j=0;j<n;j++)
			if (b[j]%p[l]==w) { a=b[j]; break; }
		printf("%d\n",a);	
	}	
	fclose(stdin); fclose(stdout);
	return 0;
}
