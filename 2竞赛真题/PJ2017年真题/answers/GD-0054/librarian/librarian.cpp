#include<cstdio>
#include<algorithm>
using namespace std;
int a[1001];
bool _comp(const int &a,const int &b)
{
	if (a<=b) return true;
		else return false; 
}
int main()
{
	int n,q,i,j,c,l,w,g;
	bool findit=false;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,_comp);
	for (i=1;i<=q;++i)
		{
		scanf("%d%d",&l,&c);
		findit=false;
		w=1;
		for (j=1;j<=l;++j)
			w*=10;
		for (j=1;j<=n;++j)
			if (a[j]%w==c)
				{
				findit=true;
				g=j;
				break;
				}
		if (findit) printf("%d\n",a[g]);
			else printf("-1\n");
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
