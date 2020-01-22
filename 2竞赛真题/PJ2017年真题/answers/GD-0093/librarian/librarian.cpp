#include<cstdio>
#include<algorithm>
int mod[8]={1,10,100,1000,10000,100000,1000000,10000000};
int n,q;
int id[1001];
int search(int x,int y)
{
	for (int i=1;i<=n;i++)
		if (id[i]%mod[x]==y)
			return id[i];
	return -1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int x,y;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&id[i]);
	std::sort(id+1,id+n+1);
	while (q--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",search(x,y));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
