//���ж���ΪC(n^3,2)=n^3(n^3-1)/2
//���ڵ���0,1,2,4,���4
//����ֻҪ���������������ȥ���Ϳ�����
//һ����n-1��(���ڵ�������),һ����n�У���ĳ���濴��n�㣬��6�� 
// 6n^2(n-1)
//��Ϊÿ�Ա��ظ��������Σ�����3n^2(n-1),ans= n^3(n^3-1)/2-3n^2(n-1)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long n;
int main(){
	while(scanf("%lld",&n)!=EOF){
		printf("%lld\n",n*n*n*(n*n*n-1)/2-3*n*n*(n-1));
	}
} 
