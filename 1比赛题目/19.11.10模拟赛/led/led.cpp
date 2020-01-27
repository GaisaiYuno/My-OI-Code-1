#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 10000
#define maxk 20
#define maxb 2000000
#define maxm 1000000
#define INF 0x3f3f3f3f
#define rg register
using namespace std;
inline void qread(int &x){
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
	x=x*sign;
}

int t;
int n,k,l;
int mk[maxn+5];
int d[maxn+5];
int a[maxn+5];
int sz=0;
int bin_id[maxn+5];
int hash_id[maxn+5];
int dp[maxb+5];


struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxm*2+5];
int esz=1;
int head[maxn+5];
void add_edge(int u,int v,int w){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	E[esz].len=w;
	head[u]=esz;
}
struct node{
	int id;
	int dist;
	node(){
		
	}
	node(int _id,int _dist){
		id=_id;
		dist=_dist;
	}
	friend bool operator < (node p,node q){
		return p.dist>q.dist;
	}
};
void dijkstra(int s,int *dist){
	static int vis[maxn+5];
	priority_queue<node>q;
	for(rg int i=1;i<=n+1;i++){
		vis[i]=0;
		dist[i]=INF;
	}
	dist[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		rg int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(rg int i=head[x];i;i=E[i].next){
			rg int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len){
				dist[y]=dist[x]+E[i].len;
				q.push(node(y,dist[y]));
			}
		}
	}	
}
int dist[maxk+5][maxn+5];//第i个差分的位置到数组里位置i的距离 
void get_dist(){
	for(rg int i=1;i<=n+1;i++){//由于差分,下标n+1也要用到 
		for(rg int j=1;j<=l;j++){
			if(i+a[j]<=n+1) add_edge(i,i+a[j],1);
			if(i-a[j]>=1) add_edge(i,i-a[j],1);
		}
	}
	for(int i=1;i<=sz;i++){
		dijkstra(hash_id[i],dist[i]);
	}
}
inline int calc(int x,int y){
	y=hash_id[y+1];
	return dist[x+1][y];
}	

int dfs(int s){
	if(s==0) return 0;
	if(dp[s]!=INF) return dp[s];
	int ans=INF;
	for(int i=0;i<sz;i++){
		if(s&(1<<i)){
			for(int j=i+1;j<sz;j++){
				if(s&(1<<j)) ans=min(ans,dfs(s^(1<<i)^(1<<j))+calc(i,j));
			}
			break;//答案与顺序无关,每次删除一个 
		}
	}
	dp[s]=ans;
	return dp[s];
} 
void ini(){
	memset(mk,0,sizeof(mk));
	memset(d,0,sizeof(d));
	sz=0;
	memset(bin_id,0,sizeof(bin_id));
	memset(hash_id,0,sizeof(hash_id));
	memset(dp,0x3f,sizeof(dp));
	esz=0;
	memset(head,0,sizeof(head));
}
int main(){
//	freopen("led.ans","w",stdout);
	int x;
	int t;
	qread(t);
	while(t--){
		ini();
		qread(n);
		qread(k);
		qread(l);
		for(int i=1;i<=k;i++){
			qread(x);
			mk[x]=1;
		}
		for(int i=1;i<=n+1;i++) d[i]=mk[i]^mk[i-1];//翻转，对应的是异或和 
		for(int i=1;i<=l;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+l);
		l=unique(a+1,a+1+l)-a-1;
		for(int i=1;i<=n+1;i++){
			if(d[i]!=0){
				bin_id[i]=++sz;
				hash_id[bin_id[i]]=i;
			}
		}
		get_dist();
//		work_dp();
		int ans=dfs((1<<sz)-1);
//		int ans=work_dp();
		if(ans!=INF) printf("%d\n",ans);
		else printf("-1\n"); 
	}
	
}
/*
2
10 8 2
1 2 3 5 6 7 8 9
4 6
3 2 1
1 2
3

1
10 5 1
2 4 6 9 10
1
*/
