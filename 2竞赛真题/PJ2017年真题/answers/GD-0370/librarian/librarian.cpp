#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,wei[1010];
long long shu[1010],tor,ans,xq[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&shu[i]);
	sort(shu+1,shu+n+1);
//	for(int i=1;i<=n;i++) cout<<shu[i]<<endl;
	for(int i=1;i<=q;i++)
	{
		tor=1;ans=0x7fffffff;
		scanf("%d%lld",&wei[i],&xq[i]);
		for(int hh=1;hh<=wei[i];hh++) tor*=10;
		for(int j=1;j<=n;j++) 
		{
			if(shu[j]%tor==xq[i]) 
			{
				ans=shu[j];
				break;
			}
		}
		if(ans==0x7fffffff) cout<<"-1"<<endl;
		else printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12
*/
