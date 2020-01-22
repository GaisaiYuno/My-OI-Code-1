#include<cstdio>
#include<algorithm>
using namespace std;
int f(int a,int b)
{
	int r=1;
	for(int i=0;i<b;i++)
	{
		r*=a;
	}
	return r;
}
typedef struct bookm{
	int l;
	int m;
}bm;
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,*sm;
	bm *xqm;
	scanf(" %d %d",&n,&q);
	sm=new int[n];
	xqm=new bm[q];
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&sm[i]);
	}
	for(int i=0;i<q;i++)
	{
		scanf(" %d %d",&xqm[i].l,&xqm[i].m);
	}
	sort(sm,sm+n,cmp);
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(sm[j]%f(10,xqm[i].l)==xqm[i].m)
			{
				printf("%d\n",sm[j]);
				break;
			}
			if(j==n-1)
			{
				printf("-1\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
