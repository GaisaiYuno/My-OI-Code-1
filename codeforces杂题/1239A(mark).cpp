#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,m; 
ll f[maxn+5];
int main(){
	scanf("%d %d",&n,&m);
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=max(n,m);i++) f[i]=(f[i-1]+f[i-2])%mod;
	printf("%I64d\n",(f[n]*2+f[m]*2-2+mod)%mod); 
}

