#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1005
#define maxm 2005
#define mod 1000000007
#define maxlog 32
using namespace std;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		k>>=1;
	}
	return ans;
}

int n,m;
long long X;
struct graph{
	struct edge{
		int from;
		int to;
		long long len;
		int next;	
		edge(){
			
		}
		edge(int u,int v,long long w,int hd){
			from=u;
			to=v;
			len=w;
			next=hd;
		}
		friend bool operator < (edge x,edge y){
			return x.len<y.len;
		} 
	}E[maxm<<1];
	int sz;
	int head[maxn];
	void add_edge(int u,int v,long long w){
		sz++;
		E[sz]=edge(u,v,w,head[u]);
		head[u]=sz;
	}
	graph(){
		sz=0;
		memset(head,0,sizeof(head));
	}
}G,T;
int log2n;
int deep[maxn];
int anc[maxn][maxlog];
long long maxv[maxn][maxlog]; 
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	for(int i=T.head[x];i;i=T.E[i].next){
		int y=T.E[i].to;
		if(y!=fa){
			anc[y][0]=fa;
			maxv[y][0]=T.E[i].len;
			for(int j=1;j<=log2n;j++){
				anc[y][j]=anc[anc[y][j-1]][j-1];
				maxv[y][j]=max(maxv[y][j-1],maxv[anc[y][j-1]][j-1]);
			}
			dfs(y,x);
		}
	}
}

long long query(int x,int y){
	long long ans=0;
	if(deep[x]<deep[y])swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			ans=max(ans,maxv[x][i]);
			x=anc[x][i];
		}
	}
	if(x==y) return ans;
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			ans=max(ans,maxv[x][i]);
			ans=max(ans,maxv[y][i]);
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	ans=max(ans,maxv[x][0]);
	ans=max(ans,maxv[y][0]);
	return ans;
} 

int fa[maxn];
inline int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int cnt_mst;
int cnt_small;
int cnt_equl;
int cnt_large;
int is_mst[maxm<<1];
long long kruskal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(G.E+1,G.E+1+m);
	int x,y,fx,fy;
	long long ans=0;
	for(int i=1;i<=m;i++){
		x=G.E[i].from;
		y=G.E[i].to;
		fx=find(x);
		fy=find(y);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=G.E[i].len;
			cnt_mst++;
			is_mst[i]=1;
			T.add_edge(x,y,G.E[i].len);
			T.add_edge(y,x,G.E[i].len);
		}
	}
	deep[1]=1;
	dfs(1,0);
	for(int i=1;i<=m;i++){
		if(is_mst[i]) continue;
		x=G.E[i].from;
		y=G.E[i].to;
		if(query(x,y)==G.E[i].len){
			is_mst[i]++;
			cnt_mst++;
		}
	}
	return ans;
} 

long long solve(){
	long long sum=kruskal();
//	printf("%lld\n",sum);
	if(X<sum) return 0;
	else if(X==sum){
		long long ans=1;
		ans=ans*(fast_pow(2,cnt_mst)-2)%mod;
		ans=ans*(fast_pow(2,m-cnt_mst))%mod;
		return (ans+mod)%mod;
	}else{
		long long maxv;
		int x,y;
		long long ans=1;
		for(int i=1;i<=m;i++){
			if(is_mst[i]) continue;
			x=G.E[i].from;
			y=G.E[i].to;
			maxv=query(x,y);
			if(sum-maxv+G.E[i].len==X) cnt_equl++;
			if(sum-maxv+G.E[i].len<X) cnt_small++;
			if(sum-maxv+G.E[i].len>X) cnt_large++; 
		}
//		printf("%d+%d=%d %d %d\n",cnt_mst,cnt_small,cnt_mst+cnt_small,cnt_equl,cnt_large); 
		ans=fast_pow(2,cnt_large)%mod;
		ans=(ans*2)%mod*(fast_pow(2,cnt_equl)-1)%mod;
		ans=(ans+mod)%mod;
		return ans;
	}
}
int main(){
//	freopen("t12.in", "r", stdin);
	int u,v;
	long long w;
	scanf("%d %d %lld",&n,&m,&X);
	log2n=log2(n)+1;
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&u,&v,&w);
		G.add_edge(u,v,w);
	}
	printf("%lld\n",solve());
} 
