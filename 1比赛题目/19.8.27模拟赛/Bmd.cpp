#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime> 
#define maxn 100
#define maxl 100
using namespace std;
int cnt=0;
int prime[maxn+5];
bool vis[maxn+5];
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
		}  
	}
}

inline int random(int l,int r){
	return 1ll*rand()*rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	sieve(maxn);
	int p=prime[random(1,cnt)],l=random(1,maxl);
	printf("%d %d\n",p,l);
}
