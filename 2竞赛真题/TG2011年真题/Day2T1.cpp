#include<iostream>
#include<cstdio>
#define mod 10007
using namespace std;
typedef long long ll;
inline int qread(){
    int x=0,sign=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*sign;
}
inline ll fast_pow(ll x,ll k){
    ll ans=1;
    while(k>0){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return ans%mod;
}
inline ll inv(ll x){
    return fast_pow(x,mod-2);
}
inline ll fact(ll x){
    ll ans=1;
    for(int i=2;i<=x;i++) ans=ans*i%mod;
    return ans;
}
inline ll C(ll n,ll m){
    return fact(n)*inv(fact(n-m))%mod*inv(fact(m))%mod;
}
int main(){
//	freopen("factor.in","r",stdin);
//	freopen("factor.out","w",stdout);
    int a,b,k,n,m;
    a=qread();
    b=qread();
    k=qread();
    n=qread();
    m=qread();
    ll ans=0;
    ans=fast_pow(a,n)*fast_pow(b,m)%mod;
    ans=ans*C(k,n)%mod;
    cout<<ans%mod;
}
