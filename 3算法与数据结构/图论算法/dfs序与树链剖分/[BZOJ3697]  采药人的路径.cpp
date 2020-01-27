#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000 
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxn*2+5];
int esz=1;
int head[maxn*2+5];
void add_edge(int u,int v,int w){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].len=w;
	E[esz].next=head[u];
	head[u]=esz;
}

int root=0;
int sum;
bool vis[maxn+5];
int sz[maxn+5];
int f[maxn+5];
void get_root(int x,int fa){
	sz[x]=1;
	f[x]=0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]){
			get_root(y,x);
			sz[x]+=sz[y];
			f[x]=max(f[x],sz[y]);
		}
	}
	f[x]=max(f[x],sum-sz[x]);
	if(f[x]<f[root]) root=x;
}
/*
定义0边权为-1，1边权为1.从分治中心开始，从上到下开始前缀
我们发现，两条路径能合并，当且仅当有一条路径上存在休息点，或者两条路径的长度和为相反数 
我们计A[i]为无休息点的，值为i的个数
计B[i]为有休息点的，值为i的个数
那么统计答案时，一个点u的贡献就是A[-dist[x]]+B[-dist[x]]
*/
int spcnt=0; 
int sza,szb;
struct arr {
    int cnt[maxn *2+5];
    inline int & operator [] (const int index) { 
		return cnt[index + maxn]; 
	}
} cnta,cntb,mark;//记录x父节点到当前分治中心的dist值出现情况 
int dista[maxn+5],distb[maxn+5];

void get_dist(int x,int fa,int d){
	if(mark[d]){//如果父节点到当前分治中心有dist值为d的点，那这两个点之间一定存在一个休息点 
		//但是有些B类到分治中心的路径上只有分治中心的值是等于B的
		//这个时候就会计算多余 
		if(d==0&&mark[d]==1) spcnt++; //只有分治中心的值(0)是等于B的 
		cntb[d]++;
		distb[++szb]=d;
	}else{
		cnta[d]++;
		dista[++sza]=d;	
	}
	mark[d]++;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]) get_dist(y,x,d+E[i].len);
	} 
	mark[d]--;
}
long long calc(int x,int d){
	if(d){
		dista[++sza]=0;
		mark[0]++;
	}
	get_dist(x,0,d);
	if(d) mark[0]--;
	long long ansa=0,ansb=0;
	if(d==0) ansa-=spcnt;//只要正着算的时候判重一次 
	for(int i=1;i<=szb;i++){
		ansa+=cnta[-distb[i]];
		ansb+=cntb[-distb[i]];
		if(distb[i]==0) ansb--; 
	}
	ansb/=2;
	for(int i=1;i<=sza;i++) cnta[dista[i]]=0;
	for(int i=1;i<=szb;i++) cntb[distb[i]]=0;
	sza=szb=0;
	spcnt=0;
	return ansa+ansb;
}

long long ans;
void solve(int x){
	vis[x]=1;
	ans+=calc(x,0);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			ans-=calc(y,E[i].len);
			root=0;
			sum=sz[y];
			f[root]=n+1;
			get_root(y,0);
			solve(root);
		}
	}
}

int main(){
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		if(w==1){
			add_edge(u,v,1);
			add_edge(v,u,1);
		}else{
			add_edge(u,v,-1);
			add_edge(v,u,-1);
		}
	}
	root=0;
	sum=n;
	f[root]=n+1;
	get_root(1,0);
	solve(root); 
	printf("%lld\n",ans);
}
