/*
Problem:��N�����ֳ�2��,ʹÿ��ĺ;������
Source:�����Ż����� 
Algorithm:DP
Description:
���������sqrt(m)�����ظ��ĺܶ࣬���Ƕ��ر���
�����Ʋ�� 
*/
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
#define maxn 10005
#define INF 0x7fffffff
using namespace std;
int n,m; 
int v[maxn],k[maxn];
int a[maxn];
bitset<maxn>dp[maxn];
void divide(){
	int newn=0;
	for(int i=1;i<=n;i++){
        for(int j=0;(1<<j)<=k[i];j++){
            a[++newn]=(1<<j)*v[i];
        }
    }
    n=newn;
} 
int main(){
	while(scanf("%d",&n)!=EOF){ 
		if(n<0) break;
		m=0; 
		for(int i=1;i<=n;i++){
			scanf("%d %d",&v[i],&k[i]);
			m+=v[i]*k[i];
		}
		for(int i=0;i<=m;i++) dp[i]=0;
		divide();
		dp[0]=1;
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
		}
		for(int j=m/2;j>=0;j--){
			if(dp[n][j]){
				printf("%d %d\n",m-j,j);
				break;
			}
		} 
	} 
}
