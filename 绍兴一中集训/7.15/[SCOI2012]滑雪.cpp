//https://www.luogu.org/problemnew/show/P2573
/*
先从1开始bfs一遍 ，去掉不合法的边
然后重新建图，跑最小生成树 
加上了高度相等的点后，每一层都是无向边，要搞最小生成树
考虑这样做：先把最高层做最小生成树缩成一个点，再把这个点加入低一层做下一层的最小生成树
具体实现时只需kruskal排序时以边指向点的高度为第一关键字对边排序
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 100000
#define maxm 1000000
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
	int len;
};
struct graph{
	edge E[maxm*2+5];
	int head[maxn+5];
	int sz;
	void add_edge(int u,int v,int w){
		sz++;
		E[sz].from=u;
		E[sz].to=v;
		E[sz].next=head[u];
		E[sz].len=w;
		head[u]=sz;
	}
	graph(){
		sz=0;
	}
}G1,G2;
int h[maxn+5];

queue<int>q;
int vis[maxn+5];
int bfs(){
	int cnt=0;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cnt++;
		for(int i=G1.head[x];i;i=G1.E[i].next){
			int y=G1.E[i].to;
			G2.add_edge(x,y,G1.E[i].len);
			if(!vis[y]){
				vis[y]=1;
				q.push(y);
				
			}
		}
	}
	return cnt;
}


struct disjoint_set{
	int fa[maxn];
	int find(int x){
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy) fa[fx]=fy;
	}
	void ini(int n){
		for(int i=1;i<=n;i++) fa[i]=i;
	}
}S;

bool cmp(edge p,edge q){
	if(h[p.to]==h[q.to]) return p.len<q.len;	
	else return h[p.to]>h[q.to];
}
long long kruskal(){
	long long ans=0;
	S.ini(n);
	sort(G2.E+1,G2.E+1+G2.sz,cmp);
	for(int i=1;i<=G2.sz;i++){
		int x=G2.E[i].from;
		int y=G2.E[i].to;
		if(S.find(x)!=S.find(y)){
			ans+=G2.E[i].len;
			S.merge(x,y);
		}
	}
	return ans;
}

int main(){
	int u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		if(h[u]>=h[v]) G1.add_edge(u,v,w);
		if(h[u]<=h[v]) G1.add_edge(v,u,w);
	}
	printf("%d ",bfs());
	printf("%lld\n",kruskal());
}

