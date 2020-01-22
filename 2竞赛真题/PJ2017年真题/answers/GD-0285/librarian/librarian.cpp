#include<cstdio>
#include<cstdlib>
#include<cstring>

int n,q;
char s[1010][12];
char d[1010][12];
int l[1010],v[1010];

int num(char s[10],int l)
{
	int y=0;
	for(int i=1;i<=l;i++)
	{
		y=y*10+s[i]-'0';
	}
	return y;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		v[i]=strlen(s[i]+1);
	}
	for(int i=1;i<=q;i++)
	{
		int len=999999999,ans;bool bj=false;
		scanf("%d %s",&l[i],d[i]+1);
		for(int k=1;k<=n;k++)
		{
			if(v[i]<l[i]) continue;
			int a=l[i];bool tf=true;
			for(int j=v[k];j>=v[k]-l[i]+1;j--)
			{
				if(d[i][a]==s[k][j]) a--;
				else
				{
					tf=false;
					break;
				}
			}
			if(tf)
			{
				bj=true;
				if(v[k]<len)
				{
					len=v[k];
					ans=num(s[k],v[k]);
				}
				if(v[k]==len)
				{
					int b=num(s[k],v[k]);
					if(b<ans)
					{
						len=v[k];
						ans=b;
					}
				}
			}
		}
		if(bj) printf("%d\n",ans);
		else printf("-1\n");
	}
}
