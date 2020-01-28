#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 10000005
using namespace std;
typedef long long ll;
ll l,r,k;
ll vis1[maxn],vis2[maxn];

void segment_sieve(ll a,ll b) {
	ll siz=min((ll)sqrt(b),min(b,k));
    for(ll i=2;i<=siz;i++) {
        if(!vis1[i]) {
            for(ll j=i*i;j<=siz;j+=i) vis1[j]=1;  
            for(ll j=max(2LL,(a+i-1)/i)*i;j<=b;j+=i) vis2[j-a]=1;
        }
    }
}

ll get_sum(){
	ll sum=0;
	for(ll i=0;i<=r-l;i++){
		if(!vis2[i]) {
//			printf("%d\n",i+l);
			sum^=(i+l);
		}
	}
	return sum;
}
int main() {
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
    cin>>l>>r>>k;
//    l=100000000000000;
//	r=100000010000000;
//	k=1000000000;
	vis1[0]=1;
	vis1[1]=1;
	segment_sieve(l,r);
	cout<<get_sum();
}

