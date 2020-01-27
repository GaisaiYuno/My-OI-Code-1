//https://www.luogu.org/problemnew/show/P4140
 
//存在a,b,使得ax+by=1,y已知，求x
//同时取模y，变成ax=1 (mod y)
//a=inv(x) (mod y),如果x,y不互质，则不存在逆元 
//所以gcd(x,y)=1
//问题转化成求[1,y]中与y质的数的个数,即phi(y)
//注意到phi(y)= y*PI(1-p[i]/p[i]),p[i]为y的质因子 
//由于乘积取模后质因子会变，线段树维护y的质因子，显然最多不超过60个，用状压保存有哪个质因子 
//由于还要取模，记得用逆元 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100000
#define mod 19961993
using namespace std;
typedef long long ll;
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1; 
	}
	return ans;
}  
inline ll inv(ll x){
	return fast_pow(x,mod-2);
}

int cnt=0;
int vis[maxn];
ll prime[maxn];
ll invprime[maxn];
void sieve(int n){
	vis[1]=0;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break; 
		}
		if(cnt==60) break;
	}
	for(int i=1;i<=cnt;i++){
		invprime[i]=inv(prime[i]);
	}
}
struct segment_tree{
	struct node{
		int l;
		int r;
		ll sum;//区间乘积
		ll pri;//区间包含质因数 
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].sum=tree[pos<<1].sum*tree[pos<<1|1].sum%mod;
		tree[pos].pri=tree[pos<<1].pri|tree[pos<<1|1].pri;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r){
			tree[pos].sum=3;
			tree[pos].pri=2;//(10)2 
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void update(int tpos,ll val,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].sum=val;
			tree[pos].pri=0;
			for(int i=1;i<=60;i++){
				if(val%prime[i]==0) tree[pos].pri|=1ll<<(i-1); 
			}
			return; 
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(tpos<=mid) update(tpos,val,pos<<1);
		else update(tpos,val,pos<<1|1);
		push_up(pos);
	}
	pair<ll,ll> query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return make_pair(tree[pos].sum,tree[pos].pri);
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		pair<ll,ll> ans=make_pair(1,0);
		if(L<=mid){
			pair<ll,ll> tmp=query(L,R,pos<<1);
			ans.first=ans.first*tmp.first%mod;
			ans.second|=tmp.second;
		}
		if(R>mid){
			pair<ll,ll> tmp=query(L,R,pos<<1|1);
			ans.first=ans.first*tmp.first%mod;
			ans.second|=tmp.second;
		}
		return ans;
	}
}T;

int m;
ll calc(ll state){
	ll ans=1;
//	return (prime[2]-1)*invprime[2]%mod;
	for(int i=1;i<=60;i++){
		if(state&(1ll<<(i-1))){
//			printf("ok %d\n",i);
			ans=ans*(prime[i]-1)%mod*invprime[i]%mod; 
		}
	}
	return ans;
}
int main(){
	int x,y,z;
	sieve(300);
	T.build(1,maxn,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&x,&y,&z);
		if(x==0){
			pair<ll,ll> ans=T.query(y,z,1);
			ll total=ans.first*calc(ans.second)%mod;
			printf("%lld\n",total);
		}else{
			T.update(y,z,1);
		}
	}
} 
