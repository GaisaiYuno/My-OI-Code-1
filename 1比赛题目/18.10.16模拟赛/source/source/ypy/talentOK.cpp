//luogu P4377
//����01�����滮
// sum(t[i])/sum(w[i])���
//���ֵ�ǰֵk
//�� sum(t[i])/sum(w[i])>=k����sum(t[i]-k*w[i])>=0ʱ��˵��k�����������ֵС,l=mid
//���ǻ���һ������ sum(w[i])>=m
//����01������w[i]Ϊ���ۣ�t[i]-k*w[i]Ϊ��ֵ��dp[i]��ʾ����Ϊiʱ������ֵ 
//��ô�ж�������ת��Ϊ,�Ƿ����i��[m,+��) ��ʹ��dp[i]>0
//ֱ��DP��MLE��TLE
//���Ǹ�ѭ������ʽ����j�Ƶ�j+w[i]����ֻҪ�� j+w[i]>mʱ����j+w[i]=m����
//�൱�ڰ� (m,+��)�����ֵ�浽dp[m]�� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 255
#define maxv 2000005
#define INF 1e10
using namespace std;
inline int qread(){
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
int n,m;
int w[maxn],t[maxn];
double v[maxn];
double dp[maxv];
int check(double k){
	for(int i=1;i<=n;i++){
		v[i]=(double)t[i]-k*w[i];
	}
	for(int i=1;i<=m;i++) dp[i]=-INF;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){//��j�Ƶ�j+w[i]
			int tmp=j+w[i];
			if(tmp>m) tmp=m;//�� (m,+��)�����ֵ�浽dp[m]�� 
			dp[tmp]=max(dp[tmp],dp[j]+v[i]);
		}
	}
	if(dp[m]>0) return 1;
	else return 0;
}
double bin_ans(){
	double l=0,r=1e9;
	for(int i=1;i<=70;i++){
		double mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return r;
}
int main(){
	n=qread();
	m=qread();
	for(int i=1;i<=n;i++){
		w[i]=qread();
		t[i]=qread();
	}
	double t=bin_ans();
	long long x=floor(1000.0*t);
	printf("%lld\n",x);
}
/*
1 10
15 30
*/
