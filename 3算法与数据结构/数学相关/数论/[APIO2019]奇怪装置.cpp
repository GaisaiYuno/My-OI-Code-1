#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 1000000
#define maxr 2e18
using namespace std;
typedef long long ll;
ll n,A,B;
inline ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
 
struct seg{
    ll l;
    ll r;
    seg(){
        
    }
    seg(ll _l,ll _r){
        l=_l;
        r=_r;
    }
    friend bool operator < (seg p,seg q){
        if(p.l==q.l) return p.r<q.r;
        else return p.l<q.l; 
    }
}a[maxn+5],b[maxn*2+5];
int cnt=0;
int main(){
    scanf("%I64d %I64d %I64d",&n,&A,&B);
    for(int i=1;i<=n;i++){
        scanf("%I64d %I64d",&a[i].l,&a[i].r);
    }
    ll C=A/gcd(A,B+1);
    if(maxr/B<=C) C=maxr; //B*C<=2e18 
    else C=C*B;
    for(int i=1;i<=n;i++){
        if(a[i].r-a[i].l>=C){
            printf("%I64d\n",C);
            return 0;
        }
        if(a[i].l%C<=a[i].r%C){
            b[++cnt]=seg(a[i].l%C,a[i].r%C);    
        }else{
            b[++cnt]=seg(0,a[i].r%C);
            b[++cnt]=seg(a[i].l%C,C-1);
        } 
    }
    sort(b+1,b+1+cnt);
//  cnt=unique(b+1,b+1+cnt)-b-1;
    ll l=b[1].l,r=b[1].r;
    ll ans=0;
    for(int i=2;i<=cnt;i++){
        if(b[i].l>r+1){
            ans+=(r-l+1);
            l=b[i].l;
            r=b[i].r;
        }else if(b[i].r>r){
            r=b[i].r;
        }
    } 
    ans+=r-l+1;
    printf("%I64d\n",ans);
} 
