#include<stdio.h>
int n,d,i,book[1005],len,que;
long long int tenpow(long long int b)
{
	long long int c=10;
	for(long long int i=2;i<=b;i++)
		c*=10;
	return c;
}
long long int look(long long int len,long long int ques)
{
	long long int Moha=tenpow(len);
	long long int mi=20000000;
	for(long long int i=1;i<=n;i++)
		if(book[i]%Moha==ques&&book[i]<mi)
			mi=book[i];
	if(mi==20000000)
		return -1;
	return mi;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++)
		scanf("%d",&book[i]);
	for(i=1;i<=d;i++)
		{
			scanf("%d%d",&len,&que);
			printf("%d\n",look(len,que));
		}
	return 0;
}
