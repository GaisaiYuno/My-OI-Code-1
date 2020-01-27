#include<cstdio>
#define mo 1000000007
using namespace std;
int n,ans,last;
int jc[4000005],ny[4000005],a[2000005];
inline int read(){
    int ret=0,p=1;char c=getchar();
    while((c>'9')||(c<'0')){if(c=='-')p=-1;c=getchar();}
    while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
    return ret*p;
}
inline int c(int n,int m){
    if((m>n)||(m<0))return 0;
    else return 1LL*jc[n]*ny[m]%mo*ny[n-m]%mo;
}
inline int pow(int x,int k){
    int ans=1;
    for(;k;k>>=1,x=1LL*x*x%mo)if(k&1)ans=1LL*ans*x%mo;
    return ans;
}
int main(){
	#ifdef DEBUG
	freopen("3.in","r",stdin);
#endif
//    freopen("dfs.in","r",stdin);
//    freopen("dfs.out","w",stdout);
    n=read();jc[0]=1;
    for(int i=1;i<=2*n;i++)jc[i]=1LL*jc[i-1]*i%mo;
    ny[2*n]=pow(jc[2*n],mo-2);
    for(int i=2*n;i;i--)ny[i-1]=1LL*ny[i]*i%mo;
    for(int i=1;i<=n;i++)a[i]=read();
    if((a[1]!=0)&&(a[1]!=-1)){
        printf("0");
        return 0;
    }
    a[1]=0;last=1;a[n+1]=ans=1;
    for(int i=2;i<=n+1;i++)if(a[i]!=-1){
        if(a[i]==0){
            puts("0");
            return 0;
        }
        int s=i-last-1,x=i-last-1-a[i]+a[last]+1;
        if(x<0){
            puts("0");
            return 0;
        }
        ans=1LL*ans*(c(s+x,x)-c(s+x,x-a[last]-1))%mo;last=i;
    }
    if(ans<0)ans+=mo;
    printf("%d",ans);
}
