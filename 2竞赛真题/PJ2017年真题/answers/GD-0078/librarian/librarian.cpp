#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long int m,n,Book[1000],RLong[1000],RBM[1000];
int main()
{
	freopen("librarian.in","w",stdin);
	freopen("librarian.out","r",stdout);
	long int k,len[1000],minn=10000001,Result[1000],Mi[1000];
	scanf("%ld%ld",&m,&n);
	for(int i=0;i<m;i++) scanf("%ld",&Book[i]);
	for(int i=0;i<n;i++) scanf("%ld%ld",&RLong[i],&RBM[i]);
	for(int i=0;i<n;i++)
	{
		Mi[i]=1;
		k=RLong[i];
		while(k!=0)
		{
			Mi[i]*=10;
			k--;
		}
	}
	long int w;
	for(int i=0;i<n;i++)
	{
		k=Book[i];
		len[i]=0;
		while(k!=0)
		{
			len[i]++;
			k/=10;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(len[j]>=RLong[i])
			{
				if(Book[j]<minn&&Book[j]%Mi[j]==RBM[i])
				minn=min(minn,Book[j]);
			}
		}
	    if(minn<10000001) Result[i]=minn;
	    else Result[i]=-1;
	    minn=10000001;
	    printf("%ld\n",Result[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
