#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[500001],b[500001],l,r;
int aa(int x){
	int f[500001]={0};
	for(int i=1;i<=n;++i){
		for(int j=i-1;j>=1;--j){
			if(a[i]-a[j]>=m+x)break;
			if(a[i]-a[j]>m-x)f[i]=max(f[i],f[j]);
		}
		f[i]+=b[i];
		if(f[i]>=k)return 1;
	}
	return 0;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&b[i]);
		r+=max(0,b[i]);
	}
	if(r<k){
		printf("-1\n");
		return 0;
	}
	r=10000000;
	l=abs(m-a[1]);
	while(l<r){
		int mid=(l+r)/2;
		if(aa(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
