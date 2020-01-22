#include<iostream>
#include<cstring>
#define maxl 105
#define maxn 105
#define maxe 15  //��󴢴�����5*2+4=14 
#define INF 99999999
using namespace std;
int dp[maxn*maxl][maxe];
struct node{
	int a;
	int b;
}tim[maxn*maxl];
int l,n,ans;
void debug(){
	for(int i=1;i<=l*n;i++){
		for(int j=0;j<maxe;j++) cout<<dp[i][j]<<' ';
		cout<<endl;
	}
}
int main(){
	//freopen("out.txt","r",stdin);
	while(cin>>l>>n){
		for(int i=1;i<=l;i++) cin>>tim[i].a;
		for(int i=1;i<=l;i++) cin>>tim[i].b;
		tim[0]=tim[l];
		for(int i=l+1;i<=l*n;i++) tim[i]=tim[i%l];//��1Ȧ֮��Ķ�Ҳ��ֵ 
		memset(dp,0,sizeof(dp));
        for(int i=1;i<maxe;i++) dp[0][i]=INF;//ע��dp[0][0]��0 
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
		//debug();
	}
	return 0;
} 
