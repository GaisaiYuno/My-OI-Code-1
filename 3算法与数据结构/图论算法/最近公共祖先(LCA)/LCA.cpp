#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 500005
#define maxm 500005
#define maxlog 32
using namespace std;
int n,m,s;
struct edge{
	int from;
	int to;
	int next;
}E[maxm*2]; 
int size=0;
int head[maxn];

int dfn[maxn*2];
struct first_visit{
	int pos;
	int deep;
}first[maxn*4];
int used[maxn];
int st[maxn*4][maxlog];
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

int cnt=0;
void dfs(int u,int deep){
	dfn[++cnt]=u;
	if(!first[u].pos){
		first[u].pos=cnt;
		first[u].deep=deep;
	} 
	used[u]=1;
	for(int i=head[u];i!=0;i=E[i].next){
		if(!used[E[i].to]){
			dfs(E[i].to,deep+1);
			dfn[++cnt]=u;
		}
	}
}
inline int get_deep(int u){
	return first[u].deep;
}
//st[i][j]��������deep��С�ĵ���dfn�е��±� 
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
	int x,y,a,b;
	scanf("%d %d %d",&n,&m,&s);
	size=0;
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	cnt=0;
	dfs(s,1);
	st_init(); 
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}
