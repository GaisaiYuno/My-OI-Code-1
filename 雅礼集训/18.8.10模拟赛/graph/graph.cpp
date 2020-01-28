#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 150005
#define maxm 150005
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;	
}E[maxm<<1];
int size=1;
int head[maxn];
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}
int w[maxn];
int used[maxm<<1];
long long ans=0;
void dfs(int x,long long v,int final){
	if(x==final){
		ans=max(ans,v);
		return;
	}
	for(int i=head[x];i;i=E[i].next){
		if(!used[i]){
			used[i]=used[i^1]=1;
			dfs(E[i].to,v+w[E[i].to],final);
		}
	}
		
}
int main(){
//	freopen("graph.in","r",stdin);
//	freopen("graph.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);	
	}
	int cmd,a,b;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&cmd,&a,&b);
		if(cmd==1){
			add_edge(a,b);
			add_edge(b,a);	
		}else if(cmd==2){
			w[a]=b;	
		}else{
			memset(used,0,sizeof(used));
			ans=-1;
			dfs(a,w[a],b);
			printf("%d\n",ans);	
		}
	}
}
