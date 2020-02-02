//https://begin.lydsy.com/JudgeOnline/problem.php?cid=1051&pid=4
//最小割多组方案？应添加spj 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 1005
#define maxv 1010
#define maxe 550005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
struct node{
	int c;
	int num;
	int p[maxn];
}a[maxn];


struct edge{
	int from;
	int to;
	int next;
	long long flow;
}E[maxe];
int head[maxv];
int sz=1;
void add_edge(int u,int v,long long w){
//	printf("%d %d %lld\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	E[sz].flow=0;
	head[v]=sz;
}

int deep[maxn];
bool bfs(int s,int t){
	queue<int>q;
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
			}
		}
	}
	return deep[t]!=0;
}

long long dfs(int x,int t,long long minf){
	if(x==t) return minf;
	long long k,rest=minf;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(deep[y]==deep[x]+1&&E[i].flow){
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

long long dinic(int s,int t){
	long long ans=0,now=0;
	while(bfs(s,t)){
		while(now=dfs(s,t,INF)) ans+=now;
	}
	return ans;
}

int mark[maxv];
int is_cut[maxe];
void dfs2(int x){
	mark[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(E[i].flow&&i%2==0){
			dfs2(y);
		}
	}
}

int s,t;
long long all;
vector<int>ans;
void make_graph(){
	sz=1;
	memset(head,0,sizeof(head));
	s=0,t=n+1;
	for(int i=1;i<=n;i++){
		if(a[i].c>0){
			add_edge(s,i,a[i].c);
			all+=a[i].c;
		}else{
			add_edge(i,t,-a[i].c);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].num;j++){
			add_edge(i,a[i].p[j],INF);
		}
	}
}
void get_ans(){
	make_graph();
	for(int i=2;i<=sz;i+=2){
		E[i].flow--;//边数最多-> -1,边数最少-> +1 
	}
	dinic(s,t);
	dfs2(s); 
	for(int i=2;i<=sz;i+=2){
		if(mark[E[i].from]&&!mark[E[i].to]&&E[i].flow==0){
			is_cut[i]=1;
		}
	}
	for(int i=head[s];i;i=E[i].next){
		int y=E[i].to;
		if(!is_cut[i]){
			ans.push_back(y);
		}
	}
	for(int i=head[t];i;i=E[i].next){
		int y=E[i^1].from;
		if(is_cut[i^1]){
			ans.push_back(y);
		}
	} 
}
int main(){
	char ch;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%c",&a[i].c,&ch);
		if(ch=='\n') continue;
		while(scanf("%d%c",&a[i].p[++a[i].num],&ch)&&ch!='\n');
	}
	make_graph();
	printf("%lld\n",all-dinic(s,t));
	get_ans();
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		printf("%d\n",ans[i]);
	}
} 
/*
6
-4
1
2 2
-1 1 2
-3 3
5 3 4

6
-4
1
2 1
-1 1 2
-3 3
5 3 4
*/
