#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 300000
using namespace std;
struct LCT{//orz Tarjan
#define fa(x) (tree[x].fa)
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
	struct node{
		int fa;
		int ch[2];
		int sz;
		bool revm;
	}tree[maxn+5];
	void ini(int n){
		for(int i=1;i<=n;i++){
			tree[i].sz=1;
		}
	}
	inline bool is_root(int x){
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x){
		return rson(fa(x))==x;
	}
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
	}
	void reverse(int x){
		tree[x].revm^=1;
		swap(lson(x),rson(x));
	}
	void push_down(int x){
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
				if(check(x)==check(y)) rotate(y);
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
	int find_root(int x){
		access(x);
		splay(x);
		while(lson(x)){
			push_down(x);
			x=lson(x);
		} 
		splay(x);
		return x;
	}
	int query(int x,int y){
		return find_root(x)==find_root(y);
	}
}T;

int n,m;
int from[maxn+5],to[maxn+5];
int main(){
	int u,v;
	int cnt=0;
	char cmd[2];
	scanf("%d %d",&n,&m);
//	T.ini(n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		T.link(u,v);
	}
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='Q'){
			scanf("%d %d",&u,&v);
			if(T.query(u,v)) printf("Yes\n");
			else printf("No\n");
		}else if(cmd[0]=='C'){
			scanf("%d %d",&u,&v);
			cnt++;
			from[cnt]=u;
			to[cnt]=v;
			T.cut(u,v);
		}else{
			scanf("%d",&u); 
			T.link(from[u],to[u]);
		}
	}
}


