#include<cstdio>
#include<cstring>
int n,m,a[1010],b[1010],l[1010],l1[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int aaa=a[i];
		l1[i]=0;
		while(aaa!=0)
		{
			aaa/=10;
			l1[i]++;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int shu=10000001;
		scanf("%d %d",&l[j],&b[j]);
		
		for(int i=1;i<=n;i++)
		{
			int bj=0;
			for(int x=1;x<=l[j];x++)
			{
				int aa=a[i],bb=b[j];
				int ch=1;
				for(int y=1;y<x;y++){aa=aa/10; bb=bb/10;}
				aa=aa%10; bb=bb%10;
				if(aa!=bb)
				{
					bj=1;
					break;
				}
			}
			if(bj==0) {if(shu>a[i]) shu=a[i];}
		}
		if(shu!=10000001) printf("%d\n",shu);
		else printf("-1\n");
	}
	return 0;
}
