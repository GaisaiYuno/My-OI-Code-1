#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxm 100005
#define maxn 100005 
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
//	printf("%d %d\n",u,v);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int vis[maxn];
int match[maxn];
int dfs(int x,int t){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(vis[y]<t){
			vis[y]=t;
			if(!match[y]||dfs(match[y],t)){
				match[y]=x;
				return 1;
			}
		}
	}
	return 0;
}

int hungary(){
	memset(vis,0,sizeof(vis));
	memset(match,0,sizeof(match));
	int ans=0;
	for(int i=1;i<=n*2;i++){
		if(dfs(i,i)) ans++;
		else break;
	}
	return ans;
}

void ini(){
	sz=0;
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
}

int main(){
	int x;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d",&n);
		ini(); 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&x);
				if(x==1) add_edge(i,j+n);
			}
		}
		if(hungary()==n) printf("Yes\n");
		else printf("No\n");
	}
} 
