#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 40
using namespace std;
typedef long long ll;
int n;
ll dp[maxn+5][4][4];//dp[x][i][j] ��ʾ��x����Ʒ��i�Ƶ�j�Ļ��� 
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
					//6-i-j��ʾi,j֮�����һ��λ�� 
					//�Ȱ�x-1����i�Ƶ�6-i-j,��x����i��j��Ȼ���ٰ�x-1����6-i-j�Ƶ�j 
					ll p=dp[x-1][i][6-i-j]+t[i][j]+dp[x-1][6-i-j][j];
					//�Ȱ�x-1����i�Ƶ�j����x����i�Ƶ�6-i-j,x-1����j�Ƶ�i,��x����i�Ƶ�j��x-1����i�Ƶ�j 
					ll q=dp[x-1][i][j]+t[i][6-i-j]+dp[x-1][j][i]+t[6-i-j][j]+dp[x-1][i][j];
					dp[x][i][j]=min(p,q);
				}
			}
		}
	}
	printf("%I64d\n",dp[n][1][3]);
}
