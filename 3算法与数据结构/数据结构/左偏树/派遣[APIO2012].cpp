#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n;
long long m;
struct leftist_tree{
	int cnt;
	long long v[maxn];
	int l[maxn],r[maxn]; 
	int dist[maxn];
	int root[maxn];
	void New(int val){
		cnt++;
		v[cnt]=val; 
		root[cnt]=cnt;
	}
	int _merge(int x,int y){
		if(!x||!y) return x+y;
		if(v[x]<v[y]) swap(x,y);
		r[x]=_merge(r[x],y);
		if(dist[l[x]]<dist[r[x]]) swap(l[x],r[x]);
		dist[x]=dist[r[x]]+1;
		return x;
	}
	void merge(int x,int y){
		root[x]=_merge(root[x],root[y]);
	}
	long long top(int x){
		return v[root[x]]; 
	}
	void del(int x){
		root[x]=_merge(l[root[x]],r[root[x]]);
	}
}T;


struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

long long ans=0;
long long cost[maxn],lead[maxn];
long long sum[maxn],cnt[maxn];
void dfs(int x,int fa){
//	printf("dfs: node=%d\n",x);
	sum[x]=cost[x];
	cnt[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x); 
			sum[x]+=sum[y];
			cnt[x]+=cnt[y];
			T.merge(x,y);
//			printf("merge %d %d\n",x,y);
		} 
	}
	while(sum[x]>m){
//		printf("top %d cnt=%d\n",x,cnt[x]);
		sum[x]-=T.top(x);
//		printf("delete %d\n",x);
		T.del(x);
		cnt[x]--;
	}
	ans=max(ans,(long long)lead[x]*cnt[x]);
}

int main(){
#ifdef FILE_IO 
	freopen("3.in","r",stdin);
#endif
	int fa,root;
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%d %lld %lld",&fa,&cost[i],&lead[i]);
		if(fa==0){
			root=i;
		}else{
			add_edge(i,fa);
			add_edge(fa,i);
		}
		
	}
	for(int i=1;i<=n;i++){
		T.New(cost[i]);
	}
	dfs(root,0);
	printf("%lld\n",ans);
}


