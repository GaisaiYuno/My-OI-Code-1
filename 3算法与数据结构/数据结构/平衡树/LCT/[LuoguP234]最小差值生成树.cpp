#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<utility>
#define maxn 50000
#define maxm 200000
#define INF 0x3f3f3f3f
using namespace std;
int n,m,p;
struct edge{
	int from;
	int to;
	int len;
	friend bool operator < (edge p,edge q){
		return p.len<q.len;
	}
}E[maxm+5];



struct link_cut_tree{
#define fa(x) (tree[x].fa)
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1]) 
	struct node{
		int fa;
		int ch[2];
		int revm;
		int id;
		int minid;
	}tree[maxn+maxm+5];
	inline bool is_root(int x){
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x){
		return rson(fa(x))==x;
	}
	void push_up(int x){
		tree[x].minid=tree[x].id;
		if(E[tree[lson(x)].minid].len<E[tree[x].minid].len) tree[x].minid=tree[lson(x)].minid;
		if(E[tree[rson(x)].minid].len<E[tree[x].minid].len) tree[x].minid=tree[rson(x)].minid;
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
		return tree[y].minid;
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


bool unused[maxm+5];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&E[i].from,&E[i].to,&E[i].len);
	}
	sort(E+1,E+1+m);
	E[0].len=INF;
	for(int i=1;i<=n+m;i++){
		if(i<=n) T.tree[i].id=0;
		else T.tree[i].id=i-n;
	}
	int ptr=1;
	int ecnt=0;//当前树上边的个数 
	int ans=INF;
	for(int i=1;i<=m;i++){
		int x=E[i].from,y=E[i].to;
		if(x==y){
			unused[i]=1;
			continue;
		}
		if(T.find_root(x)!=T.find_root(y)){
			T.Add_edge(i);
			ecnt++;
		}else{
			int last=T.Query_edge(x,y);//每次删掉最小的边 
			unused[last]=1;
			T.Del_edge(last);
			T.Add_edge(i);
		}
		while(unused[ptr]&&ptr<=i) ptr++;
		if(ecnt>=n-1) ans=min(ans,E[i].len-E[ptr].len);//因为排过序，所以可以直接O(1)求出最小值 
	}
	printf("%d\n",ans);
}

