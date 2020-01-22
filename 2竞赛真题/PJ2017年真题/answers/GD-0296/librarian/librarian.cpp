#include<cstdio>
#include<cstring>

int a[1010],b[1010],len[10][1010],s[10],ss[10];
//后面一个数组表示第几个数，前面表示第几位 

void dfs(int l,int r)
{
	int x=l,y=r,m=b[(x+y)/2];
	while(x<=y)
	{
		while(b[x]<m) x++;
		while(b[y]>m) y--;
		if(x<=y)
		{
			int t=b[x]; b[x]=b[y]; b[y]=t;
			x++; y--;
		}
	}
	if(x<r) dfs(x,r);
	if(y>l) dfs(l,y);
}

int main()
{
	freopen("librarian.in","r",stdin);
freopen("librarian.out","w",stdout);
	int n,m; scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]); 
	}
	
	dfs(1,n);
	
	//for(int i=1;i<=n;i++) printf("%d\n",b[i]);
	
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i];
		int x=1;
		while(b[i]>0)
		{
			//printf("%d %d\n",b[i],x);
			len[x][i]=b[i]%10;
			b[i]/=10;
			x++;
		}
		len[0][i]=x-1;
	}
	/*
	for(int i=1;i<=n;i++)
	{
		printf("%d ",len[i][0]);
		for(int j=1;j<=len[i][0];j++) printf("%d",len[j][i]);
		printf("\n"); 
	}
	*/
	
	for(int k=1;k<=m;k++)
	{
		int x; scanf("%d",&x);
		for(int i=1;i<=x;i++)
		{
			scanf("%1d",&s[i]);
		}
		int d=0;
		for(int i=x;i>=1;i--)
		{
			d++;
			ss[d]=s[i];
		}
		int f=0,s=0;
		for(int i=1;i<=n;i++)
		{
			//printf("\n");
			if(ss[1]==len[1][i])
			{
				if(len[0][i]>=x)
				{
					f=2;
					for(int j=1;j<=x;j++)
					{
						if(ss[j]!=len[j][i]) { f=1; }
						//printf("%d %d\n",ss[j],len[j][i]);
					}
				}
				
			}
			if(f==2)
			{
				s=1;
				for(int j=len[0][i];j>=1;j--) printf("%d",len[j][i]);
				printf("\n");
				break;
			}
		}
		if(s==0) printf("-1\n");
	}
	return 0;
}
