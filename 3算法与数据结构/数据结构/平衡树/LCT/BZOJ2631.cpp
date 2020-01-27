//https://www.luogu.com.cn/problem/P1501
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 200000
#define mod 51061
using namespace std;
typedef unsigned int ll;
int n,m;
struct LCT{
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
#define fa(x) (tree[x].fa)
	struct node{
		int fa;
		int ch[2];
		ll val;
		ll sum;
		int sz;
		int revm;
		ll addm;
		ll mulm;
	}tree[maxn+5];
	inline bool is_root(int x){
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x){
		return rson(fa(x))==x;
	}
	void push_up(int x){
		tree[x].sum=(tree[lson(x)].sum+tree[rson(x)].sum+tree[x].val)%mod;
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
	}
	void reverse(int x){
		if(x==0) return;
		tree[x].revm^=1;
		swap(lson(x),rson(x));
	}
	void push_down(int x){
		if(tree[x].mulm!=1){
			tree[lson(x)].sum*=tree[x].mulm;tree[lson(x)].sum%=mod;
			tree[lson(x)].val*=tree[x].mulm;tree[lson(x)].val%=mod;
			tree[lson(x)].addm*=tree[x].mulm;tree[lson(x)].addm%=mod;
			tree[lson(x)].mulm*=tree[x].mulm;tree[lson(x)].mulm%=mod;
			tree[rson(x)].sum*=tree[x].mulm;tree[rson(x)].sum%=mod;
			tree[rson(x)].val*=tree[x].mulm;tree[rson(x)].val%=mod;
			tree[rson(x)].addm*=tree[x].mulm;tree[rson(x)].addm%=mod;
			tree[rson(x)].mulm*=tree[x].mulm;tree[rson(x)].mulm%=mod;
			tree[x].mulm=1;
		}
		if(tree[x].addm!=0){
			tree[lson(x)].sum+=tree[lson(x)].sz*tree[x].addm%mod;tree[lson(x)].sum%=mod;
			tree[lson(x)].val+=tree[x].addm;tree[lson(x)].val%=mod;
			tree[lson(x)].addm+=tree[x].addm;tree[lson(x)].addm%=mod;
			tree[rson(x)].sum+=tree[rson(x)].sz*tree[x].addm%mod;tree[rson(x)].sum%=mod;
			tree[rson(x)].val+=tree[x].addm;tree[rson(x)].val%=mod;
			tree[rson(x)].addm+=tree[x].addm;tree[rson(x)].addm%=mod;
			tree[x].addm=0;
		}
		if(tree[x].revm){
			reverse(lson(x));
			reverse(rson(x));
			tree[x].revm=0;
		}
	}
	void push_down_all(int x){
		if(!is_root(x)) push_down_all(fa(x));
		push_down(x);
	}
	void rotate(int x){
		int y=fa(x),z=fa(y),k=check(x),w=tree[x].ch[k^1];
		tree[y].ch[k]=w;
		tree[w].fa=y;
		if(!is_root(y)) tree[z].ch[check(y)]=x;
		tree[x].fa=z;
		tree[x].ch[k^1]=y;
		tree[y].fa=x;
		push_up(y);
		push_up(x);
	}
	void splay(int x){
		push_down_all(x);
		while(!is_root(x)){
			int y=fa(x);
			if(!is_root(y)){
				if(check(y)==check(x)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		push_up(x);
	}
	void access(int x){
		for(int y=0;x;y=x,x=fa(x)){
			splay(x);
			rson(x)=y;
			push_up(x);
		}
	} 
	void make_root(int x){
		access(x);
		splay(x);
		reverse(x);
	}
	void split(int x,int y){
		make_root(x);
		access(y);
		splay(y);
	}
	void link(int x,int y){
		make_root(x);
		fa(x)=y;
	}
	void cut(int x,int y){
		split(x,y);
		lson(y)=fa(x)=0;
		push_up(y);
	}
	void add_route(int x,int y,ll val){
		split(x,y);
		tree[y].sum+=val*tree[y].sz%mod;tree[y].sum%=mod;
		tree[y].val+=val;tree[y].val%=mod;
		tree[y].addm+=val;tree[y].addm%=mod;
	}
	void mul_route(int x,int y,ll val){
		split(x,y);
		tree[y].sum*=val;tree[y].sum%=mod;
		tree[y].val*=val;tree[y].val%=mod;
		tree[y].addm*=val;tree[y].addm%=mod;
		tree[y].mulm*=val;tree[y].mulm%=mod; 
	}
	int query_route(int x,int y){
		split(x,y);
		return tree[y].sum; 
	} 
}T;

int main(){
	int u,v,p,q,c;
	char cmd[2];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		T.tree[i].sz=1;
		T.tree[i].mulm=1;
		T.tree[i].sum=1;
		T.tree[i].val=1;
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		T.link(u,v);
	}
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='+'){
			scanf("%d %d %d",&u,&v,&c);
			T.add_route(u,v,c);
		}else if(cmd[0]=='-'){
			scanf("%d %d %d %d",&u,&v,&p,&q);
			T.cut(u,v);
			T.link(p,q);
		}else if(cmd[0]=='*'){
			scanf("%d %d %d",&u,&v,&c);
			T.mul_route(u,v,c);
		}else{
			scanf("%d %d",&u,&v);
			printf("%d\n",T.query_route(u,v));
		}
	}
}

