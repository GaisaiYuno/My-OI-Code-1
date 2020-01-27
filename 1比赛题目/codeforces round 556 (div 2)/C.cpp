#include<iostream>
#include<cstdio>
#define maxn 400005
using namespace std;
int n;
int cp;
int vis[maxn];
int prime[maxn];
void sieve(int n){
	vis[0]=vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cp]=i; 
		}
		for(int j=1;j<=cp&&1ll*i*prime[j]<=1ll*n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}

int cnt1,cnt2;
int main(){
	int x;
	scanf("%d",&n);
	sieve(n*2);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x==1) cnt1++;
		else cnt2++;
	}
	int sum=0;
	while(cnt1&&cnt2){
		if(!vis[sum+1]){
			printf("1 ");
			cnt1--;
			sum++;
		}else{
			printf("2 ");
			cnt2--;
			sum+=2;
		}
	}
	for(int i=1;i<=cnt1;i++) printf("1 ");
	for(int i=1;i<=cnt2;i++) printf("2 ");
}

