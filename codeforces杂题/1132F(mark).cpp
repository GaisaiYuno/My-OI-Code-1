//��dp[i][j]��ʾ[i,j]�������С���� 
#include<iostream>
#include<cstdio>
#define maxn 505
using namespace std;
int n;
char s[maxn];
int dp[maxn][maxn];
int main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1; i<=n; i++) dp[i][i]=1;
	for(int len=2; len<=n; len++) {
		for(int i=1; i+len-1<=n; i++) {
			int j=i+len-1;
			if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+1;//ֱ��ɾ��i,j 
			else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;//����ɾi,��j 
			for(int k=i; k<=j; k++) {
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]-1);
				//��һ���ڵ�ֳ����룬������ֱ�����ٺ����������ڵ�k����ĸ���ظ�ɾ��2�Σ���Ҫ-1 
				//����д�� p[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]);
				//��Ϊ�����ٿ�����һ���������ababa,3��a����1��ɾ��
				//���������aba,ba��������ͣ��ͱ��2���� 
			}

		}
	}
	printf("%d\n",dp[1][n]);
}

