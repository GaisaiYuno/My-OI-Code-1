//https://www.luogu.com.cn/problem/P2147 
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 10000
using namespace std;
struct link_cut_tree{//orz Tarjan
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
#define fa(x) (tree[x].fa)
	struct node{
		int fa;
		int ch[2];
		bool revm;
	}tree[maxn+5];
	inline bool is_root(int x){
		return !(x==lson(fa(x))||x==rson(fa(x)));
	}
	inline int check(int x){
		return rson(fa(x))==x;
	}
	void push_up(int x){
		
	}
	void reverse(int x){
//		if(x==0) return;
		swap(lson(x),rson(x));
		tree[x].revm^=1;
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
	int find_root(int x){//找到x所在原树的根,并把它splay
		access(x);
		splay(x);
		while(lson(x)){
			push_down(x);
			x=lson(x);
		}
		splay(x);
		return x;
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
	bool query(int x,int y){
		if(find_root(x)==find_root(y)) return 1;
		else return 0;
	}
}T;

int n,m;
int main(){
	int u,v;
	char cmd[10];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%s %d %d",cmd,&u,&v);
		if(cmd[0]=='Q'){
			if(T.query(u,v)) printf("Yes\n");
			else printf("No\n");
		}else if(cmd[0]=='C'){
			T.link(u,v);
		}else{
			T.cut(u,v);
		}
	}
}

