#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define maxn 505
#define maxm 50005
#define INF 0x7fffffff
using namespace std;
int n,m;
int r[maxn];
int c[maxn];

struct edge{
	int from;
	int to;
	int next;
}E[maxm];
int head[maxn];
int sz=1;
int vol[maxm];
int flow[maxm];
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
	vol[sz]=w;
	flow[sz]=w;
}

queue<int>q;
int deep[maxn];
int bfs(int s,int t){
	while(!q.empty()) q.pop();
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(flow[i]&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
				if(y==t) return 1;
			}
		}
	} 
	return 0;
}

int dfs(int x,int t,int minf){
	if(x==t) return minf;
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(flow[i]&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,flow[i]));
			if(k==0) deep[y]=0;
			flow[i]-=k;
			flow[i^1]+=k;
			rest-=k;
		}
	}
	return minf-rest;
}

int dinic(int s,int t){
	int maxflow,nowflow;
	maxflow=0;
	while(bfs(s,t)){
		while(nowflow=dfs(s,t,INF)) maxflow+=nowflow;
	}
	return maxflow;
}

vector<int>ans;
void print_ans(){
	for(int i=1;i<=m;i++){
		ans.clear();
		for(int j=head[i];j;j=E[j].next){
			if(flow[j]==vol[j]-1&&E[j].to>=m&&E[j].to<=n+m){
//				printf("%d ",E[j].to-m);
				ans.push_back(E[j].to-m);
			} 
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++){
			printf("%d ",ans[i]); 
		} 
		printf("\n");
	}
}
int main(){
	int tot=0;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++) scanf("%d",&r[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			add_edge(i,m+j,1);
			add_edge(m+j,i,0);
		}
	}
	for(int i=1;i<=m;i++){
		tot+=r[i];
		add_edge(0,i,r[i]);
		add_edge(i,0,0);
	}
	for(int i=1;i<=n;i++){
		add_edge(m+i,m+n+1,c[i]);
		add_edge(m+n+1,m+i,0);
	}
	if(dinic(0,m+n+1)==tot){
		printf("1\n");
		print_ans();
	}else{
		printf("0\n");
	}
}



