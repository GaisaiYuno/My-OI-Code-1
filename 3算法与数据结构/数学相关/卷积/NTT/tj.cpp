#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
 
using namespace std;
#define LL long long
#define G 3
#define Mod 1004535809LL
 
inline LL read(){
    LL x=0,f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
const LL MAXN = 100010;
const LL INF = 2147473600;
 
LL N,M,X,S; LL top,rev[MAXN+1];
LL s[MAXN+1],sta[MAXN+1];
LL a[MAXN+1];
 
inline LL Pow(LL A,LL B,LL P){
    LL res=1;
    while(B){
        if(B&1) res=res*A%P;
        A=A*A%P; B>>=1;
    } return res;
} 
inline LL GetN(LL x){
    LL y=x-1;
    for(LL i=2;y!=1;i++) {
        if(y%i==0) sta[++top]=i;
        while(y%i==0) y/=i;
    }
    for(LL i=2;;i++){
        bool flag=1;
        for(LL j=1;j<=top;j++)
            if(Pow(i,(x-1)/sta[j],x)==1) {flag=false; break;}
        if(flag) return i;
    }
}
LL a1[MAXN+1],b1[MAXN+1],c1[MAXN+1],b[MAXN+1],t[MAXN+1];
inline void NTT(LL *A,LL lim,LL type){
    for(LL i=0;i<lim;i++) if(rev[i]>i) swap(A[rev[i]],A[i]);
    for(LL mid=1;mid<lim;mid<<=1){
        LL Wn = Pow(G , type==1?(Mod-1)/(mid<<1):(Mod-1-(Mod-1)/(mid<<1)) , Mod)%Mod;//-
        for(LL R=mid<<1,j=0;j<lim;j+=R){
            LL w = 1;
            for(LL k=0;k<mid;k++){
                LL x=A[j+k] , y=w*A[j+k+mid]%Mod; //-
                A[j+k]=(x+y)%Mod; A[j+k+mid]=(x-y%Mod+Mod)%Mod;
                w=w*Wn%Mod;
            }
        }
    } if(type==1) return ; //reverse(A+1,A+lim); 
    LL INV=Pow(lim,Mod-2,Mod)%Mod;
    for(LL i=0;i<lim;i++) A[i]=A[i]*INV%Mod; return ;
}
LL lim=1;
inline void Mul(LL *A,LL *B,LL *C){
    for(LL i=0;i<M;i++) a1[i]=B[i],b1[i]=C[i];
    for(LL i=M;i<lim;i++) a1[i]=b1[i]=0;
    NTT(a1,lim,1); NTT(b1,lim,1);
    for(LL i=0;i<lim;i++) A[i]=a1[i]*b1[i]%Mod;
    NTT(A,lim,-1);
    for(LL i=lim-1;i>=M-1;i--){
        A[i%(M-1)]=(A[i%(M-1)]+A[i])%Mod; A[i]=0;
    } return ;
}
 
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    N=read(),M=read(),X=read(),S=read(); LL Now=1LL,T=GetN(M);
    for(LL i=0;i<M-1;i++) t[Now]=i,Now=Now*T%M;//cout<<Now<<" "<<T<<endl;
    for(LL i=1;i<=S;i++) {LL x=read()%Mod; if(x) a[t[x]]++; } lim=1; int l=0;
    while(lim<=2*(M-1)) lim<<=1,++l;
    for(LL i=0;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
    memset(b,0,sizeof(b)); b[0]=1;
    while(N){
        if(N&1) Mul(b,a,b);
        Mul(a,a,a); N>>=1;
    } printf("%lld\n",b[t[X]]%Mod);
    return 0;
}
