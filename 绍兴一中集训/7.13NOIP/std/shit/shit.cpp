#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int P=1000000007;
const int N=305;
inline int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
    return c;
}
int fac[N],inv[N];
int C(int a,int b){
    if(a<b)return 0;
    return (fac[a]*1ll*inv[b]%P)*1ll*inv[a-b]%P;
}
int t[N];
int n,k;
int ans=0;
int rk[N];
int f[N][N][N];
void init(){
    rep(a,0,n-2)rep(c,0,n){
        int res=0;
        per(i,min(a,c-1),0){
            res=(res+C(a,i)*1ll*C(n-2-a,c-1-i))%P;
            f[a][i][c]=res;
        }
    }
}
int before(int x,int y){
    if(rk[x]>rk[y])return (fac[n]+P-before(y,x))%P;

    //POS[x] before POS[y]
    int ans=C(n,2)*1ll*fac[n-2]%P;
    rep(i,1,n){
        if(i<=k)ans=(ans+(i-1)*1ll*fac[n-2])%P;
        else{
            int dj=i-k;
            //y在前i-1个里不是前dj小的
            if(rk[y]-1<=dj)break;
            int a=rk[y]-2;
            int b=dj;
            int c=i-1;
            ans=(ans+(f[a][b][c]*1ll*fac[n-i]%P)*1ll*fac[i-1])%P;
        }
    }
    return ans;
}
int main(){
	freopen("shit.in","r",stdin);
	freopen("shit.out","w",stdout); 
    scanf("%d%d",&n,&k);
    fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
    inv[n]=Pow(fac[n],P-2);per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
    init();
    rep(i,1,n){
        scanf("%d",&t[i]);
        ans=(ans+t[i]*1ll*fac[n])%P;
    }
    rep(i,1,n)rep(j,1,n)if(pii(t[j],j)<=pii(t[i],i))rk[i]++;
    rep(i,1,n)rep(j,1,n)if(j^i){
        ans=(ans+t[j]*1ll*before(j,i))%P;
    }
    printf("%d\n",ans);
    return 0;
}
