
/*
要使这个数能被5整除，则删除后的字符末尾数字一定是5或0，这时只用枚举a的各位字符，如果遇到字符0或5就计算当前情况的总个数（2^i）
，而后面的长度为lk个串的相同位置的结果总个数分别（2^(i+l)）,（2^(i+l*2)）...,（2^(i+l*(k-1)），
   由等比数列求和公式ans=2^i*(2^lk-1)/(2^l-1)
   为了求 (2^lk-1)/(2^l-1)%mod的值要用到逆元
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
long long mod=1000000007;
long long fast_pow(long long x,long long k) {
	long long ans=x;
	if(k==0) {
		return 1;
	}
	k--;
	while(k>0) {
		if(k%2==1) {
			ans=(ans%mod*x)%mod;
		}
		x=(x%mod*x)%mod;
		k/=2;
	}
	return ans%mod;
}
long long inv(long long x,long long p) {
	return fast_pow(x,p-2)%mod;
	/*
	ab≡1(mod p)
	a^(p-1)≡1(mod p)【p是素数】 【费马小定理】
	逆元b就是a^(p-2)
	*/
}
char s[maxn];
int k;
int main() {
	scanf("%s",s);
	scanf("%d",&k);
	int l=strlen(s);
	long long ans=0;
	long long x=0,y=0;
	for(int i=0; i<l; i++) {
		if(s[i]=='0'||s[i]=='5') {
			ans+=fast_pow(2,i);
			ans%=mod;
		}
	}

	x=fast_pow(2,l);
	y=fast_pow(x,k);
	x=x-1;
//	x%=mod;
	y=y-1;
//	y%=mod;

	printf("%I64d\n",(ans*(y*inv(x,mod)%mod)%mod)%mod);
}
