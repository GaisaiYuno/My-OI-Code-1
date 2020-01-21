#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<utility>
#define maxn 10000
#define maxc 10
using namespace std;
map< pair<int,int> ,int> edg;
int cnt[maxc][maxn+5];
int n,m,C,q;
int val[maxn+5];

struct LCT{
#define fa(x) (tree[x].fa)
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
	struct node{
		int ch[2];
		int fa;
		int val;
		int revm;
		int maxv;
	}tree[maxn+5];
	void push_up(int x){
		tree[x].maxv=max(max(tree[lson(x)].maxv,tree[rson(x)].maxv),tree[x].val);
	}
	inline bool is_root(int x){
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	int check(int x){
		return rson(fa(x))==x;
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
//以上为模板LCT	

	int query_route(int x,int y){
		split(x,y);
		return tree[y].maxv;
	}
	void update_val(int x,int val){
		make_root(x);
		tree[x].val=val;
		push_up(x);
	}
	bool is_connect(int x,int y){
		return find_root(x)==find_root(y);
	}
}T[maxc];
void update_node(int x,int y){
	for(int i=0;i<C;i++) T[i].update_val(x,y); 
}
void update_edge(int x,int y,int c){
	if(!edg.count(make_pair(x,y))){
		printf("No such edge.\n");
		return;
	}
	int now=edg[make_pair(x,y)];
	if((cnt[c][x]+1>2||cnt[c][y]+1>2)&&c!=now){
	//注意特判改的颜色和原来颜色相同的情况 
		printf("Error 1.\n");
		return;
	}
	if(T[c].is_connect(x,y)&&c!=now){
		printf("Error 2.\n");
		return;
	}
	
	printf("Success.\n");
	cnt[now][x]--;
	cnt[now][y]--;
	T[now].cut(x,y);
	cnt[c][x]++;
	cnt[c][y]++;
	T[c].link(x,y);
	
	edg[make_pair(x,y)]=edg[make_pair(y,x)]=c;
}

int query(int c,int x,int y){
	if(!T[c].is_connect(x,y)) return -1;
	else return T[c].query_route(x,y);
}
int main(){
	int cmd;
	int u,v,w;
	scanf("%d %d %d %d",&n,&m,&C,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		for(int j=0;j<C;j++) T[j].tree[i].val=val[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		edg[make_pair(u,v)]=edg[make_pair(v,u)]=w;
		T[w].link(u,v);
		cnt[w][u]++;
		cnt[w][v]++;
	}
	for(int i=1;i<=q;i++){
		scanf("%d",&cmd);
		if(cmd==0){
			scanf("%d %d",&u,&v);
			update_node(u,v);
		}else if(cmd==1){
			scanf("%d %d %d",&u,&v,&w);
			update_edge(u,v,w);
		}else{
			scanf("%d %d %d",&w,&u,&v);
			printf("%d\n",query(w,u,v));
		}
	}
}
