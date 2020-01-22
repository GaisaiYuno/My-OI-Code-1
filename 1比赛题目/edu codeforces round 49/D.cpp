#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
#define INF 0x7fffffff
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int size=0;
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

int fa[maxn];
void ini(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	fa[fx]=fy;
}

int c[maxn];
int in[maxn],out[maxn];
int vis[maxn];
int vis2[maxn];
int mark[maxn];
int is_mark[maxn];
bool is_ring=false;
int k;
void  dfs(int x){
	vis[x]=1;
	k=x;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			dfs(y);
		}else{
			is_ring=true;
			k=y;
			return;
		}
	}
}
int minv;
void dfs2(int x){
	vis2[x]=1;
	minv=min(minv,c[x]);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis2[y]){
			dfs2(y);
		}else return;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]); 
	}
	int u;
	ini();
	for(int i=1;i<=n;i++){
		scanf("%d",&u);
		if(u!=i){
			add_edge(i,u); 
			merge(i,u);
			out[i]++;
			in[u]++;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++) mark[i]=find(i);
	for(int i=1;i<=n;i++){
		if(is_mark[mark[i]]==0){
			dfs(i);
//			printf("%d\n",k);
			is_mark[mark[i]]=1;
			if(is_ring){
				minv=INF;
				dfs2(k);
				ans+=minv;
			}else{
				ans+=c[k];
			}
		}
	}
	printf("%I64d\n",ans);
} 
