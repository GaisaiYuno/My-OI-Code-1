#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 5000
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
double dp[maxn+5][maxn+5];//dp[i][j]��ʾǰj�������i-1�׵ĸ��� 
double p[maxn+5];
int t[maxn+5];
double tmp[maxn+5];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lf",&p[i]);
		p[i]/=100;
		scanf("%d",&t[i]);
	}
	p[n+1]=0;
	t[n+1]=INF;
	dp[1][0]=1;
	for(int i=1;i<=n+1;i++){
		double p1=pow(1-p[i],t[i]);//���ټ�����������
		for(int j=0;j<=m;j++) tmp[j]=dp[i][j];//��ֹ�ظ����� 
		for(int j=0;j<=m;j++){
			//�����ǹ�һ��ʱ���������� 
			dp[i][j+1]+=dp[i][j]*(1-p[i]);
			dp[i+1][j+1]+=dp[i][j]*p[i]; 
			//���ǹ�һ��ʱ���������� 
			if(j+t[i]<=m){
				dp[i+1][j+t[i]]+=tmp[j]*p1;//���ﲻ��дdp[i][j]����Ϊdp[i][j]���ܻ���j-1��ʱ�򱻸��£�Ӱ����� 
				dp[i][j+t[i]]-=tmp[j]*p1;//��Ϊ�������������Լ��� 
			}
		}
	}
	double ans=0;
	for(int i=1;i<=n+1;i++){
		ans+=dp[i][m]*(i-1);
	} 
	printf("%.7f\n",ans);
}
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#define maxn 5000
//#define INF 0x3f3f3f3f
//using namespace std;
//int n,m;
//double dp[maxn+5][maxn+5];//dp[i][j]��ʾǰj�������i-1�׵ĸ��� 
//double p[maxn+5];
//int t[maxn+5];
//double tmp[maxn+5];
//int main(){
//	scanf("%d %d",&n,&m);
//	for(int i=1;i<=n;i++){
//		scanf("%lf",&p[i]);
//		p[i]/=100;
//		scanf("%d",&t[i]);
//	}
//	dp[0][0]=1;
//	for(int i=1;i<=m;i++) dp[0][i+1]+=d[0]
//	for(int i=1;i<=n;i++){
//		double p1=pow(1-p[i],t[i]);//���ټ�����������
//		for(int j=0;j<=m;j++) tmp[j]=dp[i][j];//��ֹ�ظ����� 
//		for(int j=0;j<=m;j++){
//			//�����ǹ�һ��ʱ���������� 
//			dp[i][j+1]+=dp[i][j]*(1-p[i]);
//			dp[i+1][j+1]+=dp[i][j]*p[i]; 
//			//���ǹ�һ��ʱ���������� 
//			if(j+t[i+1]<=m){
//				dp[i+1][j+t[i+1]]+=tmp[j]*p1;//���ﲻ��дdp[i][j]����Ϊdp[i][j]���ܻ���j-1��ʱ�򱻸��£�Ӱ����� 
//				dp[i][j+t[i+1]]-=tmp[j]*p1;//��Ϊ�������������Լ��� 
//			}
//		}
//	}
//	double ans=0;
//	for(int i=0;i<=n;i++){
//		ans+=dp[i][m]*(i-1);
//	} 
//	printf("%.7f\n",ans);
//}

