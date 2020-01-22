#include<cstdio>
#include<cstdlib>
#include<cstring>

int n,q,num[1010],nl[1010],l,w,min=10000010,a=1;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&w);
		for(int j=1;j<=l;j++) a*=10;
		for(int j=1;j<=n;j++) if(num[j]%a==w && num[j]<min) min=num[j];
		if(min!=10000010) printf("%d",min);
		else printf("-1");
		if(i!=q) printf("\n");
		min=10000010;a=1;
	}
	return 0;
}
