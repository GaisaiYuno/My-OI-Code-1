/*
Problem:»’≥Ã±Ì
Source:http://119.29.55.79/problem/170
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxc 55
#define maxn 5005
#define maxm 300005 
#define INF 0x3f3f3f3f
using namespace std;
int cases;
int n,m;
struct edge{
	int from;
	int to;
	int next;
	int flow;
}E[maxm<<1];
int sz=1;
int head[maxn];
void add_edge(int u,int v,int w){
//	printf("%d->%d : %d\n",u,v,w);
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
	q.push(s);
	deep[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow&&!deep[y]){
				deep[y]=deep[x]+1;
				if(y==t) return 1;
				q.push(y);
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
			if(k==0) deep[y]=0;
			E[i].flow-=k;
			E[i^1].flow+=k;
			rest-=k; 
		}
	}
	return minf-rest;
}

int dinic(int s,int t){
	int maxflow=0,nowflow=0;
	while(bfs(s,t)){
		while(nowflow=dfs(s,t,INF)) maxflow+=nowflow;
	}
	return maxflow;
}

int wcnt,bcnt,qcnt;
char table[maxc][maxc];
int s,t;
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
int id[maxc][maxc];
int mark[maxc][maxc];
int calc_blue(int x,int y){
	int sum=0;
	for(int i=0;i<4;i++){
		int xx=x+walkx[i];
		int yy=y+walky[i];
		if(xx>0&&yy>0&&xx<=n&&yy<=m&&table[xx][yy]=='#') sum++;
	}
	return sum;
}

int cal_tot(){
	wcnt=bcnt=qcnt=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(table[i][j]=='.') wcnt++;
			else if(table[i][j]=='#') bcnt++;
			else{
				qcnt++;
				id[i][j]=qcnt;
			}
		}
	}
	ans=4*bcnt;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(table[i][j]=='#'){
				ans-=calc_blue(i,j);
			}
		}
	}
	ans+=4*qcnt;
	return ans;
}

void build_graph(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((i+j)%2==0) mark[i][j]=1;
			else mark[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(table[i][j]=='?'){
				int tot=calc_blue(i,j);
				if(mark[i][j]){
					add_edge(s,id[i][j],4);
					add_edge(id[i][j],t,2*tot);
					for(int k=0;k<4;k++){
						int x=i+walkx[k];
						int y=j+walky[k];
						if(x>0&&y>0&&x<=n&&y<=m&&mark[x][y]==0&&table[x][y]=='?'){
							add_edge(id[i][j],id[x][y],2);
						}
					}
				}else{
					add_edge(s,id[i][j],2*tot);
					add_edge(id[i][j],t,4);
				}
				
			}
		}
	}
}

void ini(){
	sz=1;
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head)); 
	memset(id,0,sizeof(id));
}

int solve(){
	int ans=cal_tot();
	s=0;
	t=qcnt+1;
	build_graph();
	return ans-dinic(s,t);
}

char input[maxn];
int main(){
	scanf("%d",&cases);
	for(int p=1;p<=cases;p++){
		ini();
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",input+1);
			for(int j=1;j<=m;j++){
				table[i][j]=input[j];
			}
		}
		printf("Case #%d: %d\n",p,solve());
	}
}

