#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 1000005 
#define INF 0x7fffffff
using namespace std;
inline int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
	    if(c=='-') sign=-1;
	    c=getchar();
    }
    while(c>='0'&&c<='9'){
    	x=x*10+c-'0';
    	c=getchar();
	}
	return x*sign;
} 
int m,n;
int a[maxn];
long long dp[maxn],max_sum[maxn];
int main(){
	while(cin>>m>>n){
		for(int i=1;i<=n;i++){
			a[i]=fread();
			max_sum[i]=dp[i]=0;
		}
		dp[0]=max_sum[0]=0;
		long long ans=-INF;
		for(int i=1;i<=m;i++){
			ans=-INF;
			for(int j=i;j<=n;j++){
				dp[j]=max(dp[j-1]+a[j],max_sum[j-1]+a[j]);
				max_sum[j-1]=ans;
				ans=max(ans,dp[j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//dp[i][j] Ϊǰ j �����ֳַ� i �ε�����,��β��a[j] 
//dp[i][j]=max(dp[i][j-1],max(dp[i-1][k]))+a[j](i-1<=k<=j-1)
//dp[i][j]�����ֻ��dp[*][j]��dp[*][j-1]�й����Ա���ֻ��Ҫ����һά���� 
//ÿ�μ���dp[i][j]��ʱ���¼��ǰj�������ֵ �����鱣������  �´μ����ʱ�������
