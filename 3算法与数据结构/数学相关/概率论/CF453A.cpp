#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m; 
int main(){
	scanf("%d %d",&m,&n);
	double ans=0;
	for(int i=1;i<=m;i++){//����������n�����ֵΪi�ĸ��� 
		double p1=pow(1.0*i/m,n);//n������ֵ<=i�ĸ��� 
		double p2=pow(1.0*(i-1)/m,n);//��ȥn������ֵ<i�ĸ��ʣ�������������ľ������ֵΪi�ĸ��� 
		double p=p1-p2;
		ans+=p*i;
	}
	printf("%.5f",ans);
}

