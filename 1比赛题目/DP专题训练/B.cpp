#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 520
using namespace std;
int sum[maxn];
int row[maxn],col[maxn][maxn];
int dp[15][90][maxn];
int n,m;
void ini() {
	for(int i=0; i<(1<<n); i++) {
		if((i&(i>>1))==0) {
			row[i]=1;
			for(int j=i; j>0; j>>=1) {
				if(j&1) sum[i]++;
			}
		}
	}
	for(int i=0; i<(1<<n); i++) {
		if(!row[i]) continue;
		for(int j=0; j<(1<<n); j++) {
			if(!row[j]) continue;
			if((i&(j>>1))==0&&((i>>1)&j)==0&&(i&j)==0) col[i][j]=1;
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	ini();
	for(int i=0;i<(1<<n);i++){
		if(row[i]) dp[1][sum[i]][i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<(1<<n);j++){
			if(!row[j]) continue;
			for(int k=0;k<(1<<n);k++){
				if(!row[k]) continue;
				if(!col[j][k])  continue;
				for(int p=sum[j];p+sum[k]<=m;p++){
					dp[i+1][p+sum[k]][k]+=dp[i][p][j];
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<(1<<n);i++){
		ans+=dp[n][m][i];
	} 
	printf("%lld\n",ans);
}
