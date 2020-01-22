#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,m[1005],s,in,l,tf;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&m[i]);
	sort(m,m+n);
	while(q--)
	{
		scanf("%d %d",&l,&in);
		tf=0;s=1;
		while(l--) s*=10;
		for(int i=0;i<n;i++)
		{
			if(m[i]%s==in&&tf==0)
			{
				tf=1;
				printf("%d\n",m[i]);
			}
		}
		if(tf==0) printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
