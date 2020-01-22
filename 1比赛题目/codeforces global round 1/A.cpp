#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1)ans=ans*x%2;
		x=x*x%2;
		k>>=1;
	} 
	return ans;
} 
int main(){
	int x;
	long long ans=0;
	scanf("%d %d",&k,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		ans+=x*fast_pow(k,n-i)%2;
		ans%=2;
	}
	if(ans==0) printf("even");
	else printf("odd"); 
}

