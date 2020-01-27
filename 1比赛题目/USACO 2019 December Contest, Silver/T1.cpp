#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll n;
bool check(ll mid){
	ll cnt=mid-mid/3-mid/5+mid/15;
	if(cnt>=n) return 1;
	else return 0;
}
int main(){
#ifndef LOCAL
	freopen("moobuzz.in","r",stdin);
	freopen("moobuzz.out","w",stdout);
#endif
	scanf("%lld",&n);
	ll l=1,r=1e17,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%lld\n",ans);
} 
