#include <cstdio>
int a[1005],b[1005],lb[1005],x;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,j,m;
	bool k,l;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(i=1;i<=q;i++) {
		scanf("%d %d",&lb[i],&b[i]);
		m=1;k=true;l=false;x=999999999;
		for(j=1;j<=lb[i];j++) m=m*10;
		for(j=1;j<=n;j++){
			if(b[i]==a[j]%m) {
				if(x>a[j]) {x=a[j];}l=true;
			}
			if(j==n && l){
			printf("%d\n",x);k=false;break;}
		}
		if(k) printf("-1\n");
	}
	return 0;
}
