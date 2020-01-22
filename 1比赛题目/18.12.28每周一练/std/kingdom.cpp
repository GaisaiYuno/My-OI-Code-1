#include<cstdio>
#include<cstring>
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])
typedef long long ll;
const int M=(int)1e6+50;
void rd(int &x) {
    static char c;x=0;
    while(c=getchar(),c<48);
    do x=(x<<3)+(x<<1)+(c^48);
    while(c=getchar(),c>47);
}
int Head[M],E[M<<1],Nxt[M<<1],tol;
void Edge(int x,int y) {
    E[tol]=y;Nxt[tol]=Head[x];Head[x]=tol++;
}
int Fa[M];
int Find(int x) {
    return Fa[x]==x?x:Fa[x]=Find(Fa[x]);
}
bool del[M];
bool fff;
int line[M],top,S,T;
void dfs(int x,int fr) {
    line[++top]=x;
    if(x==S) {fff=true;return ;}
    EOR(i,x) if(E[i]!=fr) {
        dfs(E[i],x);if(fff) return ;
    }
    line[top--]=x;
}
ll sz[M],sum[M];
ll lsum[M],rsum[M];
ll Tmp[M][2];
ll res;
int n;
void rdfs(int x,int fr) {
    int y;sz[x]=1;
    EOR(i,x) if((y=E[i])!=fr && !del[y]) {
        rdfs(y,x);sz[x]+=sz[y];
        res+=sz[y]*(n-sz[y]);
    }
}
int main() {
    freopen("kingdom.in","r",stdin);
    freopen("kingdom.out","w",stdout);
    memset(Head,-1,sizeof(Head));
    rd(n);
    FOR(i,1,n) Fa[i]=i;
    FOR(i,1,n) {
        int x,y;
        rd(x);rd(y);
        if(Find(x)!=Find(y)) {
            Fa[Fa[x]]=Fa[y];
            Edge(x,y);
            Edge(y,x);
        } else S=x,T=y;
    }
    dfs(T,0);
    FOR(i,1,top) del[line[i]]=true;
    FOR(i,1,top) rdfs(line[i],0);
    FOR(i,1,top) sum[i]=sum[i-1]+sz[line[i]];
    FOR(i,1,top) lsum[i]=lsum[i-1]+sz[line[i]]*(i-1);
    DOR(i,top,1) rsum[i]=rsum[i+1]+sz[line[i]]*(top-i);
    int cnt;ll tmp;
    cnt=tmp=0;
    FOR(i,1,top-1) {
        Tmp[i][0]=tmp+rsum[i+1]+(sum[top]-sum[i])*i;
        cnt+=sz[line[i]];tmp+=cnt;
    }
    Tmp[top][0]=tmp;
    cnt=tmp=0;
    DOR(i,top,2) {
        Tmp[i][1]=tmp+lsum[i-1]+sum[i-1]*(top-i+1);
        cnt+=sz[line[i]];tmp+=cnt;
    }
    Tmp[1][1]=tmp;
    FOR(i,1,top-1) res+=sum[i]*(sum[top]-sum[i]);
    tmp=res;
    FOR(i,1,top-1) {
        tmp-=Tmp[i][1]*sz[line[i]];
        tmp+=Tmp[i][0]*sz[line[i]];
        if(tmp<res) res=tmp;
    }
    printf("%lld\n",res);
    return 0;
}
