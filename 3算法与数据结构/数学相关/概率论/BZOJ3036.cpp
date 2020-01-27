#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define maxn 100005
#define maxm 200005 
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int len;
	int next; 
}E[maxn<<1];
int sz=1;
int in[maxn],in2[maxn];
int head[maxn];
void add_edge(int u,int v,int w){
	in[v]++;
	in2[v]++;
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz; 
} 

double dp[maxn];
void topo_sort(){
	queue<int>q;
	q.push(n);
	dp[n]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			in[y]--;
			dp[y]+=(dp[x]+E[i].len)*1.0/in2[y];
			if(in[y]==0){
				q.push(y);
			}
		} 
	} 
} 
int main(){
	int u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(v,u,w);
		//期望dp用倒推，反向建边即可 
		// dp[i]表示i到n的期望距离，从dp[n]=0开始倒退 
	} 
	topo_sort();
	printf("%.2f",dp[1]);
}

