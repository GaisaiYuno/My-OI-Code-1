#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 5000
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,k,m; 
int lf[maxn+5],gf[maxn+5];
//��ʾa[i]��a[i-1]����Դ�С,cp[i]=0����������,cp[i]=-1��ʾa[i-1]>a[i],cp[i]=1��ʾa[i-1]<a[i] 
ll dp[maxn+5][maxn+5];//dp[i][j]��ʾǰi�ˣ���i���˵��ǹ�������Ϊj
//ת�Ƶ�ʱ�����һ����j,�������� 
ll sum[maxn+5];//dp[i]��ǰ׺�� 
int main(){
	int x;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		x++;
		gf[x]=1;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		x++;
		lf[x]=1;
	}
	dp[1][1]=1;
	for(int j=1;j<=n;j++) sum[j]=(sum[j-1]+dp[1][j])%mod;
	for(int i=2;i<=n;i++){
		if(gf[i-1]||lf[i]){//a[i]>a[i-1]
			for(int j=1;j<=i;j++) dp[i][j]=(dp[i][j]+sum[j-1])%mod;//��һ������ģ�����Ϊj 
		}
		else if(gf[i]||lf[i-1]){//a[i]<a[i-1]
			for(int j=1;j<=i;j++){
				dp[i][j]=(dp[i][j]+(sum[n]-sum[j-1])%mod+mod)%mod;//��i-1����������>=j,��Ϊa[i]<a[i-1],����a[i]������>j 
			}
		}else{//������ 
			for(int j=1;j<=i;j++) dp[i][j]=(dp[i][j]+sum[n])%mod;
		}
		sum[0]=0;
		for(int j=1;j<=n;j++) sum[j]=(sum[j-1]+dp[i][j])%mod;
		
	}
	ll ans=sum[n];
	printf("%lld\n",ans);
}
