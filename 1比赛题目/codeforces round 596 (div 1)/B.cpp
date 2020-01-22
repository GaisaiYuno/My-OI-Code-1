#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
typedef long long ll;
ll n,p;
ll f[100]; 
int main(){
	scanf("%I64d %I64d",&n,&p);
	for(int i=1;i<=1000000;i++){
		ll x=n-p*i;
		if(x>=i){
			x-=i;
			int cnt=0;
			for(int j=31;j>=1;j--){
				while(((1<<j)-1)<=x){
					cnt++;
					x-=(1<<j)-1;
				}
			}
			if(cnt<=i){
				printf("%d\n",i);
				return 0;
			}
		}
	} 
	printf("-1\n");
}

