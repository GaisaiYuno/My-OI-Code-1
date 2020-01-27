/*在这里来一发优先队列优化的prime 建议看之前先学习朴素的prime（然而建议你们先学最简单的Kruskal）

prime的思想是按点贪心

我们先用一个数组dist 表示如果添加了这个点需要增加的权值

因为是贪心 所以dist[ i ]越小越好

初始状态 所有dist全为一个很大的数（比方说0x7f7ff)

然后我们随机选择一个点 将它的dist变为0（我选择的是1号节点），并将它标记（因为最小生成树每个点只能用一次）

然后我们遍历与这个点相连的点 将它们的dist更新（更新为它们的边权值）

现在 我们得到了多个dist不为0x7f7ff的点了

于是 我们选择其中dist最小的点 标记它 然后再遍历与它相连的点，更新它们的dist

不断的重复 重复 直到所有点都被标记为止

当然 也存在orz的情况（虽然测试点并没有ORZ的情况 23333） 这时 被标记的点的数量是小于n的，加个判断就好啦

下面是朴素的pirme 时间复杂度O（N^2）
*/
#include<bits/stdc++.h>
#define INF 0x7f7ff
using namespace std;
int n,m,dist[5010],head[5010],k,ans;
bool vis[5010];
struct node
{
    int to,next,w;
}edge[400010];
void add(int u,int v,int w)
{
    edge[++k].to=v;
    edge[k].w=w;
    edge[k].next=head[u];
    head[u]=k;
}
void Prime()
{
    fill(dist+1,dist+n+1,INF);
    dist[1]=0;
    for(int j=1;j<=n;j++)
    {
        int u=-1,minn=INF;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]<minn&&!vis[i])
            {
                u=i;
                minn=dist[i];
            }
        }
        if(u==-1)
        {
            ans=-1;
            return;
        }
        vis[u]=1;
        ans+=dist[u];
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!vis[v]&&dist[v]>edge[i].w) dist[v]=edge[i].w;
        }
    }
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
