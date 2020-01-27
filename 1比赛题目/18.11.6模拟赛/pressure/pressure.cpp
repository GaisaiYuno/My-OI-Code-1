//标准错误解法 
//v-DCC的缩点写挂了，只能写个e-DCC骗分 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#define maxn 100005
#define maxm 200005
#define maxlog 32
using namespace std;
struct my_pair{
	int f;
	int s;
	friend bool operator < (my_pair p,my_pair q){
		if(p.f==q.f) return p.s<q.s;
		else return p.f<q.f;
	}
	my_pair(){
		
	}
	my_pair(int x,int y){
		f=x;
		s=y;
	}
};
set<my_pair>S;
int n,m,q;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

struct graph {
	struct edge {
		int from;
		int to;
		int next;
	} E[maxm<<1];
	int head[maxn];
	int ecnt;
	void add_edge(int u,int v) {
		ecnt++;
		E[ecnt].from=u;
		E[ecnt].to=v;
		E[ecnt].next=head[u];
		head[u]=ecnt;
	}
	graph(){
		memset(head,0,sizeof(head));
		memset(E,0,sizeof(E));
		ecnt=1;
	}
};
graph G,T;

int tim;
int dfn[maxn];
int low[maxn];
int is_bridge[maxm<<1];
int on_bridge[maxn];
void tarjan(int x,int in_edge){
	dfn[x]=low[x]=++tim;
	for(int i=G.head[x];i;i=G.E[i].next){
		int y=G.E[i].to;
		if(!dfn[y]){
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y]){
				is_bridge[i]=is_bridge[i^1]=1;
			}
		}else if(i!=(in_edge^1))low[x]=min(low[x],dfn[y]);
	}
}

int cnt=0;
int belong[maxn];
void get_belong(int x,int c){
	belong[x]=c;
	for(int i=G.head[x];i;i=G.E[i].next){
		if(is_bridge[i]) continue;
		int y=G.E[i].to;
		if(!belong[y]){
			get_belong(y,c);
		}
	}
}

int edge_hash[maxm<<1];
int edge_id[maxn];
void graph_to_tree(){
	tarjan(1,0);
	for(int i=1;i<=n;i++){
		if(!belong[i]) get_belong(i,++cnt);
//		printf("belong[%d]=%d\n",i,belong[i]);  
	}
	for(int i=2;i<=G.ecnt;i++){
		if(is_bridge[i]){
			on_bridge[G.E[i].from]=1;
			on_bridge[G.E[i].to]=1;
			T.add_edge(belong[G.E[i].from],belong[G.E[i].to]);
//			printf("%d-%d\n",G.E[i].from,G.E[i].to);
			edge_hash[T.ecnt]=i;
		}
	}
}

int graph_count[maxn];
int tree_count[maxn];
int deep[maxn];
int anc[maxn][maxlog];
void lca_init(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=20;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=T.head[x];i;i=T.E[i].next){
		int y=T.E[i].to;
		if(y!=fa){
			edge_id[y]=i;
			lca_init(y,x);
		}
	}
}

int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

void add_route(int u,int v){
	tree_count[lca(u,v)]-=2;
	tree_count[u]++;
	tree_count[v]++; 
}

void sum_up(int x,int fa){
	for(int i=T.head[x];i;i=T.E[i].next){
		int y=T.E[i].to;
		if(y!=fa){
			sum_up(y,x);
			tree_count[x]+=tree_count[y];
		}
	}
}
int main() {
	freopen("pressure.in","r",stdin);
	freopen("pressure.out","w",stdout);
	int u,v;
	n=qread();
	m=qread();
	q=qread();
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		if(S.count(my_pair(u,v))) continue;
		G.add_edge(u,v);
		G.add_edge(v,u);
		S.insert(my_pair(u,v));
		S.insert(my_pair(v,u));
	}
	graph_to_tree();
	lca_init(1,0);
	for(int i=1;i<=q;i++){
		u=qread();
		v=qread();
		if(belong[u]!=belong[v]) add_route(belong[u],belong[v]);
		if(!on_bridge[u]) graph_count[u]++;
		if(!on_bridge[v]) graph_count[v]++;
	}
	sum_up(1,0);
	for(int i=2;i<=cnt;i++){
		u=G.E[edge_hash[edge_id[i]]].from;
		v=G.E[edge_hash[edge_id[i]]].to;
		graph_count[u]+=tree_count[i];
		graph_count[v]+=tree_count[i];
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",graph_count[i]);
	}
}
//Dedicated to Selina 
