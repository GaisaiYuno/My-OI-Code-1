#include <stdio.h>  
#include <string.h>    
#include <iostream>    
#include <algorithm>   
using namespace std;  
typedef long long ll;  
const ll INF=0x3f3f3f3f;  
  
ll dp[1200];  
ll v[1200],w[1200];  
bool path[1100][1100];  
int a[1005][120];  
int check(int ii,int jj)//字典序比较函数   
{  
    int t1=a[ii][0];  
    int t2=a[jj][0];  
    for(int i=1,j=1;i<=t1&&j<=t2;i++,j++)  
    {  
        if(a[ii][i]!=a[jj][j])  
            return a[ii][i]-a[jj][j];  
   }  
   return 0;  
}  
int main()  
{  
    ll T,B,N;  
    int rrr=1;  
    cin>>T;  
   while(T--)  
    {  
        scanf("%lld %lld",&B,&N);  
       memset(path,0,sizeof(path));  
       memset(dp,0,sizeof(dp));  
       for(int i=1;i<=N;i++)  
        {  
            ll val,wei;  
            scanf("%lld %lld",&val,&wei);  
            v[i]=val;  
           w[i]=wei;  
           for(int j=B;j>=wei;j--){  
                if(dp[j]<dp[j-wei]+val){  
                    dp[j]=dp[j-wei]+val;  
                    path[i][j]=1;//j包顶i  
                }  
            }  
        }  
        ll maxv=0;  
        for(int j=0;j<=B;j++)  
            maxv=max(maxv,dp[j]);//最高得分  
          
        ll dexsum=INF;  
        int k=0,mark=0;  
        for(int jj=B;jj>=0;jj--)  
       {  
            if(dp[jj]==maxv)  
            {  
                ll sum=0;//序号和  
                int top=1;  
                int i=N,j=jj;  
                while(i>=1&&j>=0)  
                {    
                    if(path[i][j])//物品i在j里  
                   {  
                       a[k][top++]=i;  
                       sum+=i;  
                        j-=w[i];  //读完了物品i，找下一个背包状态     
                    }    
                    i--;     
               }  
               a[k][0]=top-1;//个数  
              sort(a[k]+1,a[k]+1+a[k][0]);  
               if(dexsum>sum){  
                    dexsum=sum;  
                   mark=k;//第k组  
               }  
               else if(dexsum==sum&&check(k,mark)<0){  
                   dexsum=sum;  
                    mark=k;//第k组  
               }  
                k++;  
            }  
        }  
         
          
        ll val=0,cost=0;  
        int top=a[mark][0];  
        sort(a[mark]+1,a[mark]+1+a[mark][0]);  
        for(int i=1;i<=top;i++)  
        {  
            val+=v[a[mark][i]];  
            cost+=w[a[mark][i]];  
        }  
        printf("Case #%d:\n",rrr++);  
        printf("%lld %lld\n",val,cost);  
        for(int i=1;i<top;i++)  
            printf("%d ",a[mark][i]);  
        if(top>=1)  
            printf("%d\n",a[mark][top]);  
    }  
}


