#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#define maxn 200005
#define maxm 200005
#define maxlog 32
using namespace std;
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

int tim,cnt,newn;
int dfn[maxn];
int low[maxn];
int cut[maxn];
int new_id[maxn]; 
int belong[maxn];
stack<int>s;
vector<int>v_dcc[maxn];
void tarjan(int x){
	int flag=0;
	dfn[x]=low[x]=++tim;
	s.push(x);
	for(int i=G.head[x];i;i=G.E[i].next){
		int y=G.E[i].to;
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<=low[y]){
				flag++;
				if(x!=1||flag>1) cut[x]=1;
				cnt++;
				int z;
				do{
					z=s.top();
					s.pop();
					v_dcc[cnt].push_back(z);
				}while(z!=y);
				v_dcc[cnt].push_back(x);
			} 
		}else low[x]=min(low[x],dfn[y]);
	}
}

void graph_to_tree(){
	tim=cnt=0;
	tarjan(1);
	newn=cnt;
	for(int i=1;i<=n;i++){
		if(cut[i]){
			belong[i]=++newn;
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=0;j<v_dcc[i].size();j++){
			int x=v_dcc[i][j];
			if(cut[x]){
				T.add_edge(i,belong[x]);
				T.add_edge(belong[x],i);
			}
			else belong[x]=i;
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
	int l=lca(u,v);
	tree_count[l]--;
	tree_count[anc[l][0]]--;
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
	int u,v,nu,nv;
	n=qread();
	m=qread();
	q=qread();
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		G.add_edge(u,v);
		G.add_edge(v,u);
	}
	graph_to_tree();
	lca_init(1,0);
	for(int i=1;i<=q;i++){
		u=qread();
		v=qread();
		nu=belong[u];
		nv=belong[v];
		add_route(nu,nv);
		if(!cut[u]) graph_count[u]++;
		if(!cut[v]) graph_count[v]++;
	}
	sum_up(1,0);
	for(int i=1;i<=n;i++){
		if(cut[i]){
			graph_count[i]=tree_count[belong[i]];
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",graph_count[i]);
	}
}
