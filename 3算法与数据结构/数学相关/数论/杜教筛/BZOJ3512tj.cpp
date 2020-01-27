//https://www.cnblogs.com/owenyu/p/7349860.html
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int gi(){
    int x=0,w=1;char ch=getchar();
    while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if (ch=='-') w=0,ch=getchar();
    while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return w?x:-x;
}
const int N = 2e6+5;
const int mod = 1e9+7;
int zhi[N],pri[N],tot,phi[N],low[N],sum[N],ans;
map<int,int>M[N],P;
int S(int n){
    if (n<N) return sum[n];
    if (P[n]) return P[n];
    int res=0;
    for (int i=2,j;i<=n;i=j+1)
        j=n/(n/i),res=(res+1ll*(j-i+1)*S(n/i))%mod;
    return P[n]=((1ll*n*(n+1)>>1)-res+mod)%mod;
}
int S(int n,int m){
    if (m==0) return 0;
    if (n==1) return S(m);
    if (M[n][m]) return M[n][m];
    int res=0;
    for (int i=1;i*i<=n;++i)
        if (n%i==0){
            res=(res+1ll*phi[n/i]*S(i,m/i))%mod;
            if (i*i<n) res=(res+1ll*phi[i]*S(n/i,m/(n/i)))%mod;
        }
    return M[n][m]=res;
}
int main(){
    int n=gi(),m=gi();phi[1]=low[1]=1;
    for (int i=2;i<N;++i){
        if (!zhi[i]) pri[++tot]=i,phi[i]=i-1,low[i]=i;
        for (int j=1;i*pri[j]<N;++j){
            zhi[i*pri[j]]=1;
            if (i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                low[i*pri[j]]=low[i];
                break;
            }
            phi[i*pri[j]]=phi[i]*(pri[j]-1);
            low[i*pri[j]]=low[i]*pri[j];
        }
    }
    for (int i=1;i<N;++i) sum[i]=(sum[i-1]+phi[i])%mod;
    for (int i=1;i<=n;++i) ans=(ans+1ll*(i/low[i])*S(low[i],m))%mod;
    printf("%d\n",ans);return 0;
}
