#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node
{
	int c,len,a[4100];
}f[4100];int as[410000],max;
int slen[4100],s[4100];
int mymax(int x,int y){return x>y?x:y;}
int cmp(const void *xx,const void *yy)
{
	node n1=*(node *)xx;
	node n2=*(node *)yy;
	if(n1.len<n2.len)return -1;
	else if(n1.len>n2.len)return 1;
	if(n1.c>n2.c)return 1;
	else return -1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,p;scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i].c);
	}
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d",&slen[i],&s[i]);
		max=mymax(max,slen[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int x=f[i].c;
		f[i].len=0;
		while(f[i].len<=max)
		{
			f[i].a[++f[i].len]=x%10;
			x=x/10;
		}
	}
	qsort(f+1,n,sizeof(node),cmp);
	for(int k=1;k<=p;k++)
	{
		for(int i=1;i<=slen[k];i++){as[i]=s[k]%10;s[k]/=10;}
		int m=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i].len<slen[k])continue;
			int t=1;
			for(int j=1;j<=slen[k];j++)
			{
				if(f[i].a[j]!=as[j])
				{
					t=0;
					break;
				}
			}
			if(t==1)
			{
				m=1;printf("%d\n",f[i].c);
				break;
			}
		}
		if(m==0)printf("-1\n");
	}
	return 0;
}
