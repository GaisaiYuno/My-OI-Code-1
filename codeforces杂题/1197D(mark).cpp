#include<iostream>
#include<cstdio>
#define maxn 300000
using namespace std;
typedef long long ll;
int n,m,k;
int a[maxn+5];
ll sum[maxn+5];
ll dp[maxn+5];//dp[i]��ʾǰi�����Ĵ� 
inline ll get_sum(int l,int r){
	return sum[r]-sum[l-1];
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll suf=0;
		ll maxsuf=0;
		//���г���<m,ֱ���ҳ�(i-m,i)�����������׺ 
		for(int j=i-1;j>=max(i-m+1,1);j--){
			suf+=a[j];
			maxsuf=max(suf,maxsuf);
		}
		dp[i]=max(0ll,maxsuf+a[i]-k);//����Ϊk
		//����>=m,���Ӵ���k ,ֱ�Ӵ�i-mת�Ƽ��ɣ���Ϊi-m������>=0,�ܳ���>=m 
		if(i-m>0) dp[i]=max(dp[i],dp[i-m]+get_sum(i-m+1,i-1)+a[i]-k);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	printf("%I64d\n",ans);
}

