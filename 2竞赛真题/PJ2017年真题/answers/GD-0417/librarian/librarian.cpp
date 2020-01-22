#include <bits/stdc++.h>
using namespace std;
bool a[10000010];
int cl(int p){
	int sum=1,i;
	for(i=1;i<=p;i++) sum*=10;
	return sum;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,l,o,maxx=0,i,j,p;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&p);
		a[p]=1;
		maxx=max(p,maxx);
	}
	for(i=1;i<=q;i++){
		bool f=0;
		scanf("%d%d",&l,&o);
		int p=cl(l);
		for(j=o;j<=maxx;j+=p){
			if(a[j]){
				f=1;
				break;
			}
		}
		if(f) printf("%d\n",j);
		else printf("-1\n");
	}
}
