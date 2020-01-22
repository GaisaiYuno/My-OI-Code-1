#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n;
ll X;
struct node{
	ll l;
	ll r;
	ll b;
}a[maxn+5];

namespace l_equal_r{
	bool cmp1 (node p,node q){
		return p.l>q.l;
	}
	ll solve1(){
		ll suma=0;
		for(int i=1;i<=n;i++){
			suma+=a[i].b*a[i].l;
		}
		sort(a+1,a+1+n,cmp1);
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll tim=(suma%a[i].l==0)?(suma/a[i].l):(suma/a[i].l+1);
			if(tim>X) tim=X;
			ans+=tim;
			suma-=tim*a[i].l;
			if(suma<=0) break;
		}
		return ans;
	}
	bool cmp2 (node p,node q){
		return p.r>q.r;
	}
	ll solve2(){
		ll suma=0;
		for(int i=1;i<=n;i++){
			suma+=a[i].b*a[i].r;
		}
		sort(a+1,a+1+n,cmp2);
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll tim=(suma%a[i].r==0)?(suma/a[i].r):(suma/a[i].r+1);
			if(tim>X) tim=X;
			ans+=tim;
			suma-=tim*a[i].r;
			if(suma<=0) break;
		}
		return ans;
	}
}

int main(){
#ifdef LOCAL
	freopen("9.in","r",stdin);
#endif
	bool flag=1;
	scanf("%d %lld",&n,&X);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a[i].b,&a[i].l,&a[i].r);
		if(a[i].l!=a[i].r) flag=0;
	}
	if(flag) printf("%lld\n",l_equal_r::solve1());
	else printf("%lld\n",min(l_equal_r::solve1(),l_equal_r::solve2()));
	
}
