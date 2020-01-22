#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,q,ans,tem,temp,x,a,top;
int book[10005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1; i<=n; i++) cin>>book[i];
	for (int i=1; i<=q; i++)
	{
		ans=100000000; temp=1; top=0;
		scanf("%d%d",&x,&a);
		for (int j=1; j<=x; j++) temp*=10;
		for (int j=1; j<=n; j++)
		{
			tem=book[j]%temp;
			if (a==tem) 
			{
				ans=min(ans,book[j]);
				top++;
			}
		}
		if (!top) cout<<-1<<endl;
		  else printf("%d\n",ans);
	}
	return 0;
}
