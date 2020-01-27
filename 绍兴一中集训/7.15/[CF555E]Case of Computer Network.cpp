#include<iostream>
#include<cstdio>
#include<cstring> 
#include<cmath>
#include<stack>
#include<queue>
#define maxn 200000
#define maxlogn 22
#define maxm 200000
using namespace std;
int n,m,q;
struct graph{
	struct edge{
		int from;
		int to;
		int next;
	}E[maxn*2+5];
	int head[maxn+5];
	int sz=1;
	void add_edge(int u,int v){
		sz++;
		E[sz].from=u;
		E[sz].to=v;
		E[sz].next=head[u];
		head[u]=sz;
	}
}G,T;

int tim;
int is_bridge[maxm*2+5];
int low[maxn+5],dfn[maxn+5];
void tarjan(int x,int in_edge){//tarjan求出桥 
	dfn[x]=++tim;
	low[x]=dfn[x];
	for(int i=G.head[x];i;i=G.E[i].next){
		int y=G.E[i].to;
		if(!dfn[y]){
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y]){
				is_bridge[i]=is_bridge[i^1]=1;
			}
		}else if(i!=(in_edge^1)){
			low[x]=min(low[x],dfn[y]);
		}
	}
	
}

int newn;
int vis[maxn+5],bel[maxn+5];
void get_e_dcc(int x,int mark){//求出边-双联通分量 
	vis[x]=1;
	bel[x]=mark;
	for(int i=G.head[x];i;i=G.E[i].next){
		int y=G.E[i].to;
		if(!vis[y]&&!is_bridge[i]){
			get_e_dcc(y,mark);
		}
	}
} 
void make_new_graph(){//缩点，把图变成树 
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i,0);
	}
	newn=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			newn++;
			get_e_dcc(i,newn);
		}
	}
	for(int i=2;i<=G.sz;i++){
		int u=G.E[i].from;
		int v=G.E[i].to;
		if(is_bridge[i]){
			T.add_edge(bel[u],bel[v]);
//			printf("%d %d\n",bel[u],bel[v]);
		}
	}
}

int log2n;
int deep[maxn+5];
int anc[maxn+5][maxlogn+5];
int tree_id[maxn+5];
void pre_lca(int x,int fa,int id){
	tree_id[x]=id;
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=T.head[x];i;i=T.E[i].next){
		int y=T.E[i].to;
		if(y!=fa){
			pre_lca(y,x,id);
		}
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]) x=anc[x][i];
	}
	if(x==y) return x;
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
int upd[maxn+5],downd[maxn+5];//边向上和向下标记 
void add_route(int x,int y){//树上差分 
	upd[x]++;
	downd[y]++;
	int lc=lca(x,y);
	upd[lc]--;
	downd[lc]--;
}
bool flag=true;
void get_sum(int x,int fa){
	for(int i=T.head[x];i;i=T.E[i].next){
		int y=T.E[i].to;
		if(y!=fa){
			get_sum(y,x);
			upd[x]+=upd[y];
			downd[x]+=downd[y];
		}
	}
	if(upd[x]>0&&downd[x]>0) flag=false;
} 
int main(){
	int u,v;
	scanf("%d %d %d",&n,&m,&q);
	log2n=log2(n)+1;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		G.add_edge(u,v);
		G.add_edge(v,u);
	}
	make_new_graph();
	for(int i=1;i<=newn;i++){
		if(!deep[i]) pre_lca(i,0,i);//原图可能不联通，缩点后会变成森林 
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&v);
		add_route(bel[u],bel[v]);
		if(tree_id[bel[u]]!=tree_id[bel[v]]){
			//如果不联通，那么直接输出No 
			printf("No\n");
			return 0;
		}
	}
	for(int i=1;i<=newn;i++){
		if(deep[i]==1) get_sum(i,0);
	} 
	if(flag) printf("Yes\n");
	else printf("No\n");
}

