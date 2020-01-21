#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#include<queue>
#define maxn 500005
#define maxlog 32
using namespace std;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2];
int head[maxn];
int size=0; 
int n,m,s;
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}
int deep[maxn];
int fa[maxn][maxlog]; 
int log2n;
void init(int s){
	queue<int>q;
	q.push(s);
	deep[s]=1;//容易忘记 
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(deep[y]) continue;
			deep[y]=deep[x]+1;
			fa[y][0]=x;
			for(int j=1;j<=log2n;j++){
				fa[y][j]=fa[fa[y][j-1]][j-1];
			}
			q.push(y);//一定要继续入队 
		}
	}
}
int lca(int x,int y){
	if(deep[x]>=deep[y]) swap(x,y);
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
int main(){
	int u,v;
	scanf("%d %d %d",&n,&m,&s);
	log2n=log2(n)+1;
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init(s); 
    for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
    }
} 
