#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define maxn 100005
#define maxm 500005
using namespace std;
int n,m;
struct edge {
	int from;
	int to;
	int next;
} E[maxm<<1];
int head[maxn];
int ecnt=0;
void add_edge(int u,int v) {
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}

int root=0;
int tim=0;
int dfn[maxn];
int low[maxn];
int cut[maxn];
int sz[maxn];
long long ans[maxn];
void tarjan(int x){
	long long res=0;
	long long sum=0;
	int flag=0;
	dfn[x]=low[x]=++tim;
	sz[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
			sz[x]+=sz[y];
			if(dfn[x]<=low[y]){
				flag++;
				if(flag>1||x!=root){
					cut[x]=1;
					sum+=sz[y];
					res+=(long long)sz[y]*(n-sz[y]);
				}
			}
		}else{
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(cut[x]){
		ans[x]=res+1*(n-1)+(long long)(sum+1)*(n-sum-1);
	}else{
		ans[x]=2*(n-1);
	}
}

int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		if(u==v) continue;
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			root=i;
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%lld\n",ans[i]);
	}
}
