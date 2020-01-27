#include<iostream>
#include<cstdio>
#define maxv 200100 
#define mod 1000000007
using namespace std;
int a,b,k,t;
struct arr{
	long long a[maxv*4+5];
	inline long long& operator [] (const int index){
		return a[index+maxv*2];
	}
};
arr dp1[2],dp2[2]; 
arr sum1[2],sum2[2];
int main(){
	int now1,now2;
	scanf("%d %d %d %d",&a,&b,&k,&t);
	dp1[0][a]=1;
	for(int j=-maxv;j<=maxv;j++) sum1[0][j]=(sum1[0][j-1]+dp1[0][j])%mod;
	now1=0;
	for(int i=1;i<=t;i++){
		now1^=1;
		for(int j=-maxv;j<=maxv;j++){
			dp1[now1][j]=sum1[now1^1][j+k]-sum1[now1^1][j-k-1];
			dp1[now1][j]=(dp1[now1][j]+mod)%mod;
		}
		sum1[now1][-maxv-1]=0;
		for(int j=-maxv;j<=maxv;j++){
			sum1[now1][j]=sum1[now1][j-1]+dp1[now1][j];
			sum1[now1][j]%=mod;
		}
	}
	
	dp2[0][b]=1;
	for(int j=-maxv;j<=maxv;j++) sum2[0][j]=(sum2[0][j-1]+dp2[0][j])%mod;
	now2=0;
	for(int i=1;i<=t;i++){
		now2^=1;
		for(int j=-maxv;j<=maxv;j++){
			dp2[now2][j]=sum2[now2^1][j+k]-sum2[now2^1][j-k-1];
			dp2[now2][j]=(dp2[now2][j]+mod)%mod;
		}
		sum2[now2][-maxv-1]=0;
		for(int j=-maxv;j<=maxv;j++){
			sum2[now2][j]=sum2[now2][j-1]+dp2[now2][j];
			sum2[now2][j]%=mod;
		}
	}
	
	long long ans=0;
	for(int i=-k*t+a;i<=k*t+a;i++){
		ans+=dp1[now1][i]*sum2[now2][i-1]%mod;
		ans%=mod;
	}
	printf("%I64d\n",ans);
}

