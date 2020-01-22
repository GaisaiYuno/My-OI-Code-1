#include<cstdio>
int n,p,bm[1001],t,ans,cnt,k;
#define INF 0x7fffffff
main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&p);
	for (register int i=1;i<=n;i++) scanf("%d",&bm[i]);
	for (register int i=1;i<=p;i++){
		scanf("%d%d",&k,&t);
		ans=INF; cnt=1;
		for (register int j=1;j<=k;j++) cnt*=10;
		for (register int j=1;j<=n;j++)
			if(bm[j]%cnt==t) ans=bm[j]<ans? bm[j]:ans;
		if(ans!=INF) printf("%d\n",ans);
		else printf("-1\n");
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
