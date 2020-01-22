#include <bits/stdc++.h>
using namespace std;
int n,pass,ans,q,i,j,l,need,a[1001];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=q;i++){
		scanf("%d%d",&l,&need);
		pass=pow(10,l);
		ans=-1;
		for(j=1;j<=n;j++){
			if(a[j]<pass/10) continue;
			if(a[j]%pass==need){
				ans=a[j];
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
