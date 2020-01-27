#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define maxn 50005
#define mod 201314
using namespace std;
int n,q;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int ecnt=0;
void add_edge(int u,int v){
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}

int fa[maxn];
int son[maxn];
int sz[maxn];
int top[maxn];
int dfn[maxn];
void dfs1(int x,int f){
	sz[x]=1;
	fa[x]=f;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=f){
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
}
int cnt=0;
void dfs2(int x,int tp){
	dfn[x]=++cnt;
	top[x]=tp;
	if(son[x]) dfs2(son[x],tp);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,y);
		}
	}
}

struct node {
    int l;
    int r;
    long long mark;
    long long v;
    int len(){
        return r-l+1;
    }
} tree[maxn<<2];
void push_up(int pos) {
    tree[pos].v=(tree[pos<<1].v+tree[pos<<1|1].v)%mod;
}
void build(int l,int r,int pos) {
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].v=tree[pos].mark=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1);
}
void push_down(int pos){
    if(tree[pos].mark){
        tree[pos<<1].mark+=tree[pos].mark;
        tree[pos<<1].mark%=mod;
        tree[pos<<1].v+=tree[pos].mark*tree[pos<<1].len();
        tree[pos<<1].v%=mod;
        tree[pos<<1|1].mark+=tree[pos].mark;
        tree[pos<<1|1].mark%=mod;
        tree[pos<<1|1].v+=tree[pos].mark*tree[pos<<1|1].len();
        tree[pos<<1|1].v%=mod;
        tree[pos].mark=0; 
    }
}
void update(int L,int R,int v,int pos){
    if(L<=tree[pos].l&&R>=tree[pos].r){
        tree[pos].v+=(long long)v*tree[pos].len();
        tree[pos].v%=mod;
        tree[pos].mark+=v;
        tree[pos].mark%=mod;
        return;
    }
    push_down(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    if(L<=mid) update(L,R,v,pos<<1);
    if(R>mid) update(L,R,v,pos<<1|1);
    push_up(pos);
}
long long query(int L,int R,int pos){
    if(L<=tree[pos].l&&R>=tree[pos].r){
        return tree[pos].v;
    }
    push_down(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    long long ans=0; 
    if(L<=mid) ans+=query(L,R,pos<<1);
    if(R>mid) ans+=query(L,R,pos<<1|1);
    return ans%mod;
}
void change(int x,int v){
    while(x){
    	update(dfn[top[x]],dfn[x],v,1);
    	x=fa[top[x]];
	}
}

int get_sum(int x){
	long long ans=0;
	while(x){
		ans+=query(dfn[top[x]],dfn[x],1);
		ans%=mod;
		x=fa[top[x]];
	}
	return ans%mod;
}

vector<int>L[maxn];
vector<int>R[maxn];
int point[maxn];
long long ans[maxn]; 
int main(){
	int x,l,r,z;
	scanf("%d %d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		x++;
		add_edge(x,i);
		add_edge(i,x);
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d %d",&l,&r,&z);
		l++;
		r++;
		z++;
		point[i]=z;
		L[l].push_back(i);
		R[r].push_back(i);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,n,1); 
	for(int i=1;i<=n;i++){
		change(i,1);
//		printf("%d\n",query(1,1,1));
		for(int j=0;j<L[i+1].size();j++){
			ans[L[i+1][j]]-=get_sum(point[L[i+1][j]]);
//			printf("ans[%d]=%d\n",L[i+1][j],ans[L[i+1][j]]);
		}
		for(int j=0;j<R[i].size();j++){
			ans[R[i][j]]+=get_sum(point[R[i][j]]);
//			printf("ans[%d]=%d\n",R[i][j],ans[R[i][j]]);
		} 
	}	
	for(int i=1;i<=q;i++){
		printf("%lld\n",(ans[i]+mod)%mod);
	}
}
