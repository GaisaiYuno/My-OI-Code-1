#include<bits/stdc++.h>
using namespace std;
struct abc{
	int l,num;
}qq[1001];
int i,j,n,q,nn[1001],mini[1001];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&nn[i]);
	sort(nn+1,nn+n+1);
	for(i=1;i<=q;i++) {
		scanf("%d%d",&qq[i].l,&qq[i].num);
		for(j=1;j<=n;j++) if(nn[j]>=qq[i].num){
			int k=qq[i].num,o=10000000;
			while(k<o/10) o/=10;
			k=nn[j]-(nn[j]/o*o);
			if(k==qq[i].num) {
				mini[i]=nn[j];
				break;
			}
		}
	}
	for(i=1;i<=q;i++) {
		if(mini[i]!=0) printf("%d\n",mini[i]);
		else printf("-1\n");
	}
	return 0;
}
