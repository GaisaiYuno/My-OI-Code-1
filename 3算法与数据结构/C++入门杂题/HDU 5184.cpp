#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#define maxn 1000000
#define mod 1000000007
using namespace std;
long long fact[maxn+5];
long long invfact[maxn+5];
long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		k>>=1;
	}
	return ans;
}
long long inv(int x){
	return fast_pow(x,mod-2);
}
void prework(){
	fact[0]=1;
	invfact[0]=1;
	for(int i=1;i<=maxn;i++){
		fact[i]=(fact[i-1]*i)%mod;
		invfact[i]=inv(fact[i]);
	}
}

long long C(int n,int m){
	return (fact[n]*invfact[n-m])%mod*invfact[m]%mod;
}

int n;
char s[maxn+5];
int main(){
	double t1=clock();
	prework();
	double t2=clock();
	printf("%.4fms\n",(t2-t1)/1000);
	while(scanf("%d",&n)!=EOF){
		getchar();
		scanf("%s",s);
		if(n%2){
			printf("0\n");
			continue;
		}
		long long m=n/2;
		int len=strlen(s);
		long long l=0,r=0;
		long long p=0,q=0;
		for(int i=0;i<len;i++){
			if(s[i]=='(') l++;
			else if(s[i]==')') r++;
			if(l<r) break;
		}
		if(l<r||l>m){
			printf("0\n");
			continue;
		}
		p=m-l;
		q=m-r;
		if(q<0||p<0){
			printf("0\n");
			continue;
		}
		long long ans=(C(p+q,q)-C(p+q,q+1)+mod)%mod;
		printf("%I64d\n",ans);
	}
}
