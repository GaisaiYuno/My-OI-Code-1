#include <iostream>
#include <cstdio>
using namespace std;

int n, d, k, a[500010], s[500010];

bool deal(int x){
	int f[500010]={0};
	f[0]=0;
	for (int i=1; i<=n; i++){
		f[i]=0;
		bool bj=0;
		for (int j=i-1; j>=0; j--){
			if (a[i]-a[j]>d+x) break;
			if (a[i]-a[j]<(x<d?d-x:1)) continue;
			bj=1;
			f[i]=max(f[i], f[j]);
		}
		if (bj) f[i]+=s[i]; 
		else break;
		if (f[i]>=k) return 1;
	}
	return 0;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i],&s[i]);
	int l=0, r=1000000001;
	while (l<r){
		int mid=(l+r)/2;
		if (deal(mid)) r=mid;
		else l=mid+1;
	}
	if (deal(r)) printf("%d\n",r);
	else printf("-1\n");
	
	fclose(stdout);
	return 0;
}
