#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int n,d,k,a[500001],b[500001],maxn,ans=-1,mini=0x7fffffff,ans1=0x7fffffff;

void dfs(int ml,int mx,int id,int tot){
	if(tot>=k){
		mini=min(mini,(int)max(abs(d-ml),abs(d-mx)));
		return;
	}
	for(int i=id+1;i<=n;i++){
		int l=a[i]-a[id];
		dfs(min(ml,l),max(mx,l),i,tot+b[i]);
	}
	return;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(maxn+b[i]>maxn or i==1)maxn+=b[i];
	}
	if(maxn<k){
		puts("-1");
		return 0;
	}
	if(maxn==k){
		int last=a[1],tot=b[1];
		for(int i=2;i<=n;i++){
			if(b[i]>=0){
				ans=max(ans,a[i]-last);
				ans1=min(ans,a[i]-last);
				tot+=b[i];
				last=a[i];
			}
			if(tot==k)break;
		}
		printf("%.0lf",max(abs(d-ans),abs(d-ans1)));
		return 0;
	}
	dfs(0x7fffffff,-1,1,a[1]);
	printf("%d",mini);
	return 0;
}
