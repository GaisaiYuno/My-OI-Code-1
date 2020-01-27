#include<bits/stdc++.h>
#define ll long long
using namespace std;
#ifndef Fading
inline char gc(){
    static char now[1<<16],*S,*T;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
#endif
#ifdef Fading
#define gc getchar
#endif
void exgcd(ll a,ll b,ll &x,ll &y){
    if (!b) return (void)(x=1,y=0);
    exgcd(b,a%b,x,y);
    ll tmp=x;x=y;y=tmp-a/b*y;
}
ll gcd(ll a,ll b){
    if (b==0) return a;
    return gcd(b,a%b); 
}
inline ll INV(ll a,ll p){
    ll x,y;
    exgcd(a,p,x,y);
    return (x+p)%p;
}
inline ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
inline ll mabs(ll x){
    return (x>0?x:-x);
}
inline ll fast_mul(ll a,ll b,ll p){
    ll t=0;a%=p;b%=p;
    while (b){
        if (b&1LL) t=(t+a)%p;
        b>>=1LL;a=(a+a)%p;
    }
    return t;
}
inline ll fast_pow(ll a,ll b,ll p){
    ll t=1;a%=p;
    while (b){
        if (b&1LL) t=(t*a)%p;
        b>>=1LL;a=(a*a)%p;
    }
    return t;
}
inline ll read(){
    ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)) {if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)) x=x*10+ch-'0',ch=gc();
    return x*f;
}
inline ll F(ll n,ll P,ll PK){
    if (n==0) return 1;
    ll rou=1;//ѭ����
    ll rem=1;//���� 
    for (ll i=1;i<=PK;i++){
        if (i%P) rou=rou*i%PK;
    }
    rou=fast_pow(rou,n/PK,PK);
    for (ll i=PK*(n/PK);i<=n;i++){
        if (i%P) rem=rem*(i%PK)%PK;
    }
    return F(n/P,P,PK)*rou%PK*rem%PK;
}
inline ll G(ll n,ll P){
    if (n<P) return 0;
    return G(n/P,P)+(n/P);
}
inline ll C_PK(ll n,ll m,ll P,ll PK){
    ll fz=F(n,P,PK),fm1=INV(F(m,P,PK),PK),fm2=INV(F(n-m,P,PK),PK);
    ll mi=fast_pow(P,G(n,P)-G(m,P)-G(n-m,P),PK);
    return fz*fm1%PK*fm2%PK*mi%PK;
}
ll A[1001],B[1001];
//x=B(mod A)
inline ll exLucas(ll n,ll m,ll P){
    ll ljc=P,tot=0;
    for (ll tmp=2;tmp*tmp<=P;tmp++){
        if (!(ljc%tmp)){
            ll PK=1;
            while (!(ljc%tmp)){
                PK*=tmp;ljc/=tmp;
            }
            if(PK==344293){
            	PK=344293;
			}
            A[++tot]=PK;B[tot]=C_PK(n,m,tmp,PK);
        }
    }
    if (ljc!=1){
        A[++tot]=ljc;B[tot]=C_PK(n,m,ljc,ljc);
    }
    ll ans=0;
    for (ll i=1;i<=tot;i++){
        ll M=P/A[i],T=INV(M,A[i]);
        ans=(ans+B[i]*M%P*T%P)%P;
    }
    return ans;
}
signed main(){
	ll n,m,P;
    scanf("%lld %lld %lld",&n,&m,&P);
    printf("%lld\n",exLucas(n,m,P));
    return 0;
}
