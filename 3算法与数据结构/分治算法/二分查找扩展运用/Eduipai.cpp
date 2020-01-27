#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int INF=0x3f3f3f3f;  
int n,X,Y,a[55],b[55],dp[205][205];             //dp[i][j]��ʾǰi����  
int judge(int mid){                             //��j��A����������B  
    int i,j,k;  
    memset(dp,-1,sizeof(dp));  
    for(i=0;i<=X&&a[1]*i<=mid;i++)              //һ��Ҫ�ж���ʱ�䲻�ܴ���mid  
    dp[1][i]=(mid-i*a[1])/b[1];  
    for(i=2;i<=n;i++){  
        for(j=0;j<=X;j++){  
            for(k=0;k<=j&&k*a[i]<=mid;k++){     //�൱��ÿ���˶���mid��ʱ�䣬Ҳ����  
                if(dp[i-1][j-k]!=-1)            //i������ʵ�ǲ��е�  
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
        l=0,r=INF;                              //�����ҳ����н�  
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
