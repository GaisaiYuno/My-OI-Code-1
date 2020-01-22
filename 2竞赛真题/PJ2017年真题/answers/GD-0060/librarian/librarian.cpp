#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#define maxn 1050
using namespace std;
int bnum[maxn],rsize[maxn],rnum[maxn];
int mt[maxn];
int n,q;
int sqr(int a,int b)
{
	int tot=1;
	for(;b>0;b--)
		tot*=a;
	return tot;
}
int flag=0;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	int k,i;
	for(k=0;k<n;k++)
		scanf("%d",&bnum[k]);
	for(i=0;i<q;i++)
		scanf("%d %d",&rsize[i],&rnum[i]);
	sort(bnum,bnum+n);
	for(i=0;i<=q;i++)
		mt[i]=sqr(10,rsize[i]);
	sort(bnum,bnum+n);
	for(i=0;i<q;i++)
	{
		for(k=0;k<n;k++)
		{
			if((bnum[k]-rnum[i])%mt[i]==0)
			{
				printf("%d\n",bnum[k]);
				flag++;
				break;
			}
		}
		if(flag==0)
			printf("-1\n");
		flag=0;
		
	}
	return 0;
}

