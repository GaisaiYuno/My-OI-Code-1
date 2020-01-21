#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath> 
#define maxn 10005
#define maxm 50005
#define maxlog 32
using namespace std;
int n,m,q;
int dfn[maxn];
int low[maxn];
int is_bridge[maxm*2];
struct edge{
	int from;
	int to;
	int next;
}G[maxm*2],E[maxn*2]; 
int head1[maxn];
int head2[maxn];
int size1=1;//一定要从2,3开始存,这样i的重边就可以存储在i^1 
void add_edge1(int u,int v){
	size1++;
	G[size1].from=u;
	G[size1].to=v;
	G[size1].next=head1[u];
	head1[u]=size1;
}
int size2=0;
void add_edge2(int u,int v){
	size2++;
	E[size2].from=u;
	E[size2].to=v;
	E[size2].next=head2[u];
	head2[u]=size2;
}
int tim=0;
int bridge_cnt=0;
void tarjan(int x,int last_edge){
	dfn[x]=++tim;
	low[x]=dfn[x];
	for(int i=head1[x];i;i=G[i].next){
		int y=G[i].to;
		if(!dfn[y]){
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y]){
				is_bridge[i]=is_bridge[i^1]=1;
			}
		}else if(i!=(last_edge^1)) low[x]=min(low[x],dfn[y]);
	} 
}
int c[maxn];
int dcc=0; 
void e_dcc(int x){
	c[x]=dcc;
	for(int i=head1[x];i;i=G[i].next){
		int y=G[i].to;
		if(c[y]||is_bridge[i]) continue;
		e_dcc(y); 
	}
}

int log2n;
int deep[maxn];
int fa[maxn][maxlog];
void lca_init(){
	queue<int>q;
	q.push(1);
	deep[1]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head2[x];i;i=E[i].next){
			int y=E[i].to;
			if(deep[y]) continue;
			deep[y]=deep[x]+1;
			fa[y][0]=x;
			for(int j=1;j<=log2n;j++){
				fa[y][j]=fa[fa[y][j-1]][j-1];
			}
			q.push(y);
		}
	}
}
int lca_query(int x,int y){
	if(deep[x]>deep[y]) swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[fa[y][i]]>=deep[x]) y=fa[y][i];
	} 
	if(x==y) return x;
	for(int i=log2n;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int get_dis(int x,int y){
	return deep[x]+deep[y]-2*deep[lca_query(x,y)];
}
void bin_print(int x){
    int a[32];
    int cnt=0;
    if(x==0){
    	putchar('0');
    	putchar('\n');
    	return;
	}
    while(x>0){
        a[cnt++]=x%2;
        x/=2;
    }
    for(int i=cnt-1;i>=0;i--) putchar(a[i]+'0');
    putchar('\n'); 
} 
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge1(u,v);
		add_edge1(v,u); 
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i,0); 
		} 
	}
	for(int i=1;i<=n;i++){
		if(!c[i]){
			dcc++;
			e_dcc(i);
		}
	}
	for(int i=2;i<=size1;i++){
		int x=G[i].from;
		int y=G[i].to;
		if(c[x]==c[y]) continue;
		else{
			add_edge2(c[x],c[y]);
		} 
	}
	n=dcc;
	log2n=log2(n)+1;
	lca_init();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&v);
		bin_print(get_dis(c[u],c[v])+1);
	}
	return 0;
} 
/*
8 9
1 2
1 3
2 3
3 4
4 5
5 6
6 7
7 8
6 8
5
1 8
*/
