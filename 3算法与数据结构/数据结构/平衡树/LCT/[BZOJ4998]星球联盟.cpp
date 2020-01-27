#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000 
using namespace std;
struct LCT{
	int bel[maxn+5];
	int con[maxn+5];
	int find_bel(int x){
		if(bel[x]==x) return x;
		else return bel[x]=find_bel(bel[x]);
	}
	int find_con(int x){
		if(con[x]==x) return x;
		else return con[x]=find_con(con[x]);
	}
	void merge_con(int x,int y){
		con[find_con(x)]=find_con(y);
	}
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
#define fa(x) (tree[x].fa)
	struct node{
		int ch[2];
		int fa;
		int revm;
		int cnt; 
		int sz;
	}tree[maxn+5];
	
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+tree[x].cnt;
	}
	inline bool is_root(int x){
		return !(lson(find_bel(fa(x)))==x||rson(find_bel(fa(x)))==x);
	}
	int check(int x){
		return rson(find_bel(fa(x)))==x;
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
		if(!is_root(x)) push_down_all(find_bel(fa(x)));
		push_down(x);
	}
	void rotate(int x){
		int y=find_bel(fa(x)),z=find_bel(fa(y)),k=check(x),w=tree[x].ch[k^1];
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
			int y=find_bel(fa(x));
			if(!is_root(y)){
				if(check(x)==check(y)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		push_up(x);
	}
	void access(int x){
		for(int y=0;x;y=x,x=find_bel(fa(x))){
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
		fa(x)=lson(y)=0;
		push_up(y);
	}
	void dfs_tree(int x,int f){
		bel[x]=f;
		push_down(x);
		if(lson(x)) dfs_tree(lson(x),f);
		if(rson(x)) dfs_tree(rson(x),f);
	}
	int shrink(int x,int y){
		split(x,y);
		int ans=tree[y].sz; 
		tree[y].cnt=ans;
		dfs_tree(y,y);
		lson(y)=0;
		return ans;
	}
	int query_sum(int x,int y){
		split(x,y);
		return tree[y].sz;
	} 
}T;

int n,m,p;
int merge(int x,int y){
	int fx=T.find_bel(x),fy=T.find_bel(y);
	if(fx==fy) return T.query_sum(fx,fx);
	else{
		if(T.find_con(fx)!=T.find_con(fy)){
			T.link(fx,fy);
			T.merge_con(fx,fy);
			return -1;
		}else{
			T.shrink(fx,fy);
			return T.query_sum(fy,fy);
		}
	}
}
int main(){
	int x,y;
	scanf("%d %d %d",&n,&m,&p);
	for(int i=1;i<=n;i++){
		T.bel[i]=T.con[i]=i;
		T.tree[i].cnt=T.tree[i].sz=1;
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		merge(x,y); 
	}
	for(int i=1;i<=p;i++){
		scanf("%d %d",&x,&y);
		int val=merge(x,y);
		if(val==-1) puts("No");
		else printf("%d\n",val);
	}
}

