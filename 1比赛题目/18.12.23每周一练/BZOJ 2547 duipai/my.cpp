#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#define maxn 2000005
#define maxm 2000005
using namespace std;
inline void qread(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

inline void qprint(int x){
	if(x==0){
		putchar('0');
		return;
	} 
	if(x/10>0) qprint(x/10);
	putchar('0'+x%10);
}
int n,m; 
struct edge{
	int from;
	int to;
	int next;
	int id;
	int ring;
}G[maxm<<1],E[maxm<<1];
int sz=0;
int head[maxn];
void add_edge(int u,int v,int id){
//	printf("db:%d %d\n",u,v);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].id=id;
	E[sz].next=head[u];
	head[u]=sz;
}

int fa[maxn];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

int vis[maxn];
int deep[maxn];
int tree_edge[maxn];
int sum[maxn];
int anc[maxn][32];
void dfs(int x,int fa){
	vis[x]=1;
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=20;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			tree_edge[y]=i;
			dfs(y,x);
		}
	}
} 

int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]) x=anc[x][i];
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

int odd_ring=0;
vector<int>ans;
void dfs2(int x,int fa){
	vis[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs2(y,x);
			sum[x]+=sum[y];
		}
	}
	if(sum[x]==odd_ring) ans.push_back(E[tree_edge[x]].id);
}

int main(){
	int fu,fv;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		qread(G[i].from); 
		qread(G[i].to);
		fu=find(G[i].from);
		fv=find(G[i].to);
		if(fu==fv) G[i].ring=1;
		else{
			fa[fu]=fv;
			add_edge(G[i].from,G[i].to,i);
			add_edge(G[i].to,G[i].from,i);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
//			deep[i]=1;
			dfs(i,0);
		} 
	}
	int ed;
	for(int i=1;i<=m;i++){
		if(G[i].ring){
			int l=lca(G[i].from,G[i].to);
//			printf("%d ",l);
			if((deep[G[i].from]+deep[G[i].to]-2*deep[l]+1)%2==1){
				odd_ring++;
				ed=i;
				sum[G[i].from]++;
				sum[G[i].to]++;
				sum[l]-=2;
//				printf("%d %d %d\n",G[i].from,G[i].to,1);
			}else{
				sum[G[i].from]--;
				sum[G[i].to]--;
				sum[l]+=2;
//				printf("%d %d %d\n",G[i].from,G[i].to,-1);
			}
			 
		}
	}
	if(!odd_ring){
		for(int i=1;i<=m;i++){
			ans.push_back(i);
		}
	}else{
		memset(vis,0,sizeof(vis));
		if(odd_ring==1){
			ans.push_back(ed);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]) dfs2(i,0);
		}
	}
	sort(ans.begin(),ans.end());
	qprint(ans.size());
	putchar('\n');
	for(int i=0;i<ans.size();i++){
		qprint(ans[i]);
		putchar(' ');
	}
}
