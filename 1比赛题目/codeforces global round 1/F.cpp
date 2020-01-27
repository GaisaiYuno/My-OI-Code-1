#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 500005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
vector<pair<int,int> >E[maxn];
int n,t;
int cnt=0;
int l[maxn],r[maxn];
long long dis[maxn];
void dfs1(int x,int fa){
	l[x]=++cnt;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].first;
		if(y!=fa){
			dis[y]=dis[x]+E[x][i].second;
			dfs1(y,x);
		}
	}
	r[x]=cnt;
}

struct node{
	int l;
	int r;
	long long mark;
	long long v;
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].v=min(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r){
		tree[pos].mark=tree[pos].v=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void push_down(int pos){
	if(tree[pos].mark){
		tree[pos<<1].mark+=tree[pos].mark;
		tree[pos<<1|1].mark+=tree[pos].mark;
		tree[pos<<1].v+=tree[pos].mark;
		tree[pos<<1|1].v+=tree[pos].mark;
		tree[pos].mark=0;
	}
}
void update(int L,int R,long long v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		tree[pos].v+=v;
		tree[pos].mark+=v;
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid)  update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
}
long long query(int L,int R,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	long long ans=INF;
	if(L<=mid)  ans=min(ans,query(L,R,pos<<1));
	if(R>mid) ans=min(ans,query(L,R,pos<<1|1));
	return ans;
}

struct range{
	int l;
	int r;
	long long ans;
	int id;
	range(){
		
	}
	range(int L,int R,int i){
		l=L;
		r=R;
		id=i;
		ans=0;
	}
	void debug(){
		printf("[%d,%d]",l,r);
	}
};
vector<range>q[maxn];

void dfs2(int x,int fa){
	for(int i=0;i<q[x].size();i++){
		q[x][i].ans=query(q[x][i].l,q[x][i].r,1);
	}
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].first;
		int len=E[x][i].second;
		if(y!=fa){
			update(l[y],r[y],-len,1);
			if(l[y]>1) update(1,l[y]-1,len,1);
			if(r[y]<n) update(r[y]+1,n,len,1); 
			dfs2(y,x); 
			update(l[y],r[y],len,1);
			if(l[y]>1) update(1,l[y]-1,-len,1);
			if(r[y]<n) update(r[y]+1,n,-len,1); 
		}
	}
}

long long ans[maxn];
int main(){
	int u,v,w,x,ll,rr;
	scanf("%d %d",&n,&t);
	for(int i=2;i<=n;i++){
		scanf("%d %d",&v,&w);
		E[v].push_back(make_pair(i,w));
		E[i].push_back(make_pair(v,w));
	}
	for(int i=1;i<=n;i++){
		sort(E[i].begin(),E[i].end());
	} 
	for(int i=1;i<=t;i++){
		scanf("%d %d %d",&x,&ll,&rr);
		q[x].push_back(range(ll,rr,i)); 
	}
	dfs1(1,0);
	build(1,n,1);
	for(int i=1;i<=n;i++){
		if(l[i]==r[i]) update(l[i],l[i],dis[i],1);
		else update(l[i],l[i],INF,1);
	}
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<q[i].size();j++){
			ans[q[i][j].id]=q[i][j].ans;
		}
	}
	for(int i=1;i<=t;i++){
		printf("%I64d\n",ans[i]);
	}
}

