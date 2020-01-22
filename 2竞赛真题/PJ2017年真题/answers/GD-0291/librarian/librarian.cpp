#include<iostream>
#include<cstdio>
using namespace std;
int n,q,i,x,a[1005][15],y,j,k,xmin,b[1005];
bool yes;
main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (i=1; i<=n; ++i){
		scanf("%d",&b[i]);
		x=b[i],a[i][0]=0;
		while (x!=0){
			a[i][++a[i][0]]=x%10;
			x/=10;
		}
	}
	for (i=1; i<=q; i++){
		scanf("%d%d",&x,&y);
		xmin=2000000000;
		for (j=1; j<=n; ++j)
			if (a[j][0]>=x){
				yes=1,k=1;
				while (y!=0){
					if (y%10!=a[j][k]){
						yes=0;
						break;
					}
					y/=10,++k;
				}
				if (yes==1&&b[j]<xmin) xmin=b[j];
			}
		if (xmin==2000000000) printf("-1\n");
			else printf("%d\n",xmin);
	}
	fclose(stdin);
	fclose(stdout);
}
