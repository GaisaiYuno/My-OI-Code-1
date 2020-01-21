#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 200000
using namespace std;
struct link_cut_tree{
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
#define fa(x) (tree[x].fa)
	struct node{
		int ch[2];
		int fa;
		int sz;
		int revm;
	}tree[maxn+5];
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
	void link(int x,int y){
		make_root(x);
		fa(x)=y;
	}
	void cut(int x,int y){
		split(x,y);
		lson(y)=fa(x)=0;
		push_up(y);
	}
	int query(int x,int y){//查询x到y的路径长度，即split出来的子树大小-1 
		split(x,y);
		return tree[y].sz-1;
	}
}T;

int n,m;
int a[maxn+5];
//虚拟节点n+1表示被弹飞 
inline int get_nex(int x,int k){//找到被弹到的节点 
	if(x+k<=n) return x+k;
	else return n+1;
}

int main(){
	int cmd,x,k;
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++) T.tree[i].sz=1;
//	T.link(4,5);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		T.link(i,get_nex(i,a[i]));
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d",&x);
			x++;
			printf("%d\n",T.query(x,n+1));//查询x到n+1路径长度 
		}else{
			scanf("%d %d",&x,&k);
			x++;
			T.cut(x,get_nex(x,a[x]));
			a[x]=k;
			T.link(x,get_nex(x,a[x]));
		}
	}
	 
}

