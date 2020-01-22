#include<cstdio>	
int n,q;
int li[1010],s[1010],b[1010];
void dfs(int l,int r)
{
	int x=l,y=r,m=s[(l+r)/2];
	while(x<=y)
	{
		while(s[x]<m) x++;
		while(s[y]>m) y--;
		if(x<=y)
		{
			int t=s[x];s[x]=s[y];s[y]=t;
			x++; y--;
		}
	}
	if(l<y) dfs(l,y);
	if(x<r) dfs(x,r);
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);	
	
	for(int i=1;i<=q;i++)
		scanf("%d %d",&li[i],&b[i]);
	dfs(1,n);	//10000
	/*for(int i=1;i<=n;i++) printf("%d ",s[i]);
	printf("\n");*/
	int flag;
	for(int i=1;i<=q;i++)
	{
		flag=0;
		for(int j=1;j<=n;j++)
		{
			int x=s[j],y=b[i],count=0;
			while(x%10==y%10)
			{
				count++;
				x/=10;
				y/=10;
				if(count==li[i])	{ flag=1; printf("%d\n",s[j]); s[j]=-1; break; }
			}
			if(flag==1) break;
		}
		if(flag==0) printf("-1\n");
	}
	return 0;
}

