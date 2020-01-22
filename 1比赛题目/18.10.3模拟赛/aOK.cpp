#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int len;
	int next;
	edge(){
		
	}
	edge(int u,int v,int w,int hd){
		from=u;
		to=v;
		len=w;
		next=hd;
	}
	friend bool operator <(edge a,edge b){
		return a.len>b.len;
	}
}E[maxn<<1];
int siz=0;
int head[maxn];
void add_edge(int u,int v,int w){
	siz++;
	E[siz]=edge(u,v,w,head[u]);
	head[u]=siz;
}

struct query{
	int x;
	int k;
	int id;
	friend bool operator <(query a,query b){
		return a.k>b.k;
	}	
}q[maxn];

int fa[maxn];
int sz[maxn];
inline int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
		sz[fy]+=sz[fx];
	}
}

int ans[maxn];
int main(){
	int u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
	}
	sort(E+1,E+1+n-1);//把边从小到大排序 
	for(int i=1;i<=m;i++){
		scanf("%d %d",&q[i].k,&q[i].x);
		q[i].id=i;
	}
	sort(q+1,q+1+m);//询问离线，按k排序 
	int num=1;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=m;i++){//对于每个询问k，将边权>=k的边加入图，则加入结束后与原来的点联通的点的个数（即集合大小）就是答案 
		while(num<=n-1&&E[num].len>=q[i].k){
			merge(E[num].from,E[num].to);
			num++;
		} 
		ans[q[i].id]=sz[find(q[i].x)]-1;
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
}
