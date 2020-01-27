#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
ll L;
struct cow{
	ll x;
	ll w; 
	int d;
	ll tim;
	cow(){
		
	}
	cow(ll _x,ll _w,int _d){
		x=_x;
		w=_w;
		d=_d;
	}
	inline ll ftim(){
		if(d==-1) return x;
		else return L-x; 
	}
}a[maxn+5];
bool cmpx(cow p,cow q){
	return p.x<q.x;
}
bool cmpt(cow p,cow q){
	return p.tim<q.tim;
}

vector<cow> b[maxn+5],c[maxn+5];
bool check(ll mid){
	int lb=lower_bound(b.begin(),b.end(),cow(),cmpt)
}
void get_tim(){
	for(int i=1;i<=n;i++){
		if(a[i].d==-1) b.push_back(a[i]);
		else c.push_back(a[i]);
	}
	sort(b.begin(),b.end(),cmpt);
	sort(c.begin(),c.end(),cmpt);
}


int main(){
	scanf("%d %lld",&n,&L);
	ll tot=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %d",&a[i].w,&a[i].x,&a[i].d);
		a[i].tim=a[i].ftim();
	}
	ll T=get_tim();
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
			ll lb=a[i].x-T*2;
			int pos=bin_search(1,i,lb);
			if(pos==n+1) continue;
			ans+=cnt[i]-cnt[pos-1];
		}
	}

	printf("%lld\n",ans);
//	printf("2\n");
} 
