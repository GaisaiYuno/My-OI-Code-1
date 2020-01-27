#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define ld long double
using namespace std;

const int maxn = 35;

int n,m;
ld p[maxn];
int v[maxn],c[maxn],d[maxn];

void upd(int &x,const int &y){ if(x==-1||y<x) x=y; }
int now; int f[2][maxn][maxn];
void dp()
{
    memset(f,-1,sizeof f);
    now=0; f[now][0][0]=0;
    for(int i=1;i<=m;i++)
    {
        now=!now;
        for(int j=0;j<=i-1;j++) for(int k=0;k<=n;k++) if(f[!now][j][k]!=-1)
        {
            int &temp=f[!now][j][k];
            upd(f[now][j][k],temp);
            if(k+d[i]<=n) upd(f[now][j+1][k+d[i]],temp+c[i]);
            temp=-1;
        }
    }
    for(int i=0;i<=m;i++) for(int k=1;k<=n;k++) if(f[now][i][k-1]!=-1)
        upd(f[now][i][k],f[now][i][k-1]);
}
struct node
{
    ld p; int x;
    friend inline bool operator <(const node a,const node b){ return a.x<b.x; }
}zero;
vector<node>V1[maxn],V2[maxn];

int main()
{
    freopen("4.in","r",stdin);
    //freopen("tmp.out","w",stdout);

    zero.p=1.0,zero.x=0;

    int tcase; scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) 
        {
            int x; scanf("%d%d",&v[i],&x);
            p[i]=(ld)x/100.0;
        }
        for(int i=1;i<=m;i++) scanf("%d%d",&c[i],&d[i]);

        dp();
        int hf=n>>1;

        int al=1<<hf;
        for(int i=0;i<=hf;i++) V1[i].clear();
        for(int i=0;i<al;i++)
        {
            node tmp=zero;
            int k=0;
            for(int j=1;j<=hf;j++)
            {
                if(i>>(j-1)&1) tmp.p*=p[j],tmp.x+=v[j];
                else tmp.p*=(1.0-p[j]),k++;
            }
            V1[k].push_back(tmp);
        }
        for(int i=0;i<=hf;i++) sort(V1[i].begin(),V1[i].end());

        al=1<<(n-hf);
        for(int i=0;i<=n-hf;i++) V2[i].clear();
        for(int i=0;i<al;i++)
        {
            node tmp=zero;
            int k=0;
            for(int j=hf+1;j<=n;j++)
            {
                if(i>>(j-hf-1)&1) tmp.p*=p[j],tmp.x+=v[j];
                else tmp.p*=(1.0-p[j]),k++;
            }
            V2[k].push_back(tmp);
        }
        for(int i=0;i<=n-hf;i++) sort(V2[i].begin(),V2[i].end());

        ld ans=0.0;
        for(int i=0;i<=hf;i++) if(V1[i].size())
            for(int j=0;j<=n-hf;j++) if(V2[j].size())
            {
                for(int k=1;k<=m&&f[now][k][i+j]!=-1;k++)
                {
                    int temp=f[now][k][i+j];
                    int y=(int)V2[j].size()-1; ld cc=0;
                    for(int x=0;x<(int)V1[i].size();x++)
                    {
                        while(y>=0&&V1[i][x].x+V2[j][y].x>=temp) cc+=V2[j][y].p,y--;
                        ans+=V1[i][x].p*cc;
                    }
                }
            }
        printf("%.4Lf\n",ans);
    }
    return 0;
}

