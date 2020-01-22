//����ÿ������ֵx,����dp�������ֵΪx�����и��������������ۼӾ͵õ����մ�
//���ݸ���ԭ��,����Ϊk��������k-1���������ֵΪn/(k-1)  
//O(sum(max(a[i])/(k - 1)*n*k)) = O(n*max(a[i])) 
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#define maxn 1000
#define mod 998244353
using namespace std;
typedef long long ll;
int n,k;
int a[maxn+5];
ll dp[maxn+5][maxn+5];//dp[i][j]��ʾ����Ϊi�����һ����Ϊa[j]�����и��� 
ll sum[maxn+5];
//dp[i][j]+=dp[i-1][k],a[j]-a[k]>=x
//˫ָ�뷨�ҳ�j��Ӧ�����һ��a[j]-a[k]>=x��λ�ã�ǰ׺���Ż�һ�¼���
ll calc(int x){
	for(int i=0;i<=k;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=0;
		}
	}
	for(int j=1;j<=n;j++){
		dp[1][j]=1;
		sum[j]=sum[j-1]+dp[1][j]%mod;
	}
	for(int i=2;i<=k;i++){
		int l=1;
		for(int j=1;j<=n;j++){
			while(a[j]-a[l]>=x) l++;
			dp[i][j]=(dp[i][j]+sum[l-1])%mod;
		}
		sum[0]=0; 
		for(int j=1;j<=n;j++){
			sum[j]=sum[j-1]+dp[i][j]%mod;
		} 
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans=(ans+dp[k][i])%mod;
	return ans;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1;i<=a[n]/(k-1);i++) ans=(ans+calc(i))%mod;
	printf("%I64d\n",ans);
}

