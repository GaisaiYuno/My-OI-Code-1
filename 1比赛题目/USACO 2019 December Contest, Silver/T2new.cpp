#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
ll L;
struct cow{
	ll x;
	ll w;
	ll neww; 
	int d;
	inline ll tim(){
		if(d==-1) return x;
		else return L-x; 
	}
}a[maxn+5];
bool cmpx(cow p,cow q){
	return p.x<q.x;
}
bool cmpt(cow p,cow q){
	return p.tim()<q.tim();
}


ll get_tim(ll tot){
	static cow b[maxn+5];
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(a+1,a+1+n,cmpt);
	sort(b+1,b+1+n,cmpx);
	int l=1,r=n;
	ll sum=0;
	ll T=0;
	for(int i=1;i<=n;i++){
		if(a[i].d==1) sum+=b[r--].w;
		else sum+=b[l++].w;
		if((i==n||a[i].tim()!=a[i+1].tim())&&sum*2>=tot){
			T=a[i].tim();
			break;
		}
	}
	return T;
} 


int bin_search(int l,int r,ll pos){
	int mid;
	int ans=n+1;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid].x>=pos){ //找到第一个坐标>=pos的位置 
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
int main(){
#ifndef LOCAL
	freopen("meetings.in","r",stdin);
	freopen("meetings.out","w",stdout);
#endif
	scanf("%d %lld",&n,&L);
	ll tot=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %d",&a[i].w,&a[i].x,&a[i].d);
		tot+=a[i].w;
	}
	ll T=get_tim(tot);
//	printf("%lld\n",T);

	sort(a+1,a+1+n,cmpx);
		
	static int cnt[maxn+5];
	cnt[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i].d==1) cnt[i]=cnt[i-1]+1;
		else cnt[i]=cnt[i-1];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].d==-1){
			ll rb=a[i].x-T*2;
			int pos=bin_search(1,n,rb);
			ans+=cnt[i]-cnt[pos-1];
		}
	}

	printf("%lld\n",ans);
//	printf("2\n");
} 
