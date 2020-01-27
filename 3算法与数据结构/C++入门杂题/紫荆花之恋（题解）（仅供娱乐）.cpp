#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
inline int read()//读入优化 
{
    char ch;
    int res=0;
    while(ch=getchar(),ch<'0'||ch>'9');
    res=ch-48;
    while(ch=getchar(),ch>='0'&&ch<='9')
    res=(res<<3)+(res<<1)+ch-48;
    return res;
} 
inline void put(long long x)//输出优化 
{
    if(x>9)put(x/10);
    putchar(x%10+48);
}
const double alpha=0.777666;
const int e=1e5+5,mod=1e9,inf=0x3f3f3f3f;
int test,n,r[e],fa[e],sze[e],son[e],num,next[e<<1],head[e],go[e<<1],cost[e<<1];
int dist[e];
long long ans=0;
bool vis[e];
vector<int>anc[e],id[e],sons[e];
inline void add(int x,int y,int v)//建边 
{
    next[++num]=head[x]; 
    head[x]=num;
    go[num]=y;
    cost[num]=v;
    next[++num]=head[y];
    head[y]=num;
    go[num]=x;
    cost[num]=v;
}
struct node
{
    node *lc,*rc; 
    int val,sze,pos;
    inline void reset(int v) 
    {
        lc=rc=NULL;
        val=v;
        sze=1;
        pos=rand();
    }
    inline void update() 
    {
        sze=(lc?lc->sze:0)+(rc?rc->sze:0)+1;
    }
}*rt_self[e],*rt_fa[e],used[4000006],*unused[4000006],*pool=used,**top=unused;
/*当grav为分治中心时，rt_self[grav]表示存储dist(i,grav)-ri的treap的根结点 
设grav在点分树上的父亲为f，rt_fa[grav]表示存储dist(i,f)-ri的根结点(非法情况)*/ 
inline node* new_node(int val)
{
    node *res=(top!=unused)? *--top:pool++;//将用过的并且删过的点的编号放入unused
    //新建节点的时候可以再使用这些编号，可以省空间 
    res->reset(val);
    return res;
}
inline void del_node(node *&u)
{
    if(!u)return;
    *top++=u;
    if(u->lc)del_node(u->lc);
    if(u->rc)del_node(u->rc);
    u=NULL;
}
inline void zig(node *&u)
{
    node *v=u->lc;
    u->lc=v->rc;
    v->rc=u;
    v->sze=u->sze;
    u->update();
    u=v;
}
inline void zag(node *&u)
{
    node *v=u->rc;
    u->rc=v->lc;
    v->lc=u;
    v->sze=u->sze;
    u->update();
    u=v;
}
inline void insert(node *&u,int val)
{
    if(!u)
    {
        u=new_node(val);
        return;
    }
    ++u->sze;
    if(val<=u->val)
    {
        insert(u->lc,val);
        if(u->lc->pos<u->pos)zig(u);
    }
    else
    {
        insert(u->rc,val);
        if(u->rc->pos<u->pos)zag(u);
    }
}
inline int qrank(node *u,int val)
{
    if(!u)return 0;
    if(val<u->val)return qrank(u->lc,val);
    else return (u->lc?u->lc->sze:0)+1+qrank(u->rc,val);
}
inline int calc_grav(int &st)//求树的重心 
{
    static int qn,que[e];
    que[qn=1]=st;
    fa[st]=0;
    for(int i=1;i<=qn;i++)
    {
        int u=que[i];
        sze[u]=1;
        son[u]=0;
        for(int j=head[u];j;j=next[j])
        {
            int v=go[j];
            if(!vis[v]||v==fa[u])continue;
            fa[v]=u;
            que[++qn]=v;
        }
    }
    for(int i=qn;i>=2;i--)
    {
        int u=que[i],v=fa[u];
        sze[v]+=sze[u];
        if(sze[u]>son[v])
        son[v]=sze[u];
    }
    int all=sze[st],grav=0,min=inf;
    for(int i=1;i<=qn;i++)
    {
        int u=que[i];
        if(all-sze[u]>son[u])
        son[u]=all-sze[u];
        if(son[u]<min)
        {
            min=son[u];
            grav=u;
        }
    }
    return grav;
}
inline int dac(int &st,int &par)//静态点分治，用于重建 
{
    static int qn,que[e];
    int grav=calc_grav(st);
    vis[grav]=false;//vis[]=false表示当前这个点已经当过分治中心 
    que[qn=1]=grav;
    fa[grav]=0;
    dist[grav]=0;
    for(int i=1;i<=qn;i++)
    {
        int u=que[i];
        for(int j=head[u];j;j=next[j])
        {
            int v=go[j];
            if(!vis[v]||v==fa[u])continue;
            fa[v]=u;
            dist[v]=dist[u]+cost[j];
            que[++qn]=v;
        }
    }
    for(int i=1;i<=qn;i++)
    {
        int u=que[i];
        id[u].push_back(grav);//id[u][i]表示u在点分树的所有祖先中(包括它自己)第i老的编号 
        anc[u].push_back(dist[u]);//anc[u][i]就是dist(u,id[u][i]) 
        //id[u][i]是id[u][i+1]点分树中的父亲，anc同理 
        sons[grav].push_back(u);//sons[u]存储在点分树中u的子树的所有节点 
        insert(rt_self[grav],dist[u]-r[u]);//所有情况 
        if(par!=0)
        insert(rt_fa[grav],anc[u][anc[u].size()-2]-r[u]);//非法情况 
    }
    for(int i=head[grav];i;i=next[i])
    {
        int v=go[i];
        if(vis[v])dac(v,grav);
    }
}
inline void rebuild(int &u,int par)//重建点分树的某一子树 
{
    vector<int>tmpson=sons[u];//要先把原来的sons[u]存了，因为下面sons[v].clear 
    int notres=anc[par].size();
    for(int i=0;i<tmpson.size();i++)//先把这棵子树部分的信息删了 
    {
        int v=tmpson[i];
        vis[v]=true;
        sons[v].clear();
        anc[v].resize(notres);//仅与子树的根结点的祖先们有关的信息还要留着 
        id[v].resize(notres);
        del_node(rt_self[v]);
        del_node(rt_fa[v]);
    }
    dac(u,par);//再将这棵子树中的所有点进行一次静态的点分治 
}
inline void check(int &u)
{
    for(int i=0;i<anc[u].size();i++)
    {
        insert(rt_self[id[u][i]],anc[u][i]-r[u]);//所有祖先的treap(包括它自己的)都要修改 
        if(i!=0)
        insert(rt_fa[id[u][i]],anc[u][i-1]-r[u]);
    }
    for(int i=0;i<anc[u].size()-1;i++)
    {
        int sze_fa=rt_self[id[u][i]]->sze;
        int sze_son=rt_self[id[u][i+1]]->sze;
        if(sze_fa<=30)break;
        if(sze_son>alpha*sze_fa)//过度不平衡，重建 
        {
            rebuild(id[u][i],i==0?0:id[u][i-1]);
            break;
        }
    }
}
inline int calc_ans(int &u,int &v,int &w)
{
    int res=0;
    anc[u]=anc[v];//当前结点的父亲的祖先也是它的祖先 
    id[u]=id[v];//存储的信息先由它父亲得来 
    anc[u].push_back(-w);//和+=w抵消 
    id[u].push_back(u);
    for(int i=0;i<anc[u].size();i++)
    {
        anc[u][i]+=w;
        sons[id[u][i]].push_back(u);
        res+=qrank(rt_self[id[u][i]],r[u]-anc[u][i]);//查询r[u]-dist[u,id[u][i]]的排名，即所有的情况 
        if(i!=0)
        res-=qrank(rt_fa[id[u][i]],r[u]-anc[u][i-1]);
        //查询r[u]-dist[u,id[u][i]的父亲]的排名，即非法情况 
    }
    return res;
}
int main()
{
    test=read();
    n=read();
    for(int i=1;i<=n;i++)
    {
        int fa_i=read(),c=read();
        r[i]=read();
        fa_i^=(ans%mod);
        if(i==1)
        {
            anc[i].push_back(0);
            id[i].push_back(i);
            sons[i].push_back(i);
            insert(rt_self[i],-r[i]);//第一个结点dist为0 
            puts("0");
            continue;
        }
        add(fa_i,i,c);
        ans+=calc_ans(i,fa_i,c);//累加包含当前结点且满足条件的点对的个数 
        check(i);//检查是否存在过度不平衡现象 
        put(ans);
        putchar('\n');
    }
    return 0;
}
