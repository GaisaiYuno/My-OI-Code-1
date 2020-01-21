/*
Problem:最长不下降子序列
Source: https://www.luogu.org/problemnew/show/P2766
Description:
https://www.luogu.org/blog/PopulusEuphratica/luogup2766-zui-zhang-fou-xia-xiang-zi-xu-lie-wen-ti
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 505
#define maxm 500005
#define INF 0x3f3f3f3f
using namespace std;
int n;
struct edge{
    int from;
    int to;
    int next;
    int flow;
}E[maxm<<1];
int sz=1;
int head[maxn*2]; 
void add_edge(int u,int v,int w){
//	printf("%d->%d %d\n",u,v,w); 
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].flow=w;
    E[sz].next=head[u];
    head[u]=sz;
    
    sz++;
    E[sz].from=v;
    E[sz].to=u;
    E[sz].flow=0;
    E[sz].next=head[v];
    head[v]=sz;
}

int deep[maxn*2];
bool bfs(int s,int t){
    queue<int>q;
    q.push(s);
    for(int i=s;i<=t;i++) deep[i]=0;
    deep[s]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(E[i].flow&&!deep[y]){
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
    int k,rest=minf;
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(E[i].flow&&deep[y]==deep[x]+1){
            k=dfs(y,t,min(rest,E[i].flow));
            rest-=k;
            E[i].flow-=k;
            E[i^1].flow+=k;
            if(k==0) deep[y]=0;
            if(rest==0) break;
        }
    }
    return minf-rest;
}

int dinic(int s,int t){
    int nowflow=0,maxflow=0;
    while(bfs(s,t)){
        while(nowflow=dfs(s,t,INF)) maxflow+=nowflow;
    }
    return maxflow;
}

int len;
int a[maxn];
int dp[maxn];
int solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(a[i]>=a[j]){
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
		ans=max(ans,dp[i]);
	}
	return ans;
}

int solve2(){
	int s=0,t=n*2+1;
	for(int i=1;i<=n;i++){
		if(dp[i]==1) add_edge(s,i,1);
	}
	for(int i=1;i<=n;i++){
		add_edge(i,i+n,1);//限制每个点只被选一次 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>=a[j]&&dp[i]==dp[j]+1){
				add_edge(j+n,i,1);
			}
		} 
	}
	for(int i=1;i<=n;i++){
		if(dp[i]==len){
			add_edge(i+n,t,1);
		}
	} 
	return dinic(s,t);
}

bool is_decrease(){
	for(int i=2;i<=n;i++){
		if(a[i]>=a[i-1]) return 0;
	}
	return 1;
}
int solve3(){
	if(is_decrease()) return solve2();
	//如果序列递减，dp全部为1，len也为1
	//dp[1]=1且dp[1]=len
	//所以S到1和1到T都有一条INF的边，答案为INF，要特判 
	sz=1;
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head)); 
	int s=0,t=n*2+1;
	for(int i=1;i<=n;i++){
		if(dp[i]==1){
			if(i==1||i==n) add_edge(s,i,INF);
			else add_edge(s,i,1);
		}
	}
	for(int i=1;i<=n;i++){
		if(i==1||i==n) add_edge(i,i+n,INF);
		else add_edge(i,i+n,1);//限制每个点只被选一次 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>=a[j]&&dp[i]==dp[j]+1){
				add_edge(j+n,i,1);
			}
		} 
	}
	for(int i=1;i<=n;i++){
		if(dp[i]==len){
			if(i==1||i==n) add_edge(i+n,t,INF);
			else add_edge(i+n,t,1);
		}
	} 
	return dinic(s,t);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	len=solve1();
	printf("%d\n",len);
	printf("%d\n",solve2());
	printf("%d\n",solve3());
}
