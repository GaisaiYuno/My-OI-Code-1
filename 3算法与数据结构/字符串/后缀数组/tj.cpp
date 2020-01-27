//P4094
#include <bits/stdc++.h>
#define y1 y1_
#define index index_
#define pipe pipe_
#define next next_
#define rgi register int
//#define ll long long
#define Pi acos(-1.0)
#define lowbit(x) ((x&(-x)))
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define fst first
#define scd second
using namespace std;
inline int read() {
    int f=1,x=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=1e5+5;
const int INF=2e9;
char s[MAXN];
int n;
struct HouZhuiShuZu{
    int sa[MAXN],x[MAXN],y[MAXN],c[MAXN],rk[MAXN],ht[MAXN],st[30][MAXN],LOG[MAXN];
    void init() {
        int m=(int)'z';
        for(rgi i=1;i<=n;++i) c[x[i]=s[i]]++;
        for(rgi i=1;i<=m;++i) c[i]+=c[i-1];
        for(rgi i=n;i>=1;--i) sa[c[x[i]]--]=i;
        for(rgi k=1;k<=n;k<<=1) {
            int num=0;
            for(rgi i=n-k+1;i<=n;++i) y[++num]=i;
            for(rgi i=1;i<=n;++i) if(sa[i]>k) y[++num]=sa[i]-k;
            for(rgi i=1;i<=m;++i) c[i]=0;
            for(rgi i=1;i<=n;++i) c[x[i]]++;
            for(rgi i=1;i<=m;++i) c[i]+=c[i-1];
            for(rgi i=n;i>=1;--i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
            swap(x,y);
            //for(rgi i=1;i<=n;++i) swap(x[i],y[i]);
            x[sa[1]]=1; num=1;
            for(rgi i=2;i<=n;++i) {
                x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
            }
            if(num==n) break;
            m=num;
        }

        for(rgi i=1;i<=n;++i) rk[sa[i]]=i;
        int k=0;
        for(rgi i=1;i<=n;++i) {
            if(rk[i]==1) continue;
            if(k)--k;
            int j=sa[rk[i]-1];
            while(i+k<=n && j+k<=n && s[i+k]==s[j+k]) k++;
            ht[rk[i]]=k;
        }

        for(rgi j=1;j<=n;++j) st[0][j]=ht[j];
        for(rgi i=1;(1<<i)<=n;i++) {
            for(rgi j=1;j+(1<<(i-1))<=n+1;++j){
                st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
            }
        }

        LOG[0]=-1;
        for(rgi i=1;i<=n;++i) LOG[i]=LOG[i>>1]+1;
    }
    inline int lcp(int l,int r) {
        /*左闭右闭RMQ*/
        if(l>r) return INF;
        int lg=LOG[r-l+1];
        return min(st[lg][l],st[lg][r-(1<<lg)+1]);
    }
}sa;
struct ZhuXiTree{
    struct TREE {
        int ls,rs,sum;
    }t[MAXN*40];
    int root[MAXN],cnt;
    void insert(int l,int r,int rt,int &nrt,int pos) {
        nrt=++cnt; t[nrt]=t[rt]; t[nrt].sum++;
        if(l==r) return ;
        int mid=(l+r)>>1;
        if(pos<=mid) insert(l,mid,t[rt].ls,t[nrt].ls,pos);
        else insert(mid+1,r,t[rt].rs,t[nrt].rs,pos);
    }
    int query(int l,int r,int rt1,int rt2,int ql,int qr) {
        if(ql>=qr || t[rt2].sum-t[rt1].sum==0) return 0;
        if(ql <= l && r <= qr) return t[rt2].sum-t[rt1].sum;
        int mid=(l+r)>>1;
        int res=0;
        if(ql<=mid) res+=query(l,mid,t[rt1].ls,t[rt2].ls,ql,qr);
        if(qr>mid)  res+=query(mid+1,r,t[rt1].rs,t[rt2].rs,ql,qr);
        return res;
    }
}zx;
void print(int x)
{
    if(x<0)//负数
    {
        putchar('-');
        x=-x;
    }
    if(x>9) 
        print(x/10);
    putchar(x%10+'0'); 
}
int main() {
//  freopen("","r",stdin);
//  freopen("","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);/*syn加速*/
    n=read(); int Q=read();
    scanf("%s",s+1);
    sa.init();
    for(rgi i=1;i<=n;++i) {
        zx.insert(1,n,zx.root[i-1],zx.root[i],sa.rk[i]);
    }
    while(Q--) {
        int a=read(),b=read(),c=read(),d=read(); 
        int l=0,r=min(b-a+1,d-c+1);
        while(l<r) {
            int mid=(l+r+1)>>1;
            int lrange,rrange;
            int ll=1,rr=sa.rk[c],mm;
            while(ll<rr) {
                mm=(ll+rr)>>1;
                if(sa.lcp(mm+1,sa.rk[c])>=mid) rr=mm;
                else ll=mm+1;
            }
            lrange=ll;
            ll=sa.rk[c]; rr=n;
            while(ll<rr) {
                mm=(ll+rr+1)>>1;
                if(sa.lcp(sa.rk[c]+1,mm)>=mid) ll=mm;
                else rr=mm-1;
            }
            rrange=ll;
            if(zx.query(1,n,zx.root[a-1],zx.root[b-mid+1],lrange,rrange)) l=mid;
            else r=mid-1;
        }
        print(l);puts("");
    }
    return 0;
}
