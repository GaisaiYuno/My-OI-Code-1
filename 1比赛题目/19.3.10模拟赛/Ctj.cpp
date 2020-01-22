#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cctype>
#include <cmath>

using namespace std;

typedef double db;

typedef pair<int,db> PI;
#define mkp(a,b) make_pair(a,b)
#define ft first
#define sd second

const int N=35;
const int M=35;
const int A=18;
const int S=1<<A;
const int INF=INT_MAX/3;

int V[N],P[N],C[M],D[M];
int n,m,T,a,b;
PI sta[A+5][S];
db sum[A+5][S];
int f[N][M];
int cnt[A+5];
db ans;

void dp()
{
    for (int i=0;i<=n;i++)
        for (int j=0;j<=m+1;j++)
            f[i][j]=INF;
    for (int i=0;i<=n;i++) f[i][0]=0;
    for (int i=1;i<=m;i++)//food id
        for (int k=i;k>=1;k--)//food sum
            for (int j=n;j>=D[i];j--)//diamond
                f[j][k]=min(f[j][k],f[j-D[i]][k-1]+C[i]);
}

void store(db pro,int d,int v){sta[d][++cnt[d]]=mkp(v,pro);}

void dfs1(int x,db pro,int d,int v)//id probably diamonds value
{
    if (x==a+1)
    {
        store(pro,d,v);
        return;
    }
    dfs1(x+1,pro*P[x]/100.0,d,v+V[x]),dfs1(x+1,pro*(100-P[x])/100.0,d+1,v);
}

void make_pre()
{
    dfs1(1,1.0,0,0);
    for (int i=0;i<=a;i++)
        if (cnt[i])
        {
            sort(sta[i]+1,sta[i]+cnt[i]+1),sum[i][0]=0;
            for (int j=1;j<=cnt[i];j++) sum[i][j]=sum[i][j-1]+sta[i][j].sd;
        }
}

int search(int x,int d)
{
    int ret=0,l=1,r=cnt[d],mid;
    while (l<=r)
    {
        mid=l+r>>1;
        if (sta[d][mid].ft<x) ret=mid,l=mid+1;
        else r=mid-1;
    }
    return ret;
}

void calc(db pro,int d,int v)
{
    for (int d0=0;d0<=a&&d0<=n-d;d0++)
    {
        if (!cnt[d0]) continue;
        for (int ts=1;ts<=m;ts++)
        {
            int L=f[d0+d][ts]-v,R=f[d0+d][ts+1]-v;
            int l=search(L,d0),r=search(R,d0);
            ans+=ts*pro*(sum[d0][r]-sum[d0][l]);
        }
    }
}

void dfs2(int x,db pro,int d,int v)
{
    if (x==n+1)
    {
        calc(pro,d,v);
        return;
    }
    dfs2(x+1,pro*P[x]/100.0,d,v+V[x]),dfs2(x+1,pro*(100-P[x])/100.0,d+1,v);
}

void solve()
{
    ans=0.0,dfs2(a+1,1.0,0,0);
}

int main()
{
    freopen("4.in","r",stdin);
    for (scanf("%d",&T);T;T--)
    {
        scanf("%d%d",&n,&m);
        memset(cnt,0,sizeof cnt),memset(sta,0,sizeof sta),memset(sum,0,sizeof sum);
        for (int i=1;i<=n;i++) scanf("%d%d",&V[i],&P[i]);
        for (int i=1;i<=m;i++) scanf("%d%d",&C[i],&D[i]);
        a=min(n*2/3,A),b=n-a;
        dp(),make_pre(),solve();
        printf("%.4lf\n",ans);
    }
    fclose(stdin),fclose(stdout);
    return 0;
}

