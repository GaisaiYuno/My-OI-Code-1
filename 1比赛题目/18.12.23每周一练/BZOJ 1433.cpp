#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
#define maxm 1005
using namespace std;
int t,n;
struct edge{
	int from;
	int to;
	int next;
}E[maxm];
int head[maxn];
int sz=0;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int is_sch[maxn];
int is_home[maxn];
int is_know[maxn][maxn];
void ini(){
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	sz=0;
}

int vis[maxn];
int match[maxn];
int dfs(int x){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			vis[y]=1;
			if(!match[y]||(dfs(match[y]))){
				match[y]=x;
				return 1;
			}
		}
	}
	return 0;
}

int hungary(){
	int ans=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=n;i++){
		if(!is_sch[i]||(is_sch[i]&&!is_home[i])){
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
	}
	return ans;
}
int main(){
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d",&n);
		ini();
		for(int i=1;i<=n;i++) scanf("%d",&is_sch[i]);
		for(int i=1;i<=n;i++) scanf("%d",&is_home[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&is_know[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			if(is_sch[i]&&!is_home[i]) add_edge(i,i);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(is_know[i][j]&&is_sch[j]) add_edge(i,j);
			}
		}
		int requst=0;
		for(int i=1;i<=n;i++){
			if(!is_sch[i]||(is_sch[i]&&!is_home[i])) requst++;
		}
		if(hungary()==requst){
			printf("^_^\n");
		}else{
			printf("T_T\n");
		}
	}	
} 
