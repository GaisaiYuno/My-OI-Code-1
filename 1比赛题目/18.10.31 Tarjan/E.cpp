#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#define maxn 4005
#define maxm 20005
using namespace std;
int n,m;
map<string,int>id;
struct edge {
	int from;
	int to;
	int next;
} E[maxm];
int head[maxn];
int sz=0;
void add_edge(int u,int v) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

stack<int>s;
int ins[maxn];
int dfn[maxn];
int low[maxn];
int belong[maxn];
int cntv[maxn];
int num=0;
int scc_cnt=0;
void tarjan(int x) {
	ins[x]=1;
	s.push(x);
	low[x]=dfn[x]=++num;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(!dfn[y]) {
			tarjan(y);
			low[x]=min(low[x],low[y]);
		} else if(ins[y]) {
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]) {
		scc_cnt++;
		int y;
		do {
			y=s.top();
			ins[y]=0;
			s.pop();
			belong[y]=scc_cnt;
			cntv[scc_cnt]++;
		} while(y!=x);
	}
}

string a,b;
int main(){
	scanf("%d",&n); 
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		id[a]=i;
		id[b]=i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		int x=id[a];
		int y=id[b];
		add_edge(x,y);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
		if(cntv[belong[i]]>1) printf("Unsafe\n");
		else printf("Safe\n");
	}
}
