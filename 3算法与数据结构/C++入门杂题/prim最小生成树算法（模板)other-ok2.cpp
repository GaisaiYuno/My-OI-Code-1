#include <bits/stdc++.h>
#define MAXV 5005
#define INF 0x3fffffff
using namespace std;
struct Node
{
    int v ,w;
    Node(int _v ,int _w) : v(_v) ,w(_w) {}
};
vector<Node> G[MAXV];
int n ,m ,u ,v ,w;
int d[MAXV];
bool vis[MAXV];
int prim();
int main()
{
    scanf("%d%d" ,&n ,&m);
    for(int i=1 ;i<=m ;i++) {
        scanf("%d%d%d" ,&u ,&v ,&w);
        G[u].push_back(Node(v ,w));
        G[v].push_back(Node(u ,w));
    }
    int Ans=prim();
    if(Ans==-1) printf("orz");
    else printf("%d" ,Ans);
    return 0;
}
int prim()
{
    fill(d ,d+MAXV ,INF);
    d[1]=0;
    int ans=0;
    for(int i=1 ;i<=n ;i++) {
        int u=-1 ,minn=INF;
        for(int j=1 ;j<=n ;j++)
            if(!vis[j] && d[j]<minn) {
                u=j;
                minn=d[j];
            }
        if(u==-1)   return -1;
        vis[u]=true;
        ans+=d[u];
        for(int j=0 ;j<G[u].size() ;j++) {
            int v=G[u][j].v;
            if(!vis[v] && G[u][j].w<d[v])
                d[v]=G[u][j].w;
        }
    }
    return ans;
}

