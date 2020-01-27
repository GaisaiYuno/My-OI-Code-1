/*
BZOJ2673
����ת����ת����ɾ�����
ö��ÿ��ÿ�����ŵ������t��Ȼ���ܷ������������ɾ�������Ȼ����֤�����Ƿ�����A/B������
�������Ͱ����в�ɶ���ͼ���ߣ�S��i����ǰ�����������(��������ɾ��) 
����ɾ�ĵ�(i,j)����i��->j��,����1������1
��֤��Ⱦ���i��->i�У�����Ϊt,����i�����ɾn-t����i��Ҳ���ɾn-t����ͬʱ��Ϊ������������� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 110
#define maxm 20000
#define INF 0x3f3f3f3f
using namespace std;
struct edge{
	int from;
	int to;
	int next;
	int flow;
	int cost;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,int w,int c){
//	printf("%d->%d flow=%d cost=%d\n",u,v,w,c);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	E[sz].cost=c; 
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	E[sz].flow=0;
	E[sz].cost=-c; 
	head[v]=sz;
}

int dist[maxn+5];
int minf[maxn+5];
int pre[maxn+5];
bool inq[maxn+5];
bool spfa(int s,int t){
	for(int i=s;i<=t;i++){
		minf[i]=dist[i]=INF;
		inq[i]=0;
		pre[i]=0;
	}
	queue<int>q;
	dist[s]=0;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow){
				if(dist[y]>dist[x]+E[i].cost){
					dist[y]=dist[x]+E[i].cost;
					pre[y]=i;
					minf[y]=min(minf[x],E[i].flow);
					if(!inq[y]){
						q.push(y);
						inq[y]=1;
					}
				}
			}
		}
	}
	return dist[t]!=INF;
}
//void update(int s,int t){
//	int x=t;
//	while(x!=s){
//		int i=pre[x];
//		E[i].flow-=minf[t];
//		E[i^1].flow+=minf[t];
//		x=E[i].from;
//	}
//}
bool vis[maxn+5];
int dfs(int x,int t,int minf,int &cost){
	if(x==t){
		cost+=dist[t]*minf;
		return minf;
	}
	int rest=minf,k;
	vis[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(vis[y]) continue;
		if(E[i].flow&&dist[y]==dist[x]+E[i].cost){
			k=dfs(y,t,min(rest,E[i].flow),cost);
			E[i].flow-=k;
			E[i^1].flow+=k;//����dinic,���а�ҹ������Ϊ 
			rest-=k;
			if(k==0) dist[y]=INF;//�ѱ�ե�ɵı߱�ǵ� 
			if(rest==0) break;
		}
	}
	vis[x]=0;//����ʱ���vis,��Ҫÿ��dfs֮ǰ��գ������޴� 
	return minf-rest;
}
pair<int,int> mcmf(int s,int t){
	int flow=0,cost=0;
	int now;
	while(spfa(s,t)){
//		for(int i=s;i<=t;i++) vis[i]=0;
		while((now=dfs(s,t,INF,cost))) flow+=now;
	}
	return make_pair(flow,cost);
}



int n,A,B;
char str[maxn+5][maxn+5];
int rtot[maxn+5],ctot[maxn+5];//ÿ�У�ÿ������ܷŵ������
int cnt_all;
int cnt_used;
void clear_graph(){
	sz=1;
	for(int i=0;i<=2*n+1;i++) head[i]=0;
}
void ini(){
	cnt_all=0;
	cnt_used=0;
	for(int i=1;i<=n;i++) rtot[i]=ctot[i]=0;
}
int main(){
//	freopen("1.in","r",stdin);
	int cas=0;
	while(scanf("%d %d %d",&n,&A,&B)!=INF&&n!=0){
		ini();
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]+1);
			for(int j=1;j<=n;j++){
				if(str[i][j]=='C'){
					rtot[i]++;
					ctot[j]++;
					cnt_all++;
					cnt_used++;
				}else if(str[i][j]=='.'){
					rtot[i]++;
					ctot[j]++;
					cnt_all++;
				}
			}
		}
		int ans=-1;
		int s=0,t=2*n+1;
		for(int flow=0;flow<=n;flow++){
			clear_graph();
			for(int i=1;i<=n;i++){
				add_edge(s,i,rtot[i],0);
				add_edge(i+n,t,ctot[i],0);
				add_edge(i,i+n,flow,0);
				for(int j=1;j<=n;j++){
					if(str[i][j]=='.') add_edge(i,j+n,1,1);
				} 
			}
			pair<int,int>tmp=mcmf(s,t);
			int real_flow=tmp.first,real_cost=tmp.second;
			if(real_flow==cnt_all&&flow*B<=(cnt_all-real_cost)*A){
				ans=max(ans,cnt_all-real_cost-cnt_used); 
			}
		}
		cas++;
		printf("Case %d: ",cas);
		if(ans==-1) printf("impossible\n");
		else printf("%d\n",ans);
		
	}	
}
