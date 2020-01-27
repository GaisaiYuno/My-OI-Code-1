#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 100005
using namespace std;
int down[maxn],up[maxn];//记录该节点的下方和上方节点编号 
struct edge_table{
	int from;
	int to;
	int next;
}edge[maxn<<1];
int head[maxn],used[maxn];
int edge_cnt;
int tot;
int n,m;
void add_edge(int u,int v){
	edge[edge_cnt].from=u;
	edge[edge_cnt].to=v;
	edge[edge_cnt].next=head[u];
	head[u]=edge_cnt;
	edge_cnt++;
}
void dfs(int u){
	tot++;
	down[u]=tot;
	used[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next){
		if(used[edge[i].to]) continue;
		dfs(edge[i].to);
	}
	up[u]=tot;
}

int tree[maxn<<2];
void push_up(int pos){
	tree[pos]=tree[pos<<1]+tree[pos<<1|1];
}
void build(int l,int r,int pos){
	if(l==r){
		tree[pos]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos); 
}
void update(int l,int r,int pos,int to_pos,int v){
	if(l==r){
		if(tree[pos]!=0) tree[pos]=0;
		else tree[pos]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(to_pos<=mid) update(l,mid,pos<<1,to_pos,v);
	else update(mid+1,r,pos<<1|1,to_pos,v);
	push_up(pos);
}
int query(int to_l,int to_r,int l,int r,int pos){
	if(to_l<=l&&to_r>=r){
		return tree[pos];
	}
	int mid=(l+r)>>1;
	int ans=0;
	if(to_l<=mid) ans+=query(to_l,to_r,l,mid,pos<<1);
	if(to_r>mid) ans+=query(to_l,to_r,mid+1,r,pos<<1|1);
	return ans; 
}
int main(){
	while(cin>>n){
		edge_cnt=0;
		int u,v;
		memset(used,0,sizeof(used));
		memset(head,-1,sizeof(head));
		memset(up,0,sizeof(up));
		memset(down,0,sizeof(down));
		for(int i=0;i<n-1;i++){
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		tot=0;
		dfs(1);
		build(1,n,1);
		char cmd;
		int x;
		cin>>m;
		while(m--){
			cin>>cmd;
			if(cmd=='C'){
				scanf("%d",&x);
			    update(1,n,1,down[x],1);
			} 
			else if(cmd=='Q'){
				scanf("%d",&x);
				if(down[x]>up[x]) swap(down[x],up[x]);
				printf("%d\n",query(down[x],up[x],1,n,1));
			} 
		}
	}
}
