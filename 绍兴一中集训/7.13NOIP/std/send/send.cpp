#include <cctype>
#include <cstdio>
/*
int read()
{
	int x=0;char c=0;
	while (!isdigit(c=getchar()));x=c-48;
	while (isdigit(c=getchar())) x=x*10+c-48;
	return x;
}
*/
const int N=1e5+5;
int fa[N*2];
int find(int x) {return fa[x]==x?x:(fa[x]=find(fa[x]),fa[x]);}
void Union(int x,int y)
{
	x=find(x),y=find(y);
	if (x!=y) 
	{
		fa[x]=y;
	}
}
int main()
{
	freopen("send.in","r",stdin);
	freopen("send.out","w",stdout);
	int n=0,q=0;
	scanf("%d %d",&n,&q);
//	n=read(),q=read();
	for (int i=1;i<=2*n;++i) fa[i]=i;
	for (int i=0,opt=0,x=0,y=0,z=0;i<q;++i) 
	{
		scanf("%d %d %d %d",&opt,&x,&y,&z);
//		opt=read(),x=read(),y=read(),z=read();
		if (opt==1)
		{
			if (z%2==1)
			{
				Union(x,y+n);
				Union(x+n,y);
			}
			else
			{
				Union(x,y);
				Union(x+n,y+n);
			}
		}
		else
		{
			puts(find(x)==find(y)?"YES":"NO");
		}
	}
}
