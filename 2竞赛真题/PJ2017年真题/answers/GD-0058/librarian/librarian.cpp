#include<cstdio>
#include<algorithm>
using namespace std;
int S[1001],DZ[1001],N,Q,Z[1001];
int find(int a,int b)
{
	int ans=0,minn=10000000,j=1;
	for(int k=1;k<=b;k++)
		j=j*10;
	for(int i=1;i<=N;i++)
	{
		if(S[i]%j==a)
		{
			minn=min(minn,S[i]);
			ans++;
		}
	}
	if(ans==0)
	return -1;
	else
	return minn;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int a;
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++)
	scanf("%d",&S[i]);
	for(int i=1;i<=Q;i++)
	{	scanf("%d%d",&a,&DZ[i]);
	Z[i]=find(DZ[i],a);
	}
	for(int i=1;i<=Q;i++)
	printf("%d\n",Z[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
