#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 300
#define maxb 256
using namespace std;
typedef long long ll;
int n,k;
int str[maxn+5];
int c[maxn+5],w[maxn+5];
ll dp[maxn+5][maxn+5][maxb+5];//dp[l][r][s],����[l,r]�ϲ���s�ķ��� 
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%1d",&str[i]);
	for(int i=0;i<(1<<k);i++){
		scanf("%d %d",&c[i],&w[i]);
	} 
	memset(dp,0x80,sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][i][str[i]]=0;
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			int rest=(len-1)%(k-1);//ÿ�κϲ�-k��,+1���������k-1�� 
			if(rest==0){//���ÿ��Ժϲ���1�� 
				for(int s=0;s<(1<<k);s++){
					for(int x=r-1;x>=l;x-=(k-1)){
						if(dp[l][x][s>>1]<0||dp[x+1][r][s&1]+w[s]<0) continue;//��ֹ����-INF������ 
						dp[l][r][c[s]]=max(dp[l][r][c[s]],dp[l][x][s>>1]+dp[x+1][r][s&1]+w[s]); 
					}
				}
			}else{
				for(int s=0;s<(1<<k);s++){
					for(int x=r-1;x>=l;x-=(k-1)){
						if(dp[l][x][s>>1]<0||dp[x+1][r][s&1]+w[s]<0) continue;
						dp[l][r][s]=max(dp[l][r][s],dp[l][x][s>>1]+dp[x+1][r][s&1]);//�ϲ����ˣ�û��ת�ƴ���w[s] 
					}
				}
			}
		}
	}
	ll ans=0;
	for(int s=0;s<(1<<k);s++) ans=max(ans,dp[1][n][s]);
	printf("%lld\n",ans);
}

