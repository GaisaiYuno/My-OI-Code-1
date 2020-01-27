/*
Problem:航空路线问题 
Source:
Description:
每个点拆成两个，i向i+n连边,容量为允许节点经过次数，费用1
对于边(u,v) u向v+n连边，容量2，费用0 
费用表示经过节点数量 
注意点1，n允许经过两次，其他允许过1次
由于1，n经过两次，最终答案为最大费用最大流-2
输出答案，在残量网络上DFS
如果该边是正向边，且对应的反向边有流量（这条边被流过），则输出
并注意判重 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<algorithm> 
#include<vector>
#define maxn 100005
#define maxm 500005
#define INF 0x3f3f3f3f
using namespace std; 
map<string,int>id;
string name[maxn];
int n,m;
struct edge{
    int from;
    int to;
    int next;
    int vol;
    int flow;
    int cost;
}E[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w,int c){
//	printf("%d->%d vol=%d cost=%d\n",u,v,w,c);
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].next=head[u];
    E[sz].flow=w;
    E[sz].vol=w;
    E[sz].cost=c; 
    head[u]=sz;
    
    sz++;
    E[sz].from=v;
    E[sz].to=u;
    E[sz].next=head[v];
    E[sz].flow=0;
    E[sz].vol=0;
    E[sz].cost=-c; 
    head[v]=sz;
} 

int dist[maxn];
int minf[maxn];
int pre[maxn];
int inq[maxn]; 
bool spfa(int s,int t){
    memset(dist,0x3f,sizeof(dist));
    memset(inq,0,sizeof(inq));
    queue<int>q;
    q.push(s);
    inq[s]=1;
    dist[s]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=0; 
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(E[i].flow){
                if(dist[y]>dist[x]+E[i].cost){
                    dist[y]=dist[x]+E[i].cost;
                    minf[y]=min(minf[x],E[i].flow);
                    pre[y]=i;
                    if(!inq[y]){
                        inq[y]=1;
                        q.push(y);
                    } 
                }
            }
        }
    } 
    if(dist[t]==INF) return 0;
    else return 1;
}

void update(int s,int t){
    int x=t;
    while(x!=s){
        int i=pre[x];
        E[i].flow-=minf[t];
        E[i^1].flow+=minf[t];
        x=E[i^1].to;
    }
}

void EK(int s,int t,int &mincost,int &maxflow){
    memset(minf,0x3f,sizeof(minf));
    while(spfa(s,t)){
        update(s,t);
        mincost+=dist[t]*minf[t];
        maxflow+=minf[t];
    }
}

vector<int>ans;
void dfs(int x){
//	printf("db:%d\n",x); 
	ans.push_back(x);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(i&1) continue;
		if(E[i^1].flow){
			dfs(y);
			E[i^1].flow--;
			return;
		}
	}
}
int main(){
	int s,t;
	string u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>u;
		id[u]=i;
		name[i]=u;
	}
	add_edge(1,n+1,2,-1);
	add_edge(n,n*2,2,-1);
	for(int i=2;i<n;i++){
		add_edge(i,i+n,1,-1);
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		int x=id[u];
		int y=id[v];
		if(x>y) swap(x,y);
		add_edge(x+n,y,INF,0);
	}
	int flow=0,cost=0;
	EK(1,n*2,cost,flow);
	if(flow==0){
		printf("No Solution!\n");
		
	}else{
		printf("%d\n",-cost-2);
		dfs(1);
		for(int i=0;i<ans.size();i++){
			if(ans[i]<=n) cout<<name[ans[i]]<<endl;
		}
//		printf("------\n");
		ans.clear();
		dfs(1);
		int tmp=0;
		for(int i=ans.size()-1;i>=0;i--){
			if(ans[i]<=n){
				tmp++;
				if(tmp==1) continue;
				cout<<name[ans[i]]<<endl;
			}
		}
	}
}
