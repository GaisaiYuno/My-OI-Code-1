//洛谷 借教室 
#include<iostream>
#include<cstring>
#define maxn 1000005
using namespace std;
int n,m;
int r[maxn];
int d[maxn],s[maxn],t[maxn];
int diff[maxn] ;

bool judge(int b){
    
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=b;i++) 
    {
    	 diff[s[i]]+=d[i];
         diff[t[i]+1]-=d[i];
    }
      
    int now=0;
    for(int i=1;i<=n;i++){
        now+=diff[i];
        if(now>r[i])return 0;
    }
    return 1;
}
int main(){
    int left,right,ans=0,mid;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int j=1;j<=m;j++) cin>>d[j]>>s[j]>>t[j];
    left=1;
    right=m;  //订单总数 
    while(left<=right){
        mid=(left+right)/2;
        if(judge(mid)==0){  //订单无法满足
        
            right=mid-1;
        }
        else{
             left=mid+1;
             ans=mid;
        }
        
    }
    if(ans<m)cout<<"-1"<<endl<<ans+1;   //二分出最后一个不超限的订单为mid， 所以mid+1为需要修改订单 
    else cout<<0;
    return 0;
}

