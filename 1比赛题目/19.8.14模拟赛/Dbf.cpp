#include<cstdio>
typedef long double ld;
typedef long long i64;
const int N=100007;
int n,es[N*2],enx[N*2],ev[N*2],e0[N],ep=2;
int c[N],v[N],ss[N],sp=0;
i64 f[N],dep[N];
int _(){
    int x;
    scanf("%d",&x);
    return x;
}
bool chk(int a,int b,int w){
    return (f[b]-f[a])/ld(dep[b]-dep[a])>(f[w]-f[b])/ld(dep[w]-dep[b]);
}
void f1(int w,int pa){
    if(sp){
        int L=1,R=sp,M;
        while(L<R){
            M=(L+R)>>1;
            int a=ss[M],b=ss[M+1];
            if(f[a]-f[b]<v[w]*(dep[a]-dep[b]))R=M;
            else L=M+1;
        }
        f[w]=c[w]+v[w]*(dep[w]-dep[ss[L]])+f[ss[L]];
    }
    int L=1,R=sp,M;
    if(L<R&&!chk(ss[R-1],ss[R],w))L=R;
    while(L<R){
        M=(L+R)>>1;
        if(chk(ss[M],ss[M+1],w))R=M;
        else L=M+1;
    }
    L=sp;
    M=ss[sp=R+1];
    ss[sp]=w;
    for(int i=e0[w];i;i=enx[i]){
        int u=es[i];
        if(u==pa)continue;
        dep[u]=dep[w]+ev[i];
        f1(u,w);
    }
    ss[sp]=M;
    sp=L;
}
int main(){
    n=_();
    for(int i=1,a,b,c;i<n;++i){
        a=_();b=_();c=_();
        es[ep]=b;enx[ep]=e0[a];ev[ep]=c;e0[a]=ep++;
        es[ep]=a;enx[ep]=e0[b];ev[ep]=c;e0[b]=ep++;
    }
    for(int i=2;i<=n;++i){
        c[i]=_();
        v[i]=_();
    }
    f1(1,0);
    for(int i=2;i<=n;++i)printf("%lld ",f[i]);
    return 0;
}
