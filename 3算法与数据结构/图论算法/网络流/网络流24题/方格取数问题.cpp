/*
Problem:方格取数问题
Source:https://www.luogu.org/problemnew/show/P2774
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxs 105
#define maxn 20005
#define maxm 500005
#define INF 0x3f3f3f3f
using namespace std;
int m,n;
int a[maxs][maxs];
int color[maxs][maxs];
inline int get_id(int x,int y){
    return (x-1)*n+y;
}
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
    memset(deep,0,sizeof(deep));
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

const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
int main(){
    scanf("%d %d",&m,&n);
    int s=0,t=m*n+1;
    int sum=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if((i+j)%2==0){
                color[i][j]=1;
            }
            sum+=a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(color[i][j]) add_edge(s,get_id(i,j),a[i][j]);
            else add_edge(get_id(i,j),t,a[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(!color[i][j]) continue;
            for(int k=0;k<4;k++){
                int x=i+walkx[k];
                int y=j+walky[k];
                if(x<=0||y<=0||x>m||y>n) continue; 
                add_edge(get_id(i,j),get_id(x,y),INF); 
            }
        }
    }
    printf("%d\n",sum-dinic(s,t));
}

