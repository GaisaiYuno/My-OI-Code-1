#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b); 
}
int divide(int x){
	int sq=sqrt(x);
	int ans=1;
	for(int i=2;i<=sq;i++){
		if(x%i==0){
			ans=max(ans,i);
			ans=max(ans,x/i);
		}
	}
	return ans;
} 

int count(int x){
	int ans=0;
	while(x>0){
		x>>=1;
		ans++;
	}
	return ans;
} 

int solve(int x){
	int l=count(x);
	if((1<<l)-1==x) return divide(x);
	else return (1<<l)-1; 
}

int main(){
	int q,x;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		printf("%d\n",solve(x));
	}
}

