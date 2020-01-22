#include<iostream>
#include<cstring>
#define maxn 105
using namespace std;
double max_p;
int t,n;
int m[maxn];
double dp[maxn*maxn];
double p[maxn];
double d_max(double x,double y){
	return x>y?x:y;
}
int main(){
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int sum=0;
		cin>>max_p>>n;
		max_p=1-max_p;
		for(int i=1;i<=n;i++){
			cin>>m[i]>>p[i];
			sum+=m[i];
			p[i]=1-p[i];//转换为赢的概率 
		}
		//银行钱数为背包容量，赢的概率为价值
		dp[0]=1;
        for(int i=1;i<=n;i++){
        	for(int j=sum;j>=m[i];j--){
        		dp[j]=d_max(dp[j],dp[j-m[i]]*p[i]);
			}
		}
		for(int i=sum;i>=0;i--){
			if(dp[i]>=max_p){
				cout<<i<<endl; 
			    break;
			} 
		}
	}
} 
