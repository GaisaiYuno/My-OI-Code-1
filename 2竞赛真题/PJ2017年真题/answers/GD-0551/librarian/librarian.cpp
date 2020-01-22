#include<cstdio>
#include<cstring>

int n,m;
struct node{int l,x;char s[1010];}a[1001];


void dfs(int l,int r)
{
	int x=l,y=r,m=a[(x+y)/2].x;
	while(x<=y)
	{
		while(a[x].x<m)x++;
		while(a[y].x>m)y--;
		if(x<=y)
		{
			node t=a[x];a[x]=a[y];a[y]=t;
			x++;y--;
		}
	}
	if(l<y)dfs(l,y);
	if(x<r)dfs(x,r);
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		a[i].x=0;a[i].l=1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i].s+1);
		int len=strlen(a[i].s+1);
		a[i].l=len;
		for(int j=1;j<=len;j++)
		{
			a[i].x=a[i].x*10+a[i].s[j]-'0';
		}
	}
	dfs(1,n);
	//for(int i=1;i<=n;i++)printf("%d %d ",a[i].x,a[i].l );
	for(int i=1;i<=m;i++)
	{
		int len=0;char s1[1010];
		scanf("%d%s",&len,s1+1);
		
		int ff=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j].l<len)continue;
			int f=1;
			for(int k=1;k<=len;k++)
			{
				if(a[j].s[a[j].l-len+k]!=s1[k])
				{
					f=0;break;//printf("11111 ");
				}	
			}
			if(f==1)
			{
				//if(a[j].v==1)
				//{
					printf("%s\n",a[j].s+1);
					ff=1;break;
				//}
			}
		}
		if(ff==0)
		{
			printf("-1\n");
		}
	}
	return 0;
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12
*/

