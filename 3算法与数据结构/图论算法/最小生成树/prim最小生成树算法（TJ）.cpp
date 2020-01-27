#include<bits/stdc++.h>
#define INF 0x7f7ff
using namespace std;
int n,m,dist[5010],head[5010],k,ans,tot;
bool vis[5010];
struct node
{
    int to,next,w;
}edge[400010];
struct p
{
    int id,d;
    bool operator < (const p &a) const
    {
        return a.d<d;
    }
};
void add(int u,int v,int w)
{
    edge[++k].to=v;
    edge[k].w=w;
    edge[k].next=head[u];
    head[u]=k;
}
void Prime()
{
    fill(dist+1,dist+1+n,INF);
    priority_queue<p> q;
    p now;
    now.id=1;now.d=dist[1]=0;
    q.push(now);
    while(!q.empty())
    {
        p now=q.top();q.pop();
        int u=now.id;
        if(now.d!=dist[u]) continue;
        vis[u]=1;
        ans+=dist[u];
        tot++;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!vis[v]&&dist[v]>edge[i].w)
            {
                dist[v]=edge[i].w;
                p nxt;
                nxt.d=dist[v];
                nxt.id=v;
                q.push(nxt);
            }
        }
    }
    if(tot<n) ans=-1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    Prime();
    if(ans==-1) cout<<"orz"<<endl;
    else cout<<ans;
}
