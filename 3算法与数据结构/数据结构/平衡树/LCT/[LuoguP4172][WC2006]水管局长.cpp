#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<utility>
#define maxn 1000
#define maxm 100000
#define maxq 100000
using namespace std;
int n,m,p;
struct edge{
	int from;
	int to;
	int len;
	bool is_del;
	friend bool operator < (edge p,edge q){
		return p.len<q.len;
	}
}E[maxm+5];
map< pair<int,int> , int> id;

struct oper{
	int type;
	int x;
	int y;
	int id;
	int ans;
}q[maxq+5];

struct link_cut_tree{
#define fa(x) (tree[x].fa)
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1]) 
	struct node{
		int fa;
		int ch[2];
		int revm;
		int id;
		int maxid;
	}tree[maxn+maxm+5];
	inline bool is_root(int x){
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x){
		return rson(fa(x))==x;
	}
	void push_up(int x){
		tree[x].maxid=tree[x].id;
		if(E[tree[lson(x)].maxid].len>E[tree[x].maxid].len) tree[x].maxid=tree[lson(x)].maxid;
		if(E[tree[rson(x)].maxid].len>E[tree[x].maxid].len) tree[x].maxid=tree[rson(x)].maxid;
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
	void link(int x,int y){
		make_root(x);
		fa(x)=y;
	}
	void split(int x,int y){
		make_root(x);
		access(y);
		splay(y);
	}
	void cut(int x,int y){
		split(x,y);
		fa(x)=lson(y)=0;
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
	
	int Query_edge(int x,int y){
		split(x,y);
		return tree[y].maxid;
	}
	inline void Add_edge(int id){
		link(E[id].from,id+n);
		link(E[id].to,id+n);
	}
	inline void Del_edge(int id){
		cut(E[id].from,id+n);
		cut(E[id].to,id+n);
	}
}T;

void kruskal(){
	for(int i=1;i<=m;i++){
		if(!E[i].is_del){
			int x=E[i].from,y=E[i].to;
			if(T.find_root(x)==T.find_root(y)) continue;
//			printf("db: %d\n",id[make_pair(x,y)]);
			T.Add_edge(i);
		}
	}
}
int main(){
//	freopen("7.in","r",stdin); 
	scanf("%d %d %d",&n,&m,&p);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&E[i].from,&E[i].to,&E[i].len);
	}
	sort(E+1,E+1+m);
	for(int i=1;i<=m;i++){
		id[make_pair(E[i].from,E[i].to)]=id[make_pair(E[i].to,E[i].from)]=i;
	}
	for(int i=1;i<=p;i++){
		scanf("%d %d %d",&q[i].type,&q[i].x,&q[i].y);
		if(q[i].type==2){
			int t=id[make_pair(q[i].x,q[i].y)];
			q[i].id=t;
			E[t].is_del=1;
		}
	}
	for(int i=1;i<=n+m;i++){
		if(i<=n) T.tree[i].id=0;
		else T.tree[i].id=i-n;
	}
	kruskal();
	for(int i=p;i>=1;i--){
		int x=q[i].x,y=q[i].y;
		if(q[i].type==1){
			q[i].ans=E[T.Query_edge(x,y)].len;
		}else{
			int pre=T.Query_edge(x,y);
			int nex=q[i].id;
			if(E[pre].len>E[nex].len){
				T.Del_edge(pre);
				T.Add_edge(nex);
			} 
		}
	}
	for(int i=1;i<=p;i++){
		if(q[i].type==1) printf("%d\n",q[i].ans);
	}
}

