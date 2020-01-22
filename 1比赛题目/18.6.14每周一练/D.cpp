#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 100005
#define maxlog 32
using namespace std;
int n,k;
struct edge{
	int from;
	int to;
	int next;
	int index;
}E[maxn*2];
int head[maxn];
int size=0;
void add_edge(int u,int v,int id){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	E[size].index=id;
	head[u]=size;
}
int dfn[maxn*2];
int used[maxn];
int fipos[maxn*2];
int deep[maxn*2];
int st[maxn*4][maxlog];
int cnt=0;
void get_dfn(int u,int d){
	dfn[++cnt]=u;
	if(fipos[u]==0){
		fipos[u]=cnt;
		deep[u]=cnt; 
	} 
	used[u]=1;
	for(int i=head[u];i;i=E[i].next){
		if(!used[E[i].to]){
			get_dfn(E[i].to,d+1);
		    dfn[++cnt]=u;
		}
	}
} 
void st_init(){
	for(int i=1;i<=(n-1)*2;i++){
		st[i][0]=dfn[i];
	}
	for(int j=1;(1<<j)<=(n-1)*2;j++){
		for(int i=1;i<=(n-1)*2;i++){
			if(deep[st[i][j-1]]<deep[st[i+(1<<(j-1))][j-1]]) st[i][j]=st[i][j-1];
			else st[i][j]=st[i+(1<<(j-1))][j-1];
		}
	} 
}
int st_query(int l,int r){
	if(l>r) swap(l,r);
	int k=log2(r-l+1);
	if(deep[st[l][k]]<deep[st[r-(1<<k)+1][k]]) return st[l][k];
	else return st[r-(1<<k)+1][k];
}
int lca(int x,int y){
	int fx=fipos[x];
	int fy=fipos[y];
	return st_query(fx,fy);
}
int len[maxn];
int outlen[maxn];//按题目顺序输出 
void get_len(int u){
	used[u]=1;
	for(int i=head[u];i;i=E[i].next){
		if(!used[E[i].to]){
			get_len(E[i].to);
			len[u]+=len[E[i].to];
			outlen[E[i].index]+=len[E[i].to];
		}
	} 
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v,i);
		add_edge(v,u,i);
	}
	get_dfn(1,0);
	st_init();
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d %d",&u,&v);
//		printf("%d\n",lca(u,v)); 
		len[u]++;
		len[v]++;
		len[lca(u,v)]-=2;
	}
	memset(used,0,sizeof(used));
	get_len(1);
	for(int i=1;i<=n-1;i++) printf("%d ",outlen[i]); 
}
/*
5
1 2
1 3
2 4
2 5
4
4 5
*/
