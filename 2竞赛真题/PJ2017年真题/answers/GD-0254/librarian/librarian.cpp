#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int q,n,bxqm[1001],k,u=10000001;
struct Reader
{
	int lenn;
	int xqm;
	int tm=1;
	bool YN=false;
};
Reader r[1001];
int tmp;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&bxqm[i]);
	for(int i=0;i<q;i++) scanf("%d%d",&r[i].lenn,&r[i].xqm);
	for(int i=0;i<q;i++)
	{
		for(int j=1;j<=r[i].lenn;j++) r[i].tm*=10;
	}
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<n;j++)
		{
			tmp=(bxqm[j]-r[i].xqm)%r[i].tm;
			if(tmp==0)
			{
				k=bxqm[j];
				u=min(u,k);
				r[i].YN=true;
			}
		}
		if(r[i].YN==true) printf("%d\n",u);
		else printf("-1\n");
		u=10000001;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
