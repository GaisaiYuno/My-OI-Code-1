#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
using namespace std;
int n; 
long long d[maxn];
long long sum[maxn];
int bin_search(long long x,long long *a){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) r=mid-1;
		else l=mid+1;
	}
	return -1; 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&d[i]);
		sum[i]=sum[i-1]+d[i];
	}
	long long tot=0;
	long long ans=0;
	for(int i=n;i>=1;i--){
		tot+=d[i];
		int pos=bin_search(tot,sum);
		if(pos==-1||pos>=i) continue;
		else{
			ans=max(ans,tot);
		}
	}
	printf("%I64d\n",ans);
}
