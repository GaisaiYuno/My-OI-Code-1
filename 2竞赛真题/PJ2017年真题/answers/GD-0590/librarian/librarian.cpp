#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,b[1050],x[1050][2];
int ch(int f)
{
	for(int i=0;i<n;i++)
	{
		int l=1;
		for(int j=0;j<x[f][0];j++)l*=10;
		if(b[i]%l==x[f][1])return b[i];
	}
	return -1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	sort(b,b+n);
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&x[i][0],&x[i][1]);
		printf("%d\n",ch(i));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
