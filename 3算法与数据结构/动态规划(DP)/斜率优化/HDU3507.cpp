#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500000
using namespace std;
int n,m;
long long a[maxn+5];
long long s[maxn+5]; 
long long dp[maxn+5];
int q[maxn+5];
int head,tail;
inline long long get_up(int j,int k){
    return dp[j]-dp[k]+s[j]*s[j]-s[k]*s[k];
}
inline long long get_down(int j,int k){
    return s[j]-s[k];
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        memset(dp,0x3f,sizeof(dp));    
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            s[i]=s[i-1]+a[i];
        }
        dp[0]=0;
        head=tail=1;
        q[head]=0;
        for(int i=1;i<=n;i++){
            while(head<tail&& get_up(q[head+1],q[head])<=2*s[i] * get_down(q[head+1],q[head]) ) head++;
            dp[i]=dp[q[head]] + (s[i]-s[q[head]])*(s[i]-s[q[head]]) + m;
            while(head<tail&& get_up(q[tail],q[tail-1])*get_down(i,q[tail])>=get_up(i,q[tail])*get_down(q[tail],q[tail-1]) ) tail--;
            q[++tail]=i;
        }
        printf("%lld\n",dp[n]);
    }
}
