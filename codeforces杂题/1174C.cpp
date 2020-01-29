#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n; 
int ans[maxn];

int vis[maxn];
int prime[maxn];
int cnt=0;
void sieve(int n){
	vis[0]=vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
			ans[i]=cnt;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			ans[i*prime[j]]=j;//记录的是能整除它的最小质数的编号j,不是cnt 
			if(i%prime[j]==0) break;
		}
	}
}

int main(){
	scanf("%d",&n);
	sieve(n);
	for(int i=2;i<=n;i++){
		printf("%d ",ans[i]);
	}	
}
