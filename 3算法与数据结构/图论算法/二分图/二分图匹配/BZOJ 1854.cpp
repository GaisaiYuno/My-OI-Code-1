#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000005
#define maxm 1000005
using namespace std;
int n;
struct edge {
	int from;
	int to;
	int next;
} E[maxm*2];
int sz=0;
int head[maxn];
void add_edge(int u,int v) {
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

int mv;
int hungary() {
	int ans=0;
	for(int i=1; i<=10000; i++) {
		vis[i]=i;
		if(dfs(i,i)) ans++;
		else break;
	}
	return ans;
}
int main() {
	int u,v;
	scanf("%d",&n);
	mv=0;
	for(int i=1; i<=n; i++) {
		scanf("%d %d",&u,&v);
		add_edge(u,i+n);
//		add_edge(i+n,u); 
		add_edge(v,i+n);
//		add_edge(i+n,v); 
	}
	printf("%d\n",hungary());
}
