### [Codeforces 266E]More Queries to Array...(线段树+二项式定理)

###　题面

维护一个长度为$n$的序列$a$，$m$个操作

1. 区间赋值为$x$
2. 查询$\sum_{i=l}^r a_i(i-l+1)^k \mod 10^9+7$

$n,m \leq 10^5,k \leq 5$

### 分析

根据二项式定理

$$(i-l+1)^k=\sum_{j=0}^k (-1)^{k-j} C_{k}^j i^j(l-1)^{k-j}$$

那么

$\begin{aligned}ans(l,r) &=\sum_{i=l}^r a_i(i-l+1)^k  \\ &= \sum_{i=l}^r a_i\sum_{j=0}^k (-1)^{k-j} C_{k}^j i^j(l-1)^{k-j} \\ &=  \sum_{i=l}^r \sum_{j=0}^k (a_ii^j) (-1)^{k-j} C_{k}^j (l-1)^{k-j} \\ &=\sum_{j=0}^k query(l,r,j) (-1)^{k-j} C_{k}^j (l-1)^{k-j}\end{aligned}$

其中$query(l,r,p)=\sum_{l=1}^r a_i^{p}$

开$k$棵线段树，每棵维护$\sum_{l=1}^r a_i^{p}$.提前预处理$sum[i][j]$表示$\sum_{p=1}^{j} p^i$,修改为$x$的时候直接区间赋值为$x(sum[i][r]-sum[i][l-1])$

时间复杂度$O(nk \log n)$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000 
#define mod 1000000007
#define maxk 5
using namespace std;
typedef long long ll;
int n,m;
 
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
ll fact[maxn+5];
ll invfact[maxn+5];
void ini_fact(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
}
inline ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}
 
ll sump[maxk+5][maxn+5];
void ini_pow(int n,int k){
	for(int i=0;i<=k;i++){
		for(int j=1;j<=n;j++){
			sump[i][j]=(sump[i][j-1]+fast_pow(j,i))%mod;
		}
	}
}
inline ll get_sump(int k,int l,int r){
	return (sump[k][r]-sump[k][l-1]+mod)%mod;
}
 
struct segment_tree{
	struct node{
		int l;
		int r;
		ll val;
		ll mark;
	}tree[maxn*4+5];
	int kk;//记录当前维护的是a[i]^k 
	void push_up(int pos){
		tree[pos].val=(tree[pos<<1].val+tree[pos<<1|1].val)%mod;
	} 
	void build(int l,int r,int *a,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].mark=-1;
		if(l==r){
			tree[pos].val=a[l]*fast_pow(l,kk);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,a,pos<<1);
		build(mid+1,r,a,pos<<1|1);
		push_up(pos);
	}
	inline void add_mark(int pos,int mark){
		tree[pos].mark=mark;
		tree[pos].val=mark*get_sump(kk,tree[pos].l,tree[pos].r)%mod;
	}
	void push_down(int pos){
		if(tree[pos].mark!=-1){
			add_mark(pos<<1,tree[pos].mark);
			add_mark(pos<<1|1,tree[pos].mark);
			tree[pos].mark=-1;
		}
	}
	void update(int L,int R,int val,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			add_mark(pos,val);
			return;
		} 
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,val,pos<<1);
		if(R>mid) update(L,R,val,pos<<1|1);
		push_up(pos);
	}
	ll query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].val;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		ll ans=0;
		if(L<=mid) ans=(ans+query(L,R,pos<<1))%mod;
		if(R>mid) ans=(ans+query(L,R,pos<<1|1))%mod;
		return ans;
	}
}T[6];
 
int a[maxn+5];
int main(){
	char cmd[2];
	int l,r,x,k;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ini_fact(maxk);
	ini_pow(n,maxk);
	for(int i=0;i<=maxk;i++){
		T[i].kk=i;
		T[i].build(1,n,a,1);
	}
	for(int t=1;t<=m;t++){
		scanf("%s",cmd);
		if(cmd[0]=='='){
			scanf("%d %d %d",&l,&r,&x);
			for(int i=0;i<=maxk;i++) T[i].update(l,r,x,1);
		}else{
			scanf("%d %d %d",&l,&r,&k);
			ll ans=0;
			//按照二项式定理,把a[i](i-l+1)^k展开
			//(-1)^j*C(k,j)*a[i]*i^j*(l-1)^(k-j) 
			for(int j=0;j<=k;j++){
//				printf("db: %lld\n",fast_pow(-1,j)); 
//				printf("db: %lld\n",C(k,j)); 
//				printf("db: %lld\n",T[j].query(l,r,1)); 
//				printf("db: %lld\n",fast_pow(l-1,k-j)); 
				ans+=fast_pow(-1,k-j)*C(k,j)%mod*T[j].query(l,r,1)%mod*fast_pow(l-1,k-j)%mod;
				ans=(ans+mod)%mod;
				ans%=mod;
			}
			printf("%lld\n",ans);
		}
	}
}
```

