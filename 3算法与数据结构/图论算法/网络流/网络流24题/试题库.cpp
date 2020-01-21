#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define maxn 2005
#define maxm 100005
#define INF 0x7fffffff
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

int m,n;
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
	for(int i=n+1;i<=m+n;i++){
		ans.clear();
		for(int j=head[i];j;j=E[j].next){
			if(flow[j^1]==0&&E[j].to>=1&&E[j].to<=n){
				ans.push_back(E[j].to);
			} 
		}
		sort(ans.begin(),ans.end());
		
		printf("%d: ",i-n);
		for(int j=0;j<ans.size();j++){
			printf("%d ",ans[j]); 
		} 
		printf("\n");
	}
}
int tot=0;
int main(){
	int u,v;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		r[i]=qread();
		tot+=r[i];
	} 
	for(int i=1;i<=n;i++){
		c[i]=qread();
		for(int j=1;j<=c[i];j++){
			u=qread();
			add_edge(i,u+n,1);
			add_edge(u+n,i,0);	
		}
	}
	for(int i=1;i<=n;i++){
		add_edge(0,i,1);
		add_edge(i,0,0);
	}
	for(int i=1;i<=m;i++){
		add_edge(i+n,m+n+1,r[i]);
		add_edge(m+n+1,i+n,0); 
	}
	if(dinic(0,m+n+1)==tot){
		print_ans();
	}else{
		printf("No Solution!\n");
	}
}
