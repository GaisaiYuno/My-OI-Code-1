#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
typedef long long ll;
ll l,k;
inline void qread(ll &x){
	x=0;
	ll sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

ll a[maxn];
ll lans=0,rans=0;
ll check(ll s){
	ll cnt=0;
	ll sum=0;
	for(int i=1;i<=l;i++){
		sum+=a[i];
		if(sum<0) sum=0;
		if(sum>=s){
			sum=0;
			cnt++;
		}
	}
	return cnt;
}

ll mv=0;
ll bin_search1(){
	ll l=1,r=mv;
	ll ans=mv;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)<=k){
			r=mid-1;
			ans=min(ans,mid);
		}
		else l=mid+1;
	}
	return l;
}

ll bin_search2(){
	ll l=1,r=mv;
	ll ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)>=k){
			l=mid+1;
			ans=max(ans,mid);
		}
		else r=mid-1;
	}
	return r;
}
int main(){
	qread(l);
	qread(k);
	for(int i=1;i<=l;i++){
		qread(a[i]);
		if(a[i]>0) mv+=a[i];
	}
	lans=bin_search1();
	if(check(lans)!=k){
		printf("-1\n");
		return 0;
	}
	rans=bin_search2();
	if(check(rans)!=k){
		printf("-1\n");
		return 0;
	}
	if(rans<lans) swap(lans,rans);
	printf("%lld %lld\n",lans,rans);
	
}
