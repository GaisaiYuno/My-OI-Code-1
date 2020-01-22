#include<cstdio>
#include<algorithm>
using namespace std;
int Book[1001];
const int INF=10000001;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,len,reader,dsum=0,temp,tsum=0,ans=INF;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&Book[i]);
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&len,&reader);
		ans=INF;
		for(int k=0;k<n;k++)
		{
			dsum=0;
			tsum=0;
			temp=Book[k];
			for(int j=0;j<len;j++)
			{
				tsum=temp%10;
				for(int x=0;x<j;x++)
				{
					tsum*=10;
				}
				dsum+=tsum;
				temp/=10;
			}
			if(dsum==reader) ans=min(ans,Book[k]);
		}
		if(ans==INF) printf("-1\n");
		else printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
