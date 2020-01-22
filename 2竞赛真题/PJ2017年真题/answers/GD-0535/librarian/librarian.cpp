#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,q; int a[1001];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=q;i++){
		int x,y,j; scanf("%d%d",&x,&y); 
		int s=pow(10.0,x);
		for (j=1;j<=n;j++) if (a[j]%s==y) {printf("%d\n",a[j]); break;}
	    if (a[j]%s!=y) printf("%d\n",-1);
	}
	return 0;
}
