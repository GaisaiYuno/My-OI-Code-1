#include <cstdio>
#include <algorithm>
using namespace std;
int x[500001],y[500001],l,r,n,d,k,s,ans;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),s=s+max(y[i],0),ans=max(ans,x[i]-x[i-1]);
	if (s<k) {printf("-1"); return 0;}
	printf("%d",ans/2);
	return 0;
}
