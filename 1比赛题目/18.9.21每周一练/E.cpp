//floyd�ı�����dp
//dp[k][i][j]��ʾ����ǰk����ʱi��j�����·
//dp[k][i][j]=min(dp[k-1][i][k]+dp[k-1][k][j],dp[k-1][i][j]
//kΪ�׶�,��������ѭ��
//ʵ���㷨��ȥ����һά 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 505
using namespace std;
int n;
int del[maxn];
int _hash[maxn];//hash�ǹؼ��� 
long long a[maxn][maxn];
long long dist[maxn][maxn];
long long ans[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%I64d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&del[i]);
		_hash[del[i]]=n-i+1;
		//�������洢,��Ϊfloyd�㷨�е�k������ǰk����ʱ,�Ǵ��ٵĵ��Ƶ���ĵ� 
		//ɾ��n-1����ʱ�ڵ�����,ɾ��1����ʱ�ڵ����,������˳���෴
		//���Է������� 
		//�����һ��ɾ�Ľڵ�hash��1,��һ��ɾ��hash��n,�����Ʋŷ���˳�� 
		//kʱ�Ƴ��Ľ����ʵ��ɾ��n-k+1�����Ľ�� 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[_hash[i]][_hash[j]]=a[i][j];
		}
	}
	long long sum=0;
	for(int k=1;k<=n;k++){
		sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				sum+=dist[i][j];
			}
		}
		ans[n-k+1]=sum;
	} 
	for(int i=1;i<=n;i++){
		printf("%I64d ",ans[i]);
	}
} 
