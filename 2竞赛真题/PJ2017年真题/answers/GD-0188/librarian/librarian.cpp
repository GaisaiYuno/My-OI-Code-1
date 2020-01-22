#include<bits/stdc++.h>
using namespace std;
struct book
{
	int k;
	int l;
}m[1100];
int n,q,w[1100],i,j,r,v;
int po(int len)
{
	int ans=1;
	for(int i=1;i<=len;i++)ans*=10;
	return ans;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)scanf("%d",&w[i]);
	for(i=1;i<=q;i++)scanf("%d%d",&m[i].l,&m[i].k);
	sort(w+1,w+n+1);
	for(i=1;i<=q;i++)
		for(j=1;j<=n;j++)
		{
			r=w[j]%po(m[i].l);
			v=0;
			if(r==m[i].k)
			{
				printf("%d\n",w[j]);
				break;
			}
			if(j==n)printf("-1\n");
		}
}
