int ver[maxm],edge[maxm],Next[maxm],cost[maxm],head[maxn],len=1;
inline void add(int x,int y,int z,int c)
{
    ver[++len]=y,edge[len]=z,cost[len]=c,Next[len]=head[x],head[x]=len;
    ver[++len]=x,edge[len]=0,cost[len]=-c,Next[len]=head[y],head[y]=len;
}
 
int s,t;
int dist[maxn];
bool vis[maxn];
inline void spfa()
{
    for (int i=s; i<=t; ++i) dist[i]=-inf;
    memset(vis,0,sizeof(vis));
    queue<int>q;q.push(t);
    dist[t]=0,vis[t]=1;
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for (int i=head[x]; i; i=Next[i])
        {
            int y=ver[i];
            if (edge[i^1] && dist[y]<dist[x]+cost[i^1])
            {
                dist[y]=dist[x]+cost[i^1];
                if (!vis[y]) q.push(y),vis[y]=1;
            }
        }
    }
}
 
int ans;//开long long会WA最后三个点，鬼知道为什么
inline int get(int x,int low)
{
    if (x==t) { ans+=dist[s]*low; return low; }
    int tmp=0;
    vis[x]=1;
    for (int i=head[x]; i; i=Next[i])
    {
        int y=ver[i];
        if (edge[i] && !vis[y] && dist[x]==dist[y]+cost[i])
        {
            int a=get(y,min(low-tmp,edge[i]));
            edge[i]-=a,edge[i^1]+=a,tmp+=a;
            if (tmp==low) return tmp;
        }
    }
//    return tmp;
}
 
inline bool adjust()
{
    int tmp=-inf;
    for (int x=s; x<=t; ++x) if (vis[x])
        for (int i=head[x]; i; i=Next[i])
        {
            int y=ver[i];
            if (!vis[y] && edge[i]) tmp=max(tmp,dist[y]+cost[i]-dist[x]);
        }
    if (tmp==-inf) return false;
    for (int i=s; i<=t; ++i) if (vis[i]) dist[i]+=tmp;
    return true;
}
 
inline void zkw()
{
    spfa();
    do
        do memset(vis,0,sizeof(vis));
        while (get(s,inf));
    while (adjust());
}
 

