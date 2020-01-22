#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 100000
using namespace std;
int n,q;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int log2n;
int tim=0;
int lb[maxn+5],rb[maxn+5];
int deep[maxn+5];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	lb[x]=++tim;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
	rb[x]=tim;
}

struct segment_tree{
	struct node{
		int l;
		int r;
		int v;
		int mark;
		int len(){
			return r-l+1;
		}
	}tree[maxn*4+5];
	void push_up(int pos){
		if(deep[tree[pos<<1].v]<deep[tree[pos<<1|1].v]) tree[pos].v=tree[pos<<1].v;
		else tree[pos].v=tree[pos<<1|1].v;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r){
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void push_down(int pos){
		if(tree[pos].mark){
			if(deep[tree[pos].mark]>deep[tree[pos<<1].mark]) tree[pos<<1].mark=tree[pos].mark;
			if(deep[tree[pos].mark]>deep[tree[pos<<1].v]) tree[pos<<1].v=tree[pos].mark;
			if(deep[tree[pos].mark]>deep[tree[pos<<1|1].mark]) tree[pos<<1|1].mark=tree[pos].mark;
			if(deep[tree[pos].mark]>deep[tree[pos<<1|1].v]) tree[pos<<1|1].v=tree[pos].mark;
			tree[pos].mark=0;
		}
	}
	void update(int L,int R,int pt,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			if(deep[tree[pos].v]<deep[pt]){
				tree[pos].v=pt;
				tree[pos].mark=pt;
			}
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,pt,pos<<1);
		if(R>mid) update(L,R,pt,pos<<1|1);
		push_up(pos);
	}
	int query(int qp,int pos){
		if(tree[pos].l==tree[pos].r){
			return tree[pos].v;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(qp<=mid) return query(qp,pos<<1);
		else return query(qp,pos<<1|1);
	}
}T;


int main(){
	char op[2];
	int num;
	int u,v;
	scanf("%d %d",&n,&q);
	log2n=log2(n)+1;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	T.build(1,n,1);
	dfs(1,0);
	T.update(lb[1],rb[1],1,1);
	for(int i=1;i<=q;i++){
		scanf("%s",op);
		scanf("%d",&num);
		if(op[0]=='C'){
			T.update(lb[num],rb[num],num,1);
		}else{
			printf("%d\n",T.query(lb[num],1));
		}
	}
}
