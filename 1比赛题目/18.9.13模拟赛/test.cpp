#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;

int a[maxn],n;
vector<int>g[maxn];
set<int>s[maxn];

void dfs(int x,int fa,int now)
{
    for(auto p:s[fa])
        s[x].insert(__gcd(p,a[x]));
    s[x].insert(now);       //µ±«∞µ„÷√¡„
    now=__gcd(now,a[x]);

    for(auto p:g[x])
        if(p!=fa)
            dfs(p,x,now);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",a+i);
    int u,v;
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    s[1].insert(a[1]);
    dfs(1,0,0);
    for(int i=1; i<=n; i++)
        printf("%d ",*s[i].rbegin());
    return 0;
}
