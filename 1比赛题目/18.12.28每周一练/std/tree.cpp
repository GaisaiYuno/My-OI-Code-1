#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1001];
int S,L;
double dp[1001][2001],p,tmp0[2001],tmp1[2001],sum[2][2001];
void dfs(int x,int f){
    for(int i=0;i<=S;i++)dp[x][i]=tmp0[i]=tmp1[i]=0;
    dp[x][0]=1;
    for(int i=0;i<edge[x].size();i++){
        int y=edge[x][i];
        if(y==f)continue;
        dfs(y,x);
        for(int i=0;i<=S;i++)tmp0[i]=tmp1[i]=0;
        for(int j=0;j<=L;j++)
            for(int k=0;k+j<=S;k++)
                tmp0[j+k]+=p*dp[y][k];
        sum[0][0]=dp[x][0];
        sum[1][0]=tmp0[0];
        for(int j=1;j<=S;j++){
            sum[0][j]=sum[0][j-1]+dp[x][j];
            sum[1][j]=sum[1][j-1]+tmp0[j];
        }
        for(int j=0;j<=S;j++){//j较大 
            int k=min(j,S-j);
            tmp1[j]+=dp[x][j]*sum[1][k]; 
        }
        for(int k=0;k<=S;k++){//k较大 
            int j=min(k,S-k);
            tmp1[k]+=sum[0][j]*tmp0[k]; 
        }
        for(int j=0;j<=S;j++){
            if(2*j<=S)tmp1[j]-=dp[x][j]*tmp0[j];
        }
        /*
        for(int j=0;j<=S;j++)
            for(int k=0;k+j<=S;k++)
                tmp1[max(j,k)]+=dp[x][j]*tmp0[k];*/
        for(int j=0;j<=S;j++)dp[x][j]=tmp1[j];
    } 
} 
double solve(){
    int n,a,b;
    cin>>n>>L>>S;p=1.0/(L+1); 
    for(int i=1;i<=n;i++)edge[i].clear();
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1,0);
    double ans=0;
    for(int i=0;i<=S;i++)ans+=dp[1][i]; 
    return ans;
}
int main(){ 
        printf("%f\n",solve());  
    return 0;
}
