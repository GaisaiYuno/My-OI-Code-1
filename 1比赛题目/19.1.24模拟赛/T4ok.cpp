/*
Problem:ÂÃÐÐ 
Source:http://119.29.55.79/contest/23/problem/4
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define maxn 55
#define maxm 505
#define INF 1e9
#define eps 1e-4
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){ 
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=sign;
}

int n,m,k;
namespace network_flow{
	struct edge{
	    int from;
	    int to;
	    int next;
	}E[maxm*maxm];
	double flow[maxm*maxm];
	int head[maxm];
	int sz=1;
	void add_edge(int u,int v,double w){
	    sz++;
	    E[sz].from=u;
	    E[sz].to=v;
	    E[sz].next=head[u];
	    flow[sz]=w;
	    head[u]=sz;
	    
	    sz++;
	    E[sz].from=v;
	    E[sz].to=u;
	    E[sz].next=head[v];
	    flow[sz]=0;
	    head[v]=sz;
	}
	
	int deep[maxm];
	queue<int>q;
	int bfs(int s,int t){
	    while(!q.empty()) q.pop();
	    q.push(s);
	    memset(deep,0,sizeof(deep));
	    deep[s]=1;
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
	
	double dfs(int x,int t,double minf){
	    if(x==t) return minf;
	    double rest=minf,k;
	    for(int i=head[x];i;i=E[i].next){
	        int y=E[i].to;
	        if(flow[i]&&deep[y]==deep[x]+1){
	            k=dfs(y,t,min(rest,flow[i]));
	            if(k<eps) deep[y]=0;
	            flow[i]-=k;
	            flow[i^1]+=k;
	            rest-=k;
	            if(rest<eps) return minf;
	        }
	    }
	    return minf-rest;
	}
	
	double dinic(int s,int t){
	    double maxflow=0,nowflow=0;
	    while(bfs(s,t)){
	        while(nowflow=dfs(s,t,INF)) maxflow+=nowflow; 
	    }
	    return maxflow;
	}
	
	void ini(){
		sz=1;
		memset(head,0,sizeof(head));
		memset(E,0,sizeof(E));
		memset(flow,0,sizeof(flow));
	}
}

int in[maxn];
vector<int>seq;
double dp[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxm<<1];
int head[maxn];
int sz=0;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
vector<int>D[maxm];
void topo_sort(){
	queue<int>q;
	for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		seq.push_back(x);
		for(int j=head[x];j;j=E[j].next){
			int y=E[j].to;
			in[y]--;
			if(in[y]==0) q.push(y); 
		}
	}
}

double check(int x,double mid){
	int s=0,t=m+1;
	network_flow::ini();
	double ans=0;
	for(int i=head[x];i;i=E[i].next){
		for(int j=0;j<D[i].size();j++){
			network_flow::add_edge(i,D[i][j],INF);
		}
		if(dp[E[i].to]+1<mid){
			network_flow::add_edge(s,i,-(dp[E[i].to]+1-mid));
		}else{
			ans+=dp[E[i].to]+1-mid;
			network_flow::add_edge(i,t,(dp[E[i].to]+1-mid));
		}
	} 
	return ans-network_flow::dinic(s,t);
}

double frac_01(int x,double l,double r){
//	printf("%d:\n",x);
	double ans=0,mid;
	while(fabs(r-l)>eps){
		mid=(l+r)/2.0;
//		printf("%.1f %.1f %.1f\n",l,r,mid);
		if(check(x,mid)>eps){
			ans=mid;
			l=mid;
		}else r=mid;
	}
	return ans;
}

double solve(){
	for(int i=seq.size()-1;i>=0;i--){
		int x=seq[i];
		double r=0;
		for(int j=head[x];j;j=E[j].next){
			int y=E[j].to;
			r=max(r,dp[y]+1);
		}
		dp[x]=frac_01(x,0,r);
	}
	return dp[1];
}
int main(){
#ifdef FILE_IO
	freopen("4.in","r",stdin);
#endif
	int u,v;
	qread(n);
	qread(m);
	qread(k);
	for(int i=1;i<=m;i++){
		qread(u);
		qread(v);
		in[v]++;
		add_edge(u,v);
	}
	for(int i=1;i<=k;i++){
		qread(u);
		qread(v);
		D[v].push_back(u);
	}
	topo_sort();
	printf("%.10lf",solve());
	return 0;
}


