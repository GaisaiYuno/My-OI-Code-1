#include<iostream>
#include<cstring>
#define maxn 1005
using namespace std;
int dp1[maxn],dp2[maxn],dp3[maxn];
int t,w;
int main(){
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>w;
		dp1[0]=1;
		dp2[0]=dp3[0]=0;
		dp1[1]=dp2[1]=dp3[1]=1; 
		for( int i=2; i<=w; i++ ){
			dp2[i]=dp2[i-1]+dp1[i-1];
			dp3[i]=dp1[i-1]+dp3[i-2];
			dp1[i]=dp1[i-1]+3*dp1[i-2]+dp3[i-1]+2*dp2[i-2];
		}
		printf("%d %d\n",k,dp1[w]);
	}
}
//dp1无突出 
//dp2一个突出 
//dp3两个突出 
