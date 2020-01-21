#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 40005
#define maxm 40005
#define maxlog 32
using namespace std;
int t;
int n,m;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm*2]; 
int size=0;
int head[maxn];
int dfn[maxn*2];
struct first_visit{
	int pos;
	int dis;
}first[maxn*4];
int used[maxn];
int st[maxn*4][maxlog];
void add_edge(int u,int v,int w){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].len=w;
	E[size].next=head[u];
	head[u]=size;
}

int cnt=0;
void dfs(int u,int dis){
	dfn[++cnt]=u;
	if(!first[u].pos){
		first[u].pos=cnt;
		first[u].dis=dis;
	} 
	used[u]=1;
	for(int i=head[u];i!=0;i=E[i].next){
		if(!used[E[i].to]){
			dfs(E[i].to,dis+E[i].len);
			dfn[++cnt]=u;
		}
	}
}
inline int get_deep(int u){
	return first[u].dis;
}
//st[i][j]存区间内deep最小的点在dfn中的下标 
void st_init(){

	for(int i=1;i<=(n-1)*2;i++){
		st[i][0]=dfn[i]; 
	}
	for(int j=1;(1<<j)<=(n-1)*2;j++){
		for(int i=1;i<=(n-1)*2;i++){
			if(get_deep(st[i+(1<<(j-1))][j-1])<get_deep(st[i][j-1])) st[i][j]=st[i+(1<<(j-1))][j-1];
			else st[i][j]=st[i][j-1];
	    }
	}
}

int st_query(int l,int r){
	int k=log2(r-l+1);
	if(get_deep(st[l][k])<get_deep(st[r-(1<<k)+1][k])) return st[l][k];
	else return st[r-(1<<k)+1][k];
} 
int lca(int u,int v){
	int x=first[u].pos;
	int y=first[v].pos;
	if(x>y) swap(x,y);
	return st_query(x,y);
}
int main(){
//	printf("%.3fMB",(double)(sizeof(E)+sizeof(head)+sizeof(dfn)+sizeof(first)+sizeof(st))/1024/1024); 
	int x,y,w,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		size=0;
		cnt=0;
		memset(E,0,sizeof(E));
		memset(head,0,sizeof(head));
		memset(st,0,sizeof(st));
		memset(dfn,0,sizeof(dfn));
	    memset(used,0,sizeof(used));
	    memset(first,0,sizeof(first));
		for(int i=1;i<=n-1;i++){
			scanf("%d %d %d",&x,&y,&w);
			add_edge(x,y,w);
			add_edge(y,x,w);
		}
		dfs(1,0);
		st_init(); 
		for(int i=1;i<=m;i++){
			scanf("%d %d",&a,&b);
			printf("%d\n",first[a].dis-2*first[lca(a,b)].dis+first[b].dis);
		}	
	}
}
