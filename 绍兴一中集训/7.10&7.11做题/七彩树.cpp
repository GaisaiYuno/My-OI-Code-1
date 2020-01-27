#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define maxn 400000
#define maxlogn 32
using namespace std;
inline int qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}
int t,n,m;
int c[maxn+5];
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
int tim;
int anc[maxn+5][maxlogn+5];
int hash_dfn[maxn+5];
int deep[maxn+5];
int lb[maxn+5],rb[maxn+5];
int id[maxn+5];
int cmp(int x,int y){
	return deep[x]<deep[y];
}

void dfs(int x,int fa){
	tim++;
	lb[x]=tim;
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	hash_dfn[lb[x]]=x;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
	rb[x]=tim;
}

int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
struct per_segment_tree{
	//第i棵可持久化线段树维护deep<=i,且dfn在[l,r]内的节点的不同颜色个数 
	struct node{
		int ls;
		int rs;
		int cnt;
	}tree[maxn*maxlogn+5];
	int root[maxn+5];
	int ptr;
	void push_up(int x){
		tree[x].cnt=tree[tree[x].ls].cnt+tree[tree[x].rs].cnt;
	}
	void insert(int &x,int last,int upos,int uval,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
		if(l==r){
			tree[x].cnt+=uval;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) insert(tree[x].ls,tree[last].ls,upos,uval,l,mid);
		else insert(tree[x].rs,tree[last].rs,upos,uval,mid+1,r);
		push_up(x); 
	}
	int query(int x,int L,int R,int l,int r){
		if(x==0) return tree[x].cnt;
		if(L<=l&&R>=r){
			return tree[x].cnt;
		}
		int mid=(l+r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(tree[x].ls,L,R,l,mid);
		if(R>mid) ans+=query(tree[x].rs,L,R,mid+1,r);
		return ans;
	}
}T;

set<int>s[maxn+5];
void ini(){
	log2n=log2(n)+1;
	tim=0;
	sz=1;
	T.ptr=0;
	for(int i=1;i<=n;i++){
		anc[i][0]=0;
		c[i]=0;
		deep[i]=0;
		hash_dfn[i]=0;
		head[i]=0;
		id[i]=0;
		lb[i]=0;
		rb[i]=0;
		s[i].clear();
		T.root[i]=0;
	}
}
int main(){

	int u,v;
	qread(t);
	while(t--){
		
		qread(n);
		qread(m);
		ini();
		
		for(int i=1;i<=n;i++) qread(c[i]);
		for(int i=2;i<=n;i++){
			qread(u);
			add_edge(u,i);
			add_edge(i,u);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++) id[i]=i;
		sort(id+1,id+1+n,cmp);
		for(int i=1;i<=n;i++){
			int x=id[i];
			int pre=0,nex=0;
			T.insert(T.root[deep[x]],T.root[deep[id[i-1]]],lb[x],1,1,n);
			set<int>::iterator it=s[c[x]].lower_bound(lb[x]);
			if(it!=s[c[x]].begin()){
				set<int>::iterator it2=it;//不能直接--it,会影响下一个判断 
				pre=hash_dfn[*(--it2)];
				T.insert(T.root[deep[x]],T.root[deep[x]],lb[lca(pre,x)],-1,1,n);
				//x会对pre到x的路径上的点产生1的贡献，树上差分 
				//线段树里的每个店储存的都是差分值 
			}
			if(it!=s[c[x]].end()){
				nex=hash_dfn[*it];
				T.insert(T.root[deep[x]],T.root[deep[x]],lb[lca(x,nex)],-1,1,n);
			}
			//lca(pre,nex)上方的路径被多减了一次，加回来
			if(pre!=0&&nex!=0){
				T.insert(T.root[deep[x]],T.root[deep[x]],lb[lca(pre,nex)],1,1,n);
			} 
			s[c[x]].insert(lb[x]);
		}
		
		int last=0;
		int x,d;
		for(int i=1;i<=m;i++){
			qread(x);
			qread(d);
			x^=last;
			d^=last;
			last=T.query(T.root[min(deep[x]+d,deep[id[n]])],lb[x],rb[x],1,n);
			qprint(last);
			putchar('\n');
		}
	}
}
/*
1
5 6
2 1 2 4 4 
1 2 1 2 
1 2
4 1
4 1
2 1
3 1
2 2
*/

