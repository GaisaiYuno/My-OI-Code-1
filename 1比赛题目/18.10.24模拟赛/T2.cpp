//luogu 3147
#include<iostream>
#include<cstdio>
#define maxn 300005
#define maxv 60
using namespace std;
int a[maxn];
int dp[maxn][maxv];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); 
    }
    for(int i=1;i<=n;i++){
        dp[i][a[i]]=i+1; 
    } 
    int ans=0;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=58;j++){
            if(!dp[i][j]){
                if(dp[i][j-1]) dp[i][j]=dp[dp[i][j-1]][j-1];
                else dp[i][j]=0; 
                if(dp[i][j]) ans=max(ans,j); 
            }
        }
    }
    printf("%d\n",ans);
} 
