#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int v[maxn];
int phi[maxn];
int prime[maxn];
int cnt=0;
void euler(int n){
	memset(v,0,sizeof(v));
	cnt=0;
	for(int i=2;i<=n;i++){
		if(!v[i]){
			v[i]=i;
			prime[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt;j++){
			if(prime[j]>v[i]||i*prime[j]>n) break;
			v[i*prime[j]]=prime[j];
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];//µÈ¼ÛÓÚprime[j]^2|i*prime[j] 
			}else  phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int c,n,ans;
int main(){
	scanf("%d",&c);
	for(int i=1;i<=c;i++){
		scanf("%d",&n);
		ans=0;
		euler(n);
		for(int j=1;j<=n;j++){
			ans+=phi[j]; 
		}
		ans*=2;
		ans+=3;
		printf("%d %d %d\n",i,n,ans);
	}
}
