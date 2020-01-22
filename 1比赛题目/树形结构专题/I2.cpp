#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,tot,al;
char ch;
int roots[100010],pre[100010],c[100010],w[100010],top[100010],fa[100010],son[100010],siz[100010],dep[100010],L[100010],first[100010];
struct os
{
    int u,v,next;
}e[200010];
struct node
{
    int maxn,sum,lson,rson;
}tree[4000010];
void pushup(int now)
{
    tree[now].maxn=max(tree[tree[now].lson].maxn,tree[tree[now].rson].maxn);
    tree[now].sum=tree[tree[now].lson].sum+tree[tree[now].rson].sum;
}
void add(int x,int y)
{
    e[++tot].u=x;
    e[tot].v=y;
    e[tot].next=first[x];
    first[x]=tot;
}
void dfs1(int now)
{
    siz[now]=1;
    for (int i=first[now];i;i=e[i].next)
    if (e[i].v!=fa[now])
    {
        fa[e[i].v]=now;
        dep[e[i].v]=dep[now]+1;
        dfs1(e[i].v);
        if (siz[e[i].v]>siz[son[now]]) son[now]=e[i].v;
        siz[now]+=siz[e[i].v];
    }
}
void dfs2(int now,int tp)
{
    top[now]=tp;
    pre[++cnt]=now;
    L[now]=cnt;
    if (son[now]) dfs2(son[now],tp);
    for (int i=first[now];i;i=e[i].next)
    if (e[i].v!=fa[now]&&e[i].v!=son[now]) dfs2(e[i].v,e[i].v);
}
void update(int &now,int begin,int end,int pos,int num)
{
    if (!now) now=++al;
    if (begin==end) {tree[now].maxn=tree[now].sum=num;return;}
    int mid=(begin+end)>>1;
    if (pos<=mid) update(tree[now].lson,begin,mid,pos,num);
    else update(tree[now].rson,mid+1,end,pos,num);
    pushup(now);
}
int get_sum(int now,int begin,int end,int l,int r)
{
    if (l<=begin&&end<=r) return tree[now].sum;
    int mid=(begin+end)>>1,ans=0;
    if (mid>=l) ans+=get_sum(tree[now].lson,begin,mid,l,r);
    if (mid<r) ans+=get_sum(tree[now].rson,mid+1,end,l,r);
    return ans;
}
int get_max(int now,int begin,int end,int l,int r)
{
    if (l<=begin&&end<=r) return tree[now].maxn;
    int mid=(begin+end)>>1,ans=0;
    if (mid>=l) ans=max(ans,get_max(tree[now].lson,begin,mid,l,r));
    if (mid<r) ans=max(ans,get_max(tree[now].rson,mid+1,end,l,r));
    return ans;
}
void solve(int color,int l,int r)
{
    int f1=top[l],f2=top[r],ans=0;
    while (f1!=f2)
    {
        if (dep[f1]<dep[f2]) swap(f1,f2),swap(l,r);
        if (ch=='S') ans+=get_sum(roots[color],1,cnt,L[f1],L[l]);
        else ans=max(ans,get_max(roots[color],1,cnt,L[f1],L[l]));
        l=fa[f1];f1=top[l];
    }
    if (dep[l]>dep[r]) swap(l,r);
    if (ch=='S') ans+=get_sum(roots[color],1,cnt,L[l],L[r]);
    else ans=max(ans,get_max(roots[color],1,cnt,L[l],L[r]));
    printf("%d\n",ans);
}
main()
{
    scanf("%d%d",&n,&m);
    int x,y,z;
    for (int i=1;i<=n;i++)
    scanf("%d%d",&w[i],&c[i]);
    for (int i=1;i<n;i++)
    scanf("%d%d",&x,&y),
    add(x,y),add(y,x);
    dfs1(1);
    dfs2(1,1);
    for (int i=1;i<=n;i++)
    update(roots[c[i]],1,cnt,L[i],w[i]);
    while (m--)
    {
        ch=getchar();
        while (ch!='C'&&ch!='Q') ch=getchar();
        if (ch=='C')
        {
            ch=getchar();
            scanf("%d%d",&x,&y);
            if (ch=='C')
                update(roots[c[x]],1,n,L[x],0),
                c[x]=y,
                update(roots[c[x]],1,n,L[x],w[x]);
            else
                update(roots[c[x]],1,n,L[x],y),w[x]=y;
        }
        else
            ch=getchar(),
            scanf("%d%d",&x,&y),
            solve(c[x],x,y);
    }
}
