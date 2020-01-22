#include<cstdio>
#include<cstring>
char st[1010];
char ss[1010];
int n,q,a[1010],b[1010];
int c[1010],d[1010];
int x[1010],y[1010][1010];
int minn=10000000,anw=0;
int min(int x,int y) {return x<y?x:y;}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(x,0,sizeof(x));
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		scanf("%s",st+1);
		a[i]=strlen(st+1);
		for(int j=1;j<=a[i];j++)
		{
			d[i]=d[i]*10+(st[j]-'0');
		}
		for(int j=1;j<=a[i];j++)
		{
			y[i][j]=st[j]-'0';
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&b[i]);
		scanf("%s",ss+1);
		for(int j=1;j<=b[i];j++)
		{
			x[j]=ss[j]-'0';
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]>=b[i])
			{
				int k=a[j],k1=b[i],ans=0;
				while(k1>0)
				{
					if(y[j][k]==x[k1])
					{
						ans++; 
					}
					k--; k1--;
				}
				if(ans==b[i]) c[j]=d[j];
			}
		}
		minn=10000000,anw=0;
		for(int j=1;j<=n;j++)
		{
			if(c[j]>0)
			{
				minn=min(minn,c[j]);
				anw++;
			}
		}
		if(anw==0)
		{
			printf("-1");
			printf("\n");	
		}
		else printf("%d\n",minn);
		for(int j=1;j<=n;j++) c[j]=0;
	}
	return 0;
}
