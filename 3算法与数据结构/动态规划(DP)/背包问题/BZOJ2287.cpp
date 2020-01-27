#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000
#define maxv 2000
#define mod 10 
using namespace std;
int n,m;
int f[maxv+5];
int w[maxn+5];
int cnt[maxn+5][maxv+5]; 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){
			f[j]+=f[j-w[i]];
			f[j]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		cnt[i][0]=1;
		for(int j=1;j<=m;j++){
			if(j<w[i]) cnt[i][j]=f[j];
			else cnt[i][j]=(f[j]-cnt[i][j-w[i]]+mod)%mod;//总方案数-用剩下物品填满j-w[i](第i个物品填满w[i])的方案数
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d",cnt[i][j]);
		}
		printf("\n"); 
	} 
}

