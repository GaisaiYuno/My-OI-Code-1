#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<queue>
#define maxn 1005
using namespace std;
long long n;
int k;

int cnt=0;
int vis[maxn];
int prime[maxn];
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}

priority_queue<long long>q;
int main(){
	scanf("%lld %d",&n,&k);
	sieve(128);
	for(int i=1;i<=cnt;i++){
		for(long long x=prime[i];x<=n;x*=prime[i]){
			q.push(x);
		}
	}
	for(int p=1;p<=k-1;p++){
		long long x=q.top();
		while(!q.empty()&&x==q.top()) q.pop();
		//判重，如果有重复的数，只算一个 
		//如果不判重的话相同的数会被算成两个不同的排名 
		long long y;
		for(int i=1;i<=cnt;i++){
			if(x%prime[i]==0){
				y=x/prime[i]*prime[i-1];
				q.push(y);
			}
		}
	}
	printf("%lld\n",q.top());
}
