//http://codeforces.com/problemset/problem/464/E
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue> 
#include<cmath>
#define maxn 500000
#define maxm 500000
#define maxlog 25
#define mod 1000000007
#define INF 0x3f3f3f3f
using namespace std;
int n,m,dg;//dg是二进制位数 
long long pow2[maxn+5];
struct segment_tree{//主席树维护二进值位 ,下标[1,n]从低位到高位存储二进制 
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		long long sum;//二进制值取模mod之后的值
		//既可以用来更新答案，也可以当做hash判断两端二进制是否相等 
	}tree[maxn*maxlog+5];
	int ptr;
	void push_up(int x,int l,int r){
		int mid=(l+r)>>1;
		tree[x].sum=tree[lson(x)].sum+tree[rson(x)].sum*pow2[mid-l+1]%mod;
		tree[x].sum%=mod;
	}
	int insert(int &x,int last,int upos,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
		if(l==r){
			tree[x].sum^=1;//+1，1变0，0变1，进位等下再处理 
			return tree[last].sum;
		}
		int mid=(l+r)>>1;
		int res;
		if(upos<=mid){
			//upos<=mid,处理进位，[mid+1,r]对应的高位也会被进位，所以要递归下去修改 
			//考虑极端情况，xi都=1，那么需要进位O(m/2+m/4+m/8+...+1)≈O(m) 
			res=insert(tree[x].ls,tree[last].ls,upos,l,mid); 
			//如果res不等于0，说明之前[l,mid]就有值，要继续进位 
			if(res) res=insert(tree[x].rs,tree[last].rs,upos,mid+1,r);
		}else{
			res=insert(tree[x].rs,tree[last].rs,upos,mid+1,r);
		} 
		push_up(x,l,r);
		return res;
	}
	bool cmp(int x,int y,int l,int r){//比较x,y两棵主席树对应的二进制大小 
		if(l==r){
			return tree[x].sum<tree[y].sum;
		} 
		int mid=(l+r)>>1;
		if(tree[tree[x].rs].sum==tree[tree[y].rs].sum) return cmp(tree[x].ls,tree[y].ls,l,mid);//从高位到低位，高位相同就比低位
		else return cmp(tree[x].rs,tree[y].rs,mid+1,r); 
	}
#undef lson
#undef rson
}T;

struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxm*2+5];
int head[maxn+5];
int ecnt=1;
void add_edge(int u,int v,int w){
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].len=w;
	E[ecnt].next=head[u];
	head[u]=ecnt;
} 

struct heap_node{
	int id;
	int rt;//对应二进制主席树的树根 
	heap_node(){
		
	}
	heap_node(int _id,int _rt){
		id=_id;
		rt=_rt;
	}
	friend bool operator < (heap_node p,heap_node q){
		return !T.cmp(p.rt,q.rt,0,dg); 
	}
}; 
priority_queue<heap_node>q;
int vis[maxn+5];
int disrt[maxn+5];
int pre[maxn+5];
long long dijkstra(int s,int t){
	memset(disrt,0x3f,sizeof(disrt));
	disrt[s]=0;
	q.push(heap_node(s,disrt[s]));
	while(!q.empty()){
		heap_node x=q.top();
		q.pop();
		if(vis[x.id]) continue;
		vis[x.id]=1;
		for(int i=head[x.id];i;i=E[i].next){
			int y=E[i].to;
			int tmprt;
			T.insert(tmprt,disrt[x.id],E[i].len,0,dg);
			if(disrt[y]==INF||T.cmp(tmprt,disrt[y],0,dg)){
				disrt[y]=tmprt;
				pre[y]=i;
				q.push(heap_node(y,disrt[y]));
			}
		}
	}
	if(disrt[t]==INF) return -1;
	else return T.tree[disrt[t]].sum;
}

int cnt=0;
int res[maxn+5];
void get_ans(int s,int t){
	int x=t;
	while(x!=s){
		res[++cnt]=x;
		x=E[pre[x]].from;
	}
	res[++cnt]=x;
}

int main(){
	int u,v,w;
	int s,t;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
		dg=max(dg,w);
	}
	scanf("%d %d",&s,&t);
	
	dg+=log2(m)+1;//进位 
	pow2[0]=1;
	for(int i=1;i<=dg;i++) pow2[i]=pow2[i-1]*2%mod; 
	
	long long ans=dijkstra(s,t);
	printf("%I64d\n",ans);
	if(ans==-1) return 0;
	
	cnt=0;
	get_ans(s,t);
	printf("%d\n",cnt);
	for(int i=cnt;i>=1;i--){
		printf("%d ",res[i]);
	}
} 
