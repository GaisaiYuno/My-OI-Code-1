//https://www.luogu.com.cn/problem/P5283 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm> 
#define maxn 500000
#define maxlogv 32
using namespace std;
typedef long long ll;
struct persist_trie{
	int ch[maxn*50+5][2];
	int sz[maxn*50+5];
	int id[maxn*50+5];//玄学数组大小 
	int root[maxn+5];
	int ptr;
	void insert(int pos,ll val,int idt){
		int now=root[pos]=++ptr,last=root[pos-1];
		for(ll i=maxlogv;i>=0;i--){//注意sum[i]比INT_MAX略大一点 
			ll k=(val>>i)&1ll;
			ch[now][k^1]=ch[last][k^1];
			ch[now][k]=++ptr;
			now=ch[now][k];
			last=ch[last][k];
			sz[now]=sz[last]+1;
		}
		id[now]=idt;
	}
	int query(int l,int r,ll val){
		int now=root[r],last=root[l-1];
		for(ll i=maxlogv;i>=0;i--){
			ll k=(val>>i)&1ll;
			int cnt=sz[ch[now][k^1]]-sz[ch[last][k^1]];
			if(cnt){
				now=ch[now][k^1];
				last=ch[last][k^1];
			}else{
				now=ch[now][k];
				last=ch[last][k];
			}
		}
		return id[now];
	}
}T; 
int n,m;
ll a[maxn+5],sum[maxn+5];
struct node{
	int l;
	int r;//右端点范围[l,r] 
	int x;//固定左端点位置 
	int mp;//[l,r]中最大值位置 
	ll val;
	node(){
		
	}
	node(int _x,int _l,int _r){
		x=_x;
		l=_l;
		r=_r;
		mp=T.query(l,r,sum[x-1]);
		val=sum[x-1]^sum[mp];
	}
	friend bool operator < (node p,node q){
		return p.val<q.val;
	}
};
priority_queue<node>q;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	} 
	for(int i=1;i<=n;i++) T.insert(i,sum[i],i);
	for(int i=1;i<=n;i++) q.push(node(i,i,n));
	ll ans=0;
	for(int i=1;i<=m;i++){
		node p=q.top();
		q.pop();
		ans+=p.val;
		if(p.l<p.mp) q.push(node(p.x,p.l,p.mp-1));
		if(p.mp<p.r) q.push(node(p.x,p.mp+1,p.r));
	} 
	printf("%lld\n",ans);
}
