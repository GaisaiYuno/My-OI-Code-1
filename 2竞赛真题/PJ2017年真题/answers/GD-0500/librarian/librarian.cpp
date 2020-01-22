#include<cstring>
#include<cstdio>

char a[1010][10010];
char st[10010];
int b[1010];

int mymin(int x,int y){return x<y?x:y;}

void zh(int k,int x)
{
	int len=1,s=k;
	while(s>0)
	{
		int v=s%10;
		a[x][len++]=v+'0';
		s/=10;
	}
}

void zh2(int k)
{
	int len=1,s=k;
	while(s>0)
	{
		int v=s%10;
		st[len++]=v+'0';
		s/=10;
	}
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,m;scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&b[i]);zh(b[i],i);}
	while(m--)
	{
		int len,x;scanf("%d %d",&len,&x);zh2(x);
		int ans=999999999;
		for(int i=1;i<=n;i++)
		{
			int tf=true;
			for(int j=1;j<=len;j++)
			{
				if(st[j]!=a[i][j]){tf=false;break;}
			}
			if(tf)ans=mymin(ans,b[i]);
		}
		if(ans==999999999)printf("-1\n");else printf("%d\n",ans);
	}
	return 0;
}
