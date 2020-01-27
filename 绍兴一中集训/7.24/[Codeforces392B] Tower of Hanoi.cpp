#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 40
using namespace std;
typedef long long ll;
int n;
ll dp[maxn+5][4][4];//dp[x][i][j] 表示把x个物品从i移到j的花费 
int t[4][4];
int main(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&t[i][j]);
		}
	}
	scanf("%d",&n);
	for(int x=1;x<=n;x++){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(i!=j){
					//6-i-j表示i,j之外的另一个位置 
					//先把x-1个从i移到6-i-j,第x个从i到j，然后再把x-1个从6-i-j移到j 
					ll p=dp[x-1][i][6-i-j]+t[i][j]+dp[x-1][6-i-j][j];
					//先把x-1个从i移到j，第x个从i移到6-i-j,x-1个从j移到i,第x个从i移到j，x-1个从i移到j 
					ll q=dp[x-1][i][j]+t[i][6-i-j]+dp[x-1][j][i]+t[6-i-j][j]+dp[x-1][i][j];
					dp[x][i][j]=min(p,q);
				}
			}
		}
	}
	printf("%I64d\n",dp[n][1][3]);
}
