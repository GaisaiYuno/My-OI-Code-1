#include<iostream>
#include<cstdio>
using namespace std;
inline long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
long long n,m,k;
int main(){
	cin>>n>>m>>k;
	if((n*m*2)%k!=0){
		printf("NO\n");
	}else{
		printf("YES\n");
		long long S=(n*m*2)/k;
		long long a,b;
		if(gcd(n*2,k)!=1){
			a=n*2/gcd(n*2,k);
			b=S/a;
		}else{
			a=n;
			b=m*2/k;
		} 
		printf("0 0\n");
		printf("%I64d 0\n",a);
		printf("%I64d %I64d\n",a,b);
	}
} 
