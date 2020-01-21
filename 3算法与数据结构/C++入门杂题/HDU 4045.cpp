//选择机器方案数：
//首先选出(r-1)*k+1个数,这样这些数中一定能选出r个合法的数
//在这之中选r台后，剩下的n-((r-1)*k+1)个数也要插入这r台之中
//也就是说在(r+1)个空里插 n-((r-1)*k+1)个数 
//令 n-((r-1)*k+1)=x
//由插板法公式得C(r+x,r) 
//r台分m组直接用第二类斯特林数算 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 1005
#define mod 1000000007
using namespace std;
int n,r,k,m;
long long C[maxn][maxn];
long long S[maxn][maxn];
void prework(){
	C[0][0]=1;
	for(int i=1;i<=1000;i++){
		C[i][0]=C[i][i]=1;
	}
	for(int i=1;i<=1000;i++){
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	S[0][0]=0;
	for(int i=1;i<=1000;i++){
		S[i][i]=1;
		S[i][0]=0;
	}
	for(int i=2;i<=1000;i++){
		for(int j=1;j<i;j++){
			S[i][j]=(S[i-1][j-1]+j*S[i-1][j]%mod)%mod;
		}
	}
} 
int main(){
	long long ans=0;
	prework();
	while(scanf("%d %d %d %d",&n,&r,&k,&m)!=EOF){
		ans=0;
		int left=n-((r-1)*k+1);
		if(left<0){
			printf("0\n");
			continue; 
		} 
		for(int i=1;i<=m;i++){
			ans=(ans+S[r][i])%mod;
		}
		ans=(ans*C[r+left][r]%mod);
		printf("%I64d\n",ans%mod);
	}
}
