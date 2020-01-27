#include<iostream>
#include<cstdio>
#define maxn 2005
#define mod 1000000007 
using namespace std;
int n,m;
int a[maxn];
long long C[maxn][maxn];

void ini(){
	for(int i=0;i<=2000;i++) C[i][0]=C[i][i]=1;
    for(int i=1;i<=2000;i++){ 
        for(int j=1;j<i;j++){ 
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	ini();
	long long ans=1;
	for(int i=1;i<=m;i++) ans=ans*C[a[i]+n-1][n-1]%mod;
	for(int i=1;i<=n;i++){
		long long sum=1;
		for(int j=1;j<=m;j++){
			sum=sum*C[a[j]+n-i-1][n-i-1]%mod;
		}
		sum=sum*C[n][i]%mod;
		if(i%2==1) ans=(ans-sum+mod)%mod;
		else ans=(ans+sum)%mod;
	} 
	printf("%lld\n",ans);
}
