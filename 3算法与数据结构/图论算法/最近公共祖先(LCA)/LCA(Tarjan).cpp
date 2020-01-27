#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#include<vector>
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

struct qdata{
	int x;
	int y;
	int id;
	qdata(){
		
	}
	qdata(int u,int v,int i){
		x=u;
		y=v;
		id=i;
	}
}; 
vector<qdata>query[maxn];

int fa[maxn];
int get(int x){
	if(fa[x]==x) return x;
	else{
		fa[x]=get(fa[x]);
		return fa[x];
	} 
}
int v[maxn];
int ans[maxn];
void tarjan(int x){
	v[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(v[y]) continue;
		tarjan(y);
		fa[y]=x;
	}
	for(int i=0;i<query[x].size();i++){
		int y=query[x][i].y;
		int id=query[x][i].id;
		if(v[y]==2){
			ans[id]=get(y);
		}
	}
	v[x]=2;
}
int main(){
	int u,v;
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		if(u==v) ans[i]=u;
		else{
			query[u].push_back(qdata(u,v,i));
			query[v].push_back(qdata(v,u,i));	
		}
    }
    tarjan(s);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
} 
