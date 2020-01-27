#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50
#define maxv 5000
#define maxrb 1e10
#define maxt 150 //���ִ𰸵��������������� 
using namespace std;
int n,r;
int a[maxn+5],b[maxn+5];
double p[maxn+5];
double dp[maxn+5][maxv+5];
//dp[i][j]��i�أ���ʱjͨ�ص�����
//���ִ�1�ؿ�ʼͨ�������mid 
bool check(double mid){
	for(int i=n;i>=1;i--){
		for(int j=r+1;j<=maxv;j++){
			dp[i+1][j]=mid;
			//ͨ�س���ʱ�����ƣ��ص�������¿�ʼ 
		}
		for(int j=0;j<=r;j++){
			double t1=(dp[i+1][j+a[i]]+a[i])*p[i];
			double t2=(dp[i+1][j+b[i]]+b[i])*(1-p[i]);
			dp[i][j]=min(mid,t1+t2);
		}
	}
	if(dp[1][0]<mid) return 1;//���ʵ��dpֵ�ȶ���ֵ��С�����Լ�����С���ַ�Χ 
	else return 0;
} 
int main(){
	scanf("%d %d",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
		scanf("%lf",&p[i]);
		p[i]/=100;
	}
	double lb=0,rb=1e10,mid,ans=0;
	for(int i=1;i<=maxt;i++){
		mid=(lb+rb)/2;
		if(check(mid)){
			ans=mid;
			rb=mid;
		}else lb=mid;
	}
	printf("%.9lf",ans);
}

