#include<bits/stdc++.h>
using namespace std;
int n,q,f[1010],check,run;
long long book[1010],reader[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%lld",&book[i]);
    for (int i=1;i<=q;i++) scanf("%d%lld",&f[i],&reader[i]);
    sort(book+1,book+n+1);
    for (int i=1;i<=q;i++)
    {
    	run=0;
    	for (int j=1;j<=n;j++)
        {
        	check=1;
        	for (int k=1;k<=f[i];k++) check*=10;
        	if ((book[j]-reader[i])%check==0) 
        	{
        		run=1;
        		printf("%lld\n",book[j]);
        		break;
        	}
        }
        if (run==0) printf("-1\n");
    }
	return 0;
}
