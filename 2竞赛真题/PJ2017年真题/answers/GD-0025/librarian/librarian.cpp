#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,j,k,p,ans,g,h,m;
	bool flag;
	int a[1001],b[1001],c[1001];
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=q;i++){
		h=1;
		k=0;
		flag=false;
		scanf("%d%d",&p,&g);
		for(j=1;j<=p;j++) h=h*10;
		for(j=1;j<=n;j++){
		   b[j]=a[j]%h;
	    }
        for(j=1;j<=n;j++){
        	if(b[j]==g) {
        		flag=true;
        		c[k]=a[j];
        		k++;
        	}
        }
        sort(c,c+k);
        if(flag) ans=c[0];
        else ans=-1;
        printf("%d\n",ans);
	}
	return 0;
}
