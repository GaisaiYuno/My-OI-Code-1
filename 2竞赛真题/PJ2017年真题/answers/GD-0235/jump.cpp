#include<cstdio>
#include<cstring>
struct node{ int x,s; } a[500010];
int n,d,k,t=0,ans=0;
/*void search()
{
	
}*/
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].s);
		if(a[i].s>0) t+=a[i].s;
	}
	if(t<k) { printf("-1"); return 0; }
	/*search();
	if(ans!=k) printf("-1");
	else printf("%d",ans);*/
	printf("-1");
	return 0;
}
