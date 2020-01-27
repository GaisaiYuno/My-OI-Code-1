#include<cstdio>

typedef long long ll;
template<class T>
inline void read(T&x)
{
    x=0;bool f=0;char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar(); if(c=='-')f=1,c=getchar();
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x=f?-x:x;
}
const int MAXN(60);
const double eps(1e-6);
int n,m,val[MAXN][MAXN],row[MAXN][MAXN],line[MAXN][MAXN],sum;
double ans;
struct Node{int nd,nx,v,c;}bot[MAXN*MAXN<<2];int tot,first[MAXN*MAXN];
int P(int x,int y){return (x-1)*(m+1)+y;}
void add(int a,int b,int v,int c){
	printf("debug:%d %d %d %d\n",a,b,v,c);
bot[++tot]=(Node){b,first[a],v,c};first[a]=tot;
}
void build()
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)val[i][j]+=val[i-1][j];
    for(int i=1;i<=n+1;i++)
    for(int j=1;j<=m;j++)
        add(P(i,j),P(i,j+1),val[i-1][j],row[i][j]),
        add(P(i,j+1),P(i,j),-val[i-1][j],row[i][j]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m+1;j++)
        add(P(i,j),P(i+1,j),0,line[i][j]),
        add(P(i+1,j),P(i,j),0,line[i][j]);
}
double dis[MAXN*MAXN],limt;
bool vis[MAXN*MAXN],flag;
void dfs(int x)
{
    vis[x]=true;
    for(int v=first[x];v;v=bot[v].nx)
    if(dis[bot[v].nd]>dis[x]+bot[v].c*limt-bot[v].v+eps)
    {
        if(vis[bot[v].nd]){flag=true;return;};
        dis[bot[v].nd]=dis[x]+bot[v].c*limt-bot[v].v;
        dfs(bot[v].nd);if(flag)return;
    }
    vis[x]=false;
}
bool ok(double mid)
{
    limt=mid; flag=false; for(int i=1;i<=(n+1)*(m+1);i++)dis[i]=vis[i]=0;
    for(int i=1;i<=(n+1)*(m+1);i++)
    {
        dfs(i);if(flag)return true;
    }
    return false;
}
int main()
{
//    freopen("C.in","r",stdin);
//    freopen("C.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)read(val[i][j]),sum+=val[i][j];
    for(int i=1;i<=n+1;i++)
    for(int j=1;j<=m;j++)read(row[i][j]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m+1;j++)read(line[i][j]);
    build();
    for(double l=0,r=sum,mid;l+eps<r;)
        if(ok(mid=(l+r)/2))l=mid,ans=mid;else r=mid;
    printf("%.3lf",ans);
    return 0;
}
