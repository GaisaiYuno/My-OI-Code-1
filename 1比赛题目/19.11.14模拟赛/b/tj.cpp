#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int head[200010];
int to[400010];
int dep[200010];
int next[400010];
int mx[200010];
int son[200010];
int st[200010];
int top;
int tot;
int S,T;
int res;
int ans[200010];
int n,m;
int x,y;
int col[200010];
int cnt[200010];
void add(int x,int y)
{
    next[++tot]=head[x];
    head[x]=tot;
    to[tot]=y;
}
void pop()
{
    cnt[col[st[top]]]--;
    res-=(cnt[col[st[top]]]==0);
    top--;
}
void push(int x)
{
    st[++top]=x;
    cnt[col[x]]++;
    res+=(cnt[col[x]]==1);
}
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=next[i])
    {
        if(to[i]!=fa)
        {
            dfs(to[i],x);
        }
    }
}
void dfs1(int x,int fa)
{
    son[x]=0;
    mx[x]=0;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=next[i])
    {
        if(to[i]!=fa)
        {
            dfs1(to[i],x);
            if(mx[to[i]]>mx[son[x]])
            {
                son[x]=to[i];
            }
        }
    }
    mx[x]=mx[son[x]]+1;
}
void dfs2(int x,int fa)
{
    if(!son[x])
    {
        ans[x]=max(ans[x],res);
        return ;
    }
    int len=0;
    for(int i=head[x];i;i=next[i])
    {
        if(to[i]!=fa&&to[i]!=son[x])
        {
            len=max(len,mx[to[i]]);
        }
    }
    while(top&&dep[st[top]]>=dep[x]-len)
    {
        pop();
    }
    push(x);
    dfs2(son[x],x);
    for(int i=head[x];i;i=next[i])
    {
        if(to[i]!=fa&&to[i]!=son[x])
        {
            while(top&&dep[st[top]]>=dep[x]-mx[son[x]])
            {
                pop();
            }
            push(x);
            dfs2(to[i],x);
        }
    }
    while(top&&dep[st[top]]>=dep[x]-mx[son[x]])
    {
        pop();
    }
    ans[x]=max(ans[x],res);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&col[i]);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        S=dep[i]>dep[S]?i:S;
    }
    dfs(S,0);
    for(int i=1;i<=n;i++)
    {
        T=dep[i]>dep[T]?i:T;
    }
    S=5;
    dfs1(S,0);
    dfs2(S,0);
    dfs1(T,0);
    dfs2(T,0);
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",ans[i]);
    }
}
