#include<iostream>
#include<cstdio>
#include<cstring>
#define maxm 200005
#define maxn 200005
using namespace std;
int n,m;
struct edge{
    int from;
    int to;
    int next;
}E[maxm<<1];
int sz=0;
int head[maxn];
void add_edge(int u,int v){
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].next=head[u];
    head[u]=sz;
}

int vis[maxn];
int match[maxn];
int res[maxn];
int dfs(int x,int t){
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(vis[y]<t){
            vis[y]=t;
            if(!match[y]||dfs(match[y],t)){
                match[y]=x;
                res[x]=y;
                return 1;
            }
        }
    }
    return 0;
}

int hungary(){
	int ans=0;
	for(int i=n+1;i<=m+n;i++){
//		vis[i]=i;
		if(dfs(i,i)) ans++;
		else break;
	}
	return ans;
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge(i+n,u);
		add_edge(i+n,v);
	}
	int ans=hungary();
	printf("%d\n",ans);
}
