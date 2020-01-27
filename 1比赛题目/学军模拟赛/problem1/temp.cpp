#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
ll fact[maxn+5];
void ini(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
}
ll dp[maxn+5];

void print_seq(int n){
	if(n%100>10&&n%100<=20){
		printf("%dth",n);
	}else{
		if(n%10==1) printf("%dst",n);
		else if(n%10==2) printf("%dnd",n);
		else if(n%10==3) printf("%drd",n);
		else printf("%dth",n);
	}
	
}
int main(){
	scanf("%d",&n);
	ini(n);
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=(dp[i]+dp[i-1]*(i-i/2)%mod)%mod;
		dp[i]=(dp[i]+(fact[i-1]-dp[i-1]+mod)%mod*(i/2)%mod)%mod;
	}
	printf("The ");
	print_seq(n);
	printf(" answer is %lld.",dp[n]);
}
