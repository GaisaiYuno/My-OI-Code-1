#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
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
int used[maxn];
int ans=0;
void dfs(int x){
	used[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(used[y]){
			ans=y;
			return;
		}else{
			dfs(y);
		}
	}
}
int main(){
	int p;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p);
		add_edge(i,p);
	}
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		dfs(i);
		printf("%d ",ans);
	}
}

