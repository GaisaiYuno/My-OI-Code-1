#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
#define maxn 100000 
using namespace std;
int n,m,q;
pair<int,int>ed[maxn+5];
struct oper{
	pair<int,int>e;
	int type;
	int ans;
}p[maxn+5];
map< pair<int,int>,bool>is_del;

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
	}tree[maxn+5];
	void push_up(int x){
		
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
	void shrink(int x,int y){
		split(x,y);
		dfs_tree(y,y);
		lson(y)=0;
	}
}T;
void merge(int x,int y){
	int fx=T.find_bel(x);
	int fy=T.find_bel(y);
	if(fx==fy) return;
	else{
		if(T.find_con(fx)!=T.find_con(fy)){
			T.link(fx,fy);
			T.merge_con(fx,fy);
		}else T.shrink(fx,fy); 
	}
} 
int query(int x,int y){
	return T.find_bel(x)==T.find_bel(y);
} 
int main(){
	int u,v;
	char cmd[3];
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		T.bel[i]=T.con[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		if(u>v) swap(u,v);
		ed[i]=make_pair(u,v);
	}
	for(int i=1;i<=q;i++){
		scanf("%s %d %d",cmd,&u,&v);
		if(u>v) swap(u,v);
		p[i].e=make_pair(u,v);
		if(cmd[0]=='Z'){
			p[i].type=1;
			is_del[make_pair(u,v)]=1;
		}else{
			p[i].type=2; 
		} 
	}
	for(int i=1;i<=m;i++){
		if(!is_del.count(ed[i])) merge(ed[i].first,ed[i].second); 
	}
	for(int i=q;i>=1;i--){
		if(p[i].type==1) merge(p[i].e.first,p[i].e.second);
		else p[i].ans=query(p[i].e.first,p[i].e.second);
	} 
	for(int i=1;i<=q;i++){
		if(p[i].type==2){
			if(p[i].ans==1) puts("Yes");
			else puts("No");
		}
	}
}
 
