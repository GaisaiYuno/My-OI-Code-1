#include<iostream>
#include<cstdio>
using namespace std;
int t,a;
int cnt(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		long long t=cnt(a);
		printf("%I64d\n",(1ll<<t));
	} 
}
