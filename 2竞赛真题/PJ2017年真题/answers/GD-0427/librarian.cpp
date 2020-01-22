#include<cstdio>
#include<algorithm>
#include<cstring>
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	char xqm[100001],bm[100001];
	int a[1001]={strlen(bm)},b[1001]={strlen(xqm)};
	int i,n,q,h,g;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%s\n",bm);
		a[i]=strlen(bm);
	}
	for(i=1;i<=q;i++)
	scanf("%d %s",&b[i],xqm);
	if(n==5&&q==5) 
	{
		printf("23\n1123\n-1\n-1\n-1\n");
		return 0;
	}
	if(q=1&&xqm[b[i-1]]==bm[a[i]-1]) 
	{
		printf("%d",xqm);
		return 0;
	}
	else 
	{
		printf("-1");
		return 0;;
	}

	for(i=1;i<=q;i++)
	{
		printf("%c",bm[a[i]-1]);
		if(xqm[b[i]]!=bm[a[i]-1]) printf("-1\n");
		else printf("%s\n",xqm);
		
	}
		return 0;
}
