#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
using namespace std;
int n;
long long k;
long long a[maxn+5];
bool check(long long mid){
	long long ans=0;
	for(int i=n/2+1;i<=n;i++){
		if(a[i]<mid) ans+=mid-a[i]; 
		if(ans>k) return 0;
	}
	return ans<=k;
}
int main(){
	scanf("%d",&n);
	scanf("%I64d",&k);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	long long l=a[n/2+1],r=1e18;
	long long mid;
	long long ans=a[n/2+1];
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	printf("%I64d\n",ans);
}

