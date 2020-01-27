#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxlog 11
#define maxn 200005
using namespace std;
int a[maxn],len[maxn];
map<long long,int>cnt[maxlog];
int n,k;
long long pow10[maxn];
inline long long fast_pow(long long x,int p){
	long long ans=1;
	while(p){
		if(p&1) ans=ans*x%k;
		x=x*x%k;
		p>>=1;
	} 
	return ans;
}
inline int cal_len(int x){
	int ans=0; 
	while(x>0){
		ans++;
		x/=10;
	}
	return ans;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		len[i]=cal_len(a[i]);
		cnt[len[i]][(long long)a[i]%k]++;
	}
	pow10[0]=1;
	for(int i=1;i<=10;i++){
		pow10[i]=pow10[i-1]*10%k;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++){
			long long m1=(a[i]*pow10[j])%k;
			long long m2=(k-m1)%k;
			ans+=cnt[j][m2];
			if(len[i]==j&&(m1+a[i]%k)%k==0) ans--;
		} 
	}
	printf("%I64d\n",ans);
} 
