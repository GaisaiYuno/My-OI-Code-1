
/*
Ҫʹ������ܱ�5��������ɾ������ַ�ĩβ����һ����5��0����ʱֻ��ö��a�ĸ�λ�ַ�����������ַ�0��5�ͼ��㵱ǰ������ܸ�����2^i��
��������ĳ���Ϊlk��������ͬλ�õĽ���ܸ����ֱ�2^(i+l)��,��2^(i+l*2)��...,��2^(i+l*(k-1)����
   �ɵȱ�������͹�ʽans=2^i*(2^lk-1)/(2^l-1)
   Ϊ���� (2^lk-1)/(2^l-1)%mod��ֵҪ�õ���Ԫ
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
	ab��1(mod p)
	a^(p-1)��1(mod p)��p�������� ������С����
	��Ԫb����a^(p-2)
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
