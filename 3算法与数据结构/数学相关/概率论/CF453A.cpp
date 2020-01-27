#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m; 
int main(){
	scanf("%d %d",&m,&n);
	double ans=0;
	for(int i=1;i<=m;i++){//计算扔骰子n次最大值为i的概率 
		double p1=pow(1.0*i/m,n);//n次所有值<=i的概率 
		double p2=pow(1.0*(i-1)/m,n);//减去n次所有值<i的概率，这样计算出来的就是最大值为i的概率 
		double p=p1-p2;
		ans+=p*i;
	}
	printf("%.5f",ans);
}

