#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,k;
int is_ok(long long k){
	long long x=n,cnt=0;
	while(x>0){
		cnt+=min(x,k);
		x-=k;
		x-=x/10;
	}
	if(cnt>=(n+1)/2) return 1;
	else return 0;
}
int main(){
	scanf("%I64d",&n);
	long long l=1,r=(n+1)/2;
	long long ans=0;
	long long mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(is_ok(mid)){
			r=mid-1;
			ans=mid;
		}else l=mid+1;
	}
	printf("%I64d\n",ans);
}
