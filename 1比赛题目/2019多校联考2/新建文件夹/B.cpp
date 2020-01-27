#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<cmath> 
#include<map>
#define mod 1000000007
#define maxn 10000
using namespace std;
typedef long long ll;
int t,n,k;
map<int,int>id;
ll dp[maxn+5];
int tot=0;
int a[maxn+5],num[maxn+5];
void divide(int x){
	tot=0;
	id.clear();
	int sq=sqrt(x);
	for(int i=1;i<=sq;i++){
		if(x%i==0){
			num[++tot]=i;
			if(x/i!=i) num[++tot]=x/i;
		}
	}
	sort(num+1,num+1+tot);
	for(int i=1;i<=tot;i++){
		id[num[i]]=i; 
	} 
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		divide(k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[1]=1; 
		for(int i=1;i<=n;i++){
			if(k%a[i]!=0) continue;
			for(int j=tot;j>=1;j--){
				if(num[j]%a[i]==0){
					dp[j]+=dp[id[num[j]/a[i]]];
					dp[j]%=mod;
				}
			}
		}
		printf("%lld\n",dp[tot]);
	}
}

