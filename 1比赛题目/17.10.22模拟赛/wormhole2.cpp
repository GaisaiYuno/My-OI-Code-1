#include <cstdio>
#include <cstdlib>
#include <cstring>
#define fr(k) edge[k].from
#define nx(k) edge[k].next
#define ev(k) edge[k].value
#define to(k) edge[k].to
#define ll long long
const ll maxn=100000;
ll hd[maxn],mm[maxn],c[maxn],d[maxn],f,n,m,w,x,y,z;
bool m1[maxn],mark;
struct edge
{
    ll from,next,value,to;
}edge[maxn<<1];
void add(ll x,ll y,ll v,ll k)
{
    fr(k)=x;
    to(k)=y;
    ev(k)=v;
    nx(k)=hd[x];
    hd[x]=k;
}
ll spfa(ll s)
{
    ll l,r;
    memset(m1,false,sizeof(m1));
    memset(mm,0,sizeof(mm));
    memset(c,0,sizeof(c));
    l=1;
    r=1;
    c[1]=s;
    d[s]=0;
    m1[s]=true;
    mm[s]=1;
    for (int i=1;i<=n;i++)
        if (i!=s) d[i]=2147483647;
    while (l<=r)
    {
        for (int i=hd[c[l]];i!=0;i=nx(i))
            if (ev(i)+d[c[l]]<d[to(i)])
            {
                d[to(i)]=ev(i)+d[c[l]];
                if (m1[to(i)]==false)
                {
                    r++;
                    c[r]=to(i);
                    m1[to(i)]=true;
                    mm[to(i)]++;
                    if (mm[to(i)]>n) return 1;
                }
            }
        m1[c[l]]=false;
        l++;    
    }
    return 0;
}
int main()
{
    scanf("%d",&f);
    for (int i=1;i<=f;i++)
    {
        memset(edge,0,sizeof(edge));
        memset(hd,0,sizeof(hd));
        scanf("%lld%lld%lld",&n,&m,&w);
        for (int j=1;j<=m;j++)
        {
            scanf("%lld%lld%lld",&x,&y,&z);
            add(x,y,z,j);
            add(y,x,z,j+m);
        }
        for (int j=1;j<=w;j++)
        {
            scanf("%lld%lld%lld",&x,&y,&z);
            add(x,y,-z,2*m+j);
        }
        if (spfa(1)==1) printf("YES\n");
            else printf("NO\n");
    }
    return 0;
}
