/*
Problem:��N�����ֳ�2��,ʹÿ��ĺ;������
Source:�����Ż����� 
Algorithm:DP
Description:
01����ģ��+bitset�Ż�
��dpֵѹ��bitset 
ԭ��������dp[i][j]����dp[i]���һ����jλ��bitset
dp[i]<<x,�൱�ڼ���x֮�������ɵ�������� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
#define maxn 250005
#define INF 0x7fffffff
using namespace std;
int n,m,cnt; 
int a[maxn];
bitset<maxn>dp[maxn];
int main(){
	int u,v;
	while(scanf("%d",&n)!=EOF){ 
		if(n<0) break;
		m=0;
		cnt=0;
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; i++){
	      	scanf("%d %d",&u,&v);
	      	while(v--){
	        	a[++cnt]=u;//����ֵ��������
	        	m+=u;
	      	}
		}
		n=cnt;
		dp[0]=1;
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
		}
		for(int j=m/2;j>=0;j--){
			if(dp[n][j]){
				printf("%d %d\n",max(j,m-j),min(j,m-j));
				break;
			}
		} 
	} 
}
