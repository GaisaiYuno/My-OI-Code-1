#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105 
using namespace std;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*maxn*2];
int n,m;
int sz=0;
int head[maxn];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int match[maxn];
int vis[maxn];
int dfs(int x){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			vis[y]=1;
			if(!match[y]||dfs(match[y])){
				match[y]=x;
				return 1;
			} 
		}
	}
	return 0;
} 

int hungary(){
	int ans=0;
	for(int i=1;i<=m;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++; 
	}
	return ans;
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	while(scanf("%d %d",&u,&v)!=EOF){
		if(u==-1) break;
		add_edge(u,v);
	}
	printf("%d\n",hungary());
	for(int i=1;i<=m;i++){
		if(match[i]!=0) printf("%d %d\n",match[i],i);
	}
} 
