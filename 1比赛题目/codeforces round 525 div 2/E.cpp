//����DP
//��һ��DP���ÿ����������ֵ��dp[x]��ʾ��xΪ�������������Ȩֵ�ͣ�����ѡx)
//DP��͵õ����п��е����ֵans 
//����ΪҪ������
//������DPһ�Σ�һ����ǰ��dp[x]=ansʱ��˵����ǰ���Ѿ�����������k++ 
// ���ڿ鲻�ܻ��������������dp[x]=0����������x�����Ƚڵ������ʱ�ÿ�һ�����ᱻ������ȨֵΪ0) 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 300005
#define INF 0x7ffffffffffffff
using namespace std;
int n,k;
long long ans=0;
int a[maxn];
long long dp[maxn];
vector<int>E[maxn];
void dfs1(int x,int fa){
	dp[x]=a[x];
	for(auto y : E[x]){
		if(y!=fa){
			dfs1(y,x);
			dp[x]+=max(dp[y],0ll);
		}
	}
	ans=max(ans,dp[x]);
}
void dfs2(int x,int fa){
	dp[x]=a[x];
	for(auto y : E[x]){
		if(y!=fa){
			dfs2(y,x);
			dp[x]+=max(dp[y],0ll);
		}
	}
	if(dp[x]==ans){
		k++;
		dp[x]=0;
	}
}

int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans=-INF;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%I64d %d\n",ans*k,k);
}
