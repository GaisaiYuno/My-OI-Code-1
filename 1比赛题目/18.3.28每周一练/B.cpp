#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 30
using namespace std;
long long dp[maxn+5];
int main(){
	dp[0]=1;
	dp[1]=0;
	dp[2]=3;
	for(int i=3;i<=maxn;i++){
		 if(i%2==1) dp[i]=0; 
		 else dp[i]=dp[i-2]*4-dp[i-4]; 
	} 
	int x;
	while(scanf("%d",&x)!=EOF){
		if(x==-1) break;
		else printf("%lld\n",dp[x]); 
	}
	//for(int i=3;i<=maxn;i++) printf("%d\n",dp[i]); 
}
/*
���Ϊ2,���������߷ָ�ľ�����3��
��ȴ���2�����������߷ָ�ľ�����2��
dp[i]=3*dp[i-2]+2*(dp[i-4]+dp[i-6]+����dp[0])
dp[i-2]=3*dp[i-4]+2*(dp[i-6]+����dp[0])
�����dp[i]=4*dp[i-2]-dp[i-4] 
*/
