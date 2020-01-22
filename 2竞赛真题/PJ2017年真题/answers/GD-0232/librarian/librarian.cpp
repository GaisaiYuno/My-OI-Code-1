#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	int i,j,l,k,n,q,kk[1001],ii[1001],tsmn[1001];
	char xqm[1001][8],tsm[1001][8];
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%s",tsm[i]);
		kk[i]=strlen(tsm[i]);
		k=1;tsmn[i]=0;
		for(j=kk[i]-1;j>=0;j--)
		{
			tsmn[i]+=(tsm[i][j]-'0')*k;
			k*=10;
		}
	}
	for(i=0;i<q;i++)
		scanf("%d %s",ii[i],xqm[i]);
	sort(tsmn+0,tsmn+n);
	for(i=0;i<n;i++)
	{
		k=i;
		while(k>0)
		{
			kk[i]++;
			k=k/10;
		}
		k=1;
		for(j=kk[i]-1;j>=0;j++)
		{
			k*=10;
			tsm[i][j]=j%k/(k/10);
		}
	}
	for(i=0;i<q;i++)
	{
		for(j=0;j<n;j++)
		{
			for(l=kk[j]-ii[i];l<kk[j];l++)
				if(tsm[j][l]!=xqm[i][l])
					break;
			if(l>=kk[j]) 
			{
				printf("%s\n",tsm[j]);
				break;
			}
		}
		if(j>=n) printf("-1");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
