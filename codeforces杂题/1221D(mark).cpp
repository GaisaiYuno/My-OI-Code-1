//ע�⵽ÿ��ֵ��౻+2,
//��Ϊ��a[i-1]=a[i]ʱ�����ǿ��԰�a[i-1] ��a[i]+1,
//�����������ܻ����a[i-1]=a[i-2],����a[i-1]��+1 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300000 
#define maxd 2 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n,q;
int a[maxn+5];
ll b[maxn+5]; 
ll dp[maxn+5][maxd+5];
int main(){
	scanf("%d",&q);
	while(q--){ 
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %I64d",&a[i],&b[i]); 
		} 
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				dp[i][j]=INF;
				for(int k=0;k<=2;k++){
					if(a[i]+j!=a[i-1]+k) dp[i][j]=min(dp[i][j],dp[i-1][k]+j*b[i]);	
				}
			}
		}
		printf("%I64d\n",min(min(dp[n][0],dp[n][1]),dp[n][2]));
	} 
}

