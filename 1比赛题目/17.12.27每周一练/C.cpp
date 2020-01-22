#include<iostream>
#include<cstring>
#define maxl 105
#define maxn 105
#define maxe 15  //��󴢴�����5*2+4=14 
#define INF 0xfffffff
using namespace std;
int dp[maxn*maxl][maxe];
struct node{
	int a;
	int b;
}tim[maxl];
int l,n,ans;
int main(){
	while(cin>>l>>n){
		for(int i=1;i<=l;i++) cin>>tim[i].a;
		for(int i=1;i<=l;i++) cin>>tim[i].b;
		tim[0]=tim[l];
		for(int i=l+1;i<=l*n;i++){//��1Ȧ֮��Ķ�Ҳ��ֵ 
			tim[i].a=tim[i%l].a;
			tim[i].b=tim[i%l].b;
		}
		memset(dp,0,sizeof(dp));
        for(int i=0;i<maxe;i++) dp[0][i]=INF;
		for(int i=1;i<=l*n;i++){
			for(int j=0;j<maxe;j++){
			    if(j==0) dp[i][j]=dp[i-1][5]+tim[i].b;
			    else if(j<10) dp[i][j]=min(dp[i-1][j-1]+tim[i].a,dp[i-1][j+5]+tim[i].b);
			    else if(j==10) dp[i][j]=min(dp[i-1][j-1]+tim[i].a,dp[i-1][14]+tim[i].a);
			    else if(j>10) dp[i][j]=dp[i-1][j-1]+tim[i].a;
		    }
		} 
		ans=INF;
		for(int i=0;i<maxe;i++){
			ans=min(ans,dp[l*n][i]);
		}
		cout<<ans<<endl; 
	}
	return 0;
} 
