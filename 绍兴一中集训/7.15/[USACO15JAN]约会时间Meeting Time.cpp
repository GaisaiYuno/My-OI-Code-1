//https://www.luogu.org/problemnew/show/P3116
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100
#define maxm 10000
#define maxl 10000
using namespace std;
int n,m; 
struct edge{
	int from;
	int to;
	int next;
	int len1;
	int len2;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
int in[maxn+5];
void add_edge(int u,int v,int w1,int w2){
	in[v]++;
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len1=w1;
	E[sz].len2=w2;
	head[u]=sz;
} 

bool f[maxn+5][maxl+5],g[maxn+5][maxl+5];
queue<int>q;
void topo_sort(){
	for(int i=1;i<=n;i++) {
		if(in[i]==0){
			q.push(i);
		}
	}
	f[1][0]=g[1][0]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			in[y]--;
			for(int j=0;j+E[i].len1<maxl;j++) f[y][j+E[i].len1]|=f[x][j];
			for(int j=0;j+E[i].len2<maxl;j++) g[y][j+E[i].len2]|=g[x][j];
			if(in[y]==0) q.push(y);
		}
	}
}

int main(){
//	freopen("2.txt","r",stdin);
	int u,v,w1,w2;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&u,&v,&w1,&w2);
		add_edge(u,v,w1,w2);
	}	
	topo_sort();
	for(int i=0;i<maxl;i++){
		if(f[n][i]==1&&g[n][i]==1){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("IMPOSSIBLE");
} 
