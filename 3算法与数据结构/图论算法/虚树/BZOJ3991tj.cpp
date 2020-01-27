#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
#define MOD 1000000007
#define inf 2147483647
#define LL long long
#define free(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
using namespace std;
inline LL getint() {
    LL x=0,f=1;char ch=getchar();
    while (ch>'9' || ch<'0') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int maxn=100010;
struct edge {int next,to,w;}e[maxn<<2];
int head[maxn],fa[maxn][20],bin[20],deep[maxn],b[maxn],num[maxn],dfn[maxn],a[maxn];
int cnt,n,m;
LL w[maxn];
set<int> s;

void insert(int u,int v,int w) {
    e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;e[cnt].w=w;
    e[++cnt].to=u;e[cnt].next=head[v];head[v]=cnt;e[cnt].w=w;
}
void dfs(int u) {
    dfn[u]=++cnt;num[cnt]=u;
    for (int i=1;i<20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for (int i=head[u];i;i=e[i].next) if (e[i].to!=fa[u][0]) {
            w[e[i].to]=w[u]+(LL)e[i].w;
            deep[e[i].to]=deep[u]+1;
            fa[e[i].to][0]=u;
            dfs(e[i].to);
        }
}
int lca(int x,int y) {
    if (deep[x]<deep[y]) swap(x,y);
    int t=deep[x]-deep[y];
    for (int i=0;bin[i]<=t;i++) if (bin[i]&t) x=fa[x][i];
    for (int i=19;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return x==y?x:fa[x][0];
}
LL dis(int x,int y) {
    return w[x]+w[y]-2*w[lca(x,y)];
}
int main() {
    bin[0]=1;for (int i=1;i<20;i++) bin[i]=bin[i-1]<<1;
    scanf("%d%d",&n,&m);
    for (int i=1;i<n;i++) {
        int u=getint(),v=getint(),w=getint();
        insert(u,v,w);
    }
    cnt=0;
    dfs(1);
    LL ans=0;
    s.insert(inf);s.insert(-inf);
    while (m--) {
        LL x=getint(),t;
        if (b[x]) s.erase(dfn[x]),t=-1;
        else s.insert(dfn[x]),t=1;
        b[x]^=1;
        int l=*--s.lower_bound(dfn[x]),r=*s.upper_bound(dfn[x]);
        if (l!=-inf) ans+=(LL)t*dis(num[l],x);
        if (r!=inf) ans+=(LL)t*dis(num[r],x);
        if (l!=-inf && r!=inf) ans-=(LL)t*dis(num[l],num[r]);
        if (s.size()>3) t=dis(num[*s.upper_bound(-inf)],num[*--s.lower_bound(inf)]);
        else t=0;
        printf("%lld\n",ans+t);
    }
    return 0;
}

