#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define maxm 100005
#define mod 998244353
using namespace std;
int n,m,k;
inline __int128 fast_pow(__int128 x,__int128 k){
	__int128 ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
inline  inv(__int128 x){
//	printf("%d %d %d\n",x,mod-2,fast_pow(x,mod-2));
	return fast_pow(x,mod-2)%mod;
}
__int128 fact[maxn+maxm];
__int128 invfact[maxn+maxm];
inline __int128 C(int n,int m){
	if(n<m) return 0;
	if(n==m||m==0) return 1;
	return fact[n]*invfact[n-m]*invfact[m];
}
int vis[maxn];
int prime[maxn];
int cnt_prime=0;
void sieve(int n){
	vis[0]=1;
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt_prime]=i;
			for(int j=i;j<=n/i;j++){
//				printf("%lld\n",j);
				vis[i*j]=1;
			}
		}
	}
}
void change(__int128 v, char* s)
{
    char temp;
    int i=0, j;

    while(v >0) {
        s[i++] = v % 10 + '0';
        v /= 10;
    }
    s[i] = '\0';

    j=0;
    i--;
    while(j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j++;
        i--;
    }
}
char anss[100];
int main(){
	scanf("%d %d %d",&n,&m,&k);
	fact[0]=1;
	for(int i=1;i<=n+m;i++){
		fact[i]=fact[i-1]*i;
		invfact[i]=inv(fact[i]);
	}
	sieve(k);
	__int128 ans;
	int p;
	for(int i=0;i<=m;i++){
		ans=0;
//		for(int j=cnt_prime;j>=1;j--){
//			p=prime[j];
//			if(p<k-i) break;
//			ans+=C(n,p)*C(i,k-p)%mod;
//			ans%=mod;
//		}
		for(int j=1;j<=cnt_prime;j++){
			int p=prime[j];
			if(p<k-i) continue;
			ans+=C(n,p)*C(i,k-p);
		}
		ans=ans*inv(C(n+i,k));
		ans=ans%mod;
//		if(ans!=0) printf("sdf");
		change(ans,anss);
		printf("%d\n",ans);
//		printf("%s\n",anss);
	}
}


