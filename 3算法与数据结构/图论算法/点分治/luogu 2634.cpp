#include<iostream>
#include<cstdio>
using namespace std;
inline long long gcd(int a,int b){
	
}
int n;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn<<1];
int ptr=0;
int head[maxn];
void add_edge(int u,int v,int w){
	ptr++;
	E[ptr].from=u;
	E[ptr].to=v;
	E[ptr].len=w;
	E[ptr].next=head[u];
	head[u]=ptr;
}

int used[maxn];
int sz[maxn];
int maxsz[maxn];
int minv;
int root;
int tree_sz;
void get_root(int x,int fa){
	sz[x]=1;
	maxsz[x]=0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!used[i]){
			get_root(y,x);
			maxsz[x]=max(maxsz[x],sz[y]);
		}
	}
	maxsz[x]=max(tree_sz-maxsz[x],maxsz[x]);
	if(maxsz[x]<minv){
		minv=maxsz[x];
		root=x;
	}
}

int cnt[3];
void get_dis(int x,int fa,int d){
	cnt[d%mod]++;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!used[y]){
			get_dis(x,fa,(d+E[i].len)%3);
		}
	}
}
long long cal(int x,int len){
	cnt[0]=cnt[1]=cnt[2]=0;
	cal(x,0,len);
	long long tmp=2*sum[1]*sum[2]+sum[0]*sum[0];
	return tmp;
}

long long ans=0;
void divide(int r){
	used[r]=1;
	ans+=calc(r,0);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!used[y]){
			ans-=calc(r,E[i].len);
			minv=INF;
			root=0;
			tree_sz=sz[y];
			get_root(y,0);
			divide(root);
		}
	}
}

int main(){
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	} 
	minv=INF;
	root=0;
	tree_sz=n;
	ans=0;
	get_root(1,0);
	divide(root);
	
}
