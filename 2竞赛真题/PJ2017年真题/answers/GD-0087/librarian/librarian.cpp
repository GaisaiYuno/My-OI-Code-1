#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int ans,num[20000],lon,fin,n,m;
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
	  scanf("%d",&num[i]);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&lon,&fin);
		bool ansb=false;
		ans=100000000;
		for (int j=1; j<=n; j++)
		{
			int q=num[j],p=fin;
			bool boo=true;
			for (int k=1; k<=lon; k++)
			{
			  if (q%10!=p%10)
				{
					boo=false;
					break;
				}
				else q=q/10,p=p/10;
				//cout<<boo<<endl;
			}
			if (boo&&p==0) ans=min(ans,num[j]),ansb=true;
			//cout<<boo<<' '<<p<<endl;
		}
		if (ansb) printf("%d\n",ans);
		  else printf("-1\n");
	}
	return 0;
}
