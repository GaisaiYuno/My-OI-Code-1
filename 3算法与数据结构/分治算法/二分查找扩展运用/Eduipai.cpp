#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int INF=0x3f3f3f3f;  
int n,X,Y,a[55],b[55],dp[205][205];             //dp[i][j]表示前i个人  
int judge(int mid){                             //做j件A还能做几件B  
    int i,j,k;  
    memset(dp,-1,sizeof(dp));  
    for(i=0;i<=X&&a[1]*i<=mid;i++)              //一定要判断总时间不能大于mid  
    dp[1][i]=(mid-i*a[1])/b[1];  
    for(i=2;i<=n;i++){  
        for(j=0;j<=X;j++){  
            for(k=0;k<=j&&k*a[i]<=mid;k++){     //相当于每个人都有mid的时间，也就是  
                if(dp[i-1][j-k]!=-1)            //i个人其实是并行的  
                dp[i][j]=max(dp[i][j],dp[i-1][j-k]+(mid-k*a[i])/b[i]);  
            }  
        }  
    }  
    if(dp[n][X]>=Y)  
    return 1;  
    return 0;  
}  
int main(){  
    int i,t,l,r,mid,ans,cas;  
    scanf("%d",&t);  
    for(cas=1;cas<=t;cas++){  
        scanf("%d%d%d",&n,&X,&Y);  
        for(i=1;i<=n;i++)  
        scanf("%d%d",&a[i],&b[i]);  
        l=0,r=INF;                              //二分找出可行解  
        while(l<=r){  
            mid=(l+r)>>1;  
            if(judge(mid)){  
                ans=mid;  
                r=mid-1;  
            }  
            else  
            l=mid+1;  
        }  
        printf("Case %d: %d\n",cas,ans);  
    }  
    return 0;  
}  
