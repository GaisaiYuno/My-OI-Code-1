#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000
using namespace std;
int t,k,n,m;
long long C[maxn+5][maxn+5];
long long sum[maxn+5][maxn+5];
void ini(){
	for(int i=0;i<=maxn;i++){
		C[i][0]=C[i][i]=1;
	}
	C[1][1]=1;
	for(int i=2;i<=maxn;i++){
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%k;
		}
	}
	for(int i=1;i<=maxn;i++){
		for(int j=1;j<=i;j++){
			if(C[i][j]==0) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+1;
			else sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
		sum[i][i+1]=sum[i][i];
	}
	
}
int main(){
	scanf("%d %d",&t,&k);
	ini();
	for(int i=1;i<=t;i++){
		scanf("%d %d",&n,&m);
		if(m>n) m=n; 
		printf("%lld\n",sum[n][m]);
//		for(int i=0;i<=max(n,m);i++){
//			for(int j=0;j<=i;j++){
//				printf("%d ",C[i][j]);
//			}
//			printf("\n");
//		} 
	}
}
