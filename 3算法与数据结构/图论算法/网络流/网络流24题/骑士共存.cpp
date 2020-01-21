/*
Problen:∆Ô øπ≤¥Ê 
Source:http://119.29.55.79/problem/179
Description: 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxc 205
#define maxn 50005
#define maxm 500005 
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int a[maxc][maxc];
int mark[maxc][maxc];

struct edge{
    int from;
    int to;
    int next;
    int flow;
}E[maxm<<1];
int sz=1;
int head[maxn]; 
void add_edge(int u,int v,int w){
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

int deep[maxn];
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

inline int get_id(int x,int y){
	return (x-1)*n+y;
}
const int walkx[8]={1,1,-1,-1,2,2,-2,-2};
const int walky[8]={-2,2,-2,2,-1,1,-1,1};
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		a[u][v]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((i+j)%2==0) mark[i][j]=1;
		} 
	}
	int s=0,t=n*n+1;;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]) continue;
			if(mark[i][j]) add_edge(s,get_id(i,j),1);
			else add_edge(get_id(i,j),t,1);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]) continue;
			if(mark[i][j]){
				for(int k=0;k<8;k++){
					int x=i+walkx[k];
					int y=j+walky[k];
					if(x>=1&&y>=1&&x<=n&&y<=n&&!a[x][y]){
						add_edge(get_id(i,j),get_id(x,y),1);
					} 
				} 
			}
		}
	}
	printf("%d\n",n*n-m-dinic(s,t));
}

