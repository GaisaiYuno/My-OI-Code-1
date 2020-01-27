#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct
{
    int f,w,nex;
}graph[30002];
int tail=10001;

struct edge___
{
    int s,t,w;
}edges[50001];

bool cmp(edge___ a,edge___ b)
{
    return a.w<b.w;
}

int e,v,times=0;
int find(int);
void merge(int,int);
void reset(int);
void mintree();//最小生成树 
void dfs(int,int);//获取节点的深度 
void init();//树上倍增初始化 
int lca(int,int);//查询最大值 
int p_parents[10001][18];
int max_parents[10001][18];
int deepth[10001];
bool vis[10001];

inline void read(int &x)
{
    x=0;char ch=getchar();bool f=0;
    while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(((x<<2)+x)<<1)+ch-48;ch=getchar();}
    if(f)x=-x;
}

int main()
{
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    read(v);read(e);
    for(int i=0;i<e;i++)
    {
        read(edges[i].s);
        read(edges[i].t);
        read(edges[i].w);
    }
    mintree();
    for(int i=1;i<=v;i++)
    {
        if(!vis[i]) dfs(i,0);
    }
    deepth[0]=-1;
    init();
    int p,s,t;
    read(p);
    while(p--)
    {
        read(s);read(t);
        if(find(s)!=find(t)) puts("-1");
        else printf("%d\n",lca(s,t));
    }
    return 0;
}

int ranks[10001],father[10001];

void reset(int n)
{
    for(int i=0;i<n;i++)
    {
        father[i]=i;
        ranks[i]=0;
    }
}

int find(int x)
{
    while(father[x]!=x) x=father[x];return x;
}

void merge(int x,int y)
{
    int a=find(x),b=find(y);
    if(ranks[a]<ranks[b])
    {
        father[a]=b;
    }
    else
    {
        father[b]=a;
        if(ranks[b]==ranks[a])
        {
            ++ranks[a];
        }
    }
}

void mintree()
{
    int tmp1,tmp2;
    sort(edges,edges+e,cmp);
    reset(v+1);
    for(int i=0;i<e;i++)
    {
        if(find(edges[i].s)!=find(edges[i].t))
        {
            tmp1=graph[edges[i].s].nex;
            tmp2=graph[edges[i].t].nex;
            graph[edges[i].s].nex=++tail;
            graph[edges[i].t].nex=++tail;
            graph[tail-1].f=edges[i].t;
            graph[tail].f=edges[i].s;
            graph[tail-1].w=edges[i].w;
            graph[tail].w=edges[i].w;
            graph[tail-1].nex=tmp1;
            graph[tail].nex=tmp2;
            merge(edges[i].s,edges[i].t);
        }
    }
}

void dfs(int now,int d)
{
    vis[now]=true;
    deepth[now]=d;
    for(int i=graph[now].nex;i;i=graph[i].nex)
    {
        if(!vis[graph[i].f])
        {
            p_parents[graph[i].f][0]=now;
            max_parents[graph[i].f][0]=graph[i].w;
            dfs(graph[i].f,d+1);
        }
    }
}

void init()
{
    for(int j=1;j<18;j++)
    {
        for(int i=1;i<=v;i++)
        {
            if(deepth[i]<(1<<j)) continue;
            p_parents[i][j]=p_parents[p_parents[i][j-1]][j-1];
            max_parents[i][j]=max(max_parents[i][j-1],max_parents[p_parents[i][j-1]][j-1]);
        }
    }
}

int lca(int a,int b)
{
    int ans=0;
    if(deepth[a]>deepth[b]) swap(a,b);
    for(int i=17;i>=0;i--)
    {
        if(deepth[p_parents[b][i]]>=deepth[a]) 
        {
            ans=max(ans,max_parents[b][i]);
            b=p_parents[b][i];
        }
    }
    if(a==b) return ans;
    for(int i=17;i>=0;i--)
    {
        if(p_parents[a][i]!=p_parents[b][i])
        {
            ans=max(ans,max(max_parents[a][i],max_parents[b][i]));
            a=p_parents[a][i];
            b=p_parents[b][i];
        }
    }
    return max(ans,max(max_parents[a][0],max_parents[b][0]));
}
