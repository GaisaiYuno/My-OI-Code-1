//ʱ�临�Ӷ�O(log2n)��O(n)ֻ����70
/*a[1]=a[2]=a[3]=1
a[x]=a[x-3]+a[x-1] (x>3)
��a ���еĵ�n ���1000000007��10^9+7��ȡ���ֵ��
��һ��һ������T����ʾѯ�ʸ�����
����T �У�ÿ��һ��������n��*/
#include<iostream>
#include<cstring>
#include<cstdio>
#define size 3
#define mod 1000000007
using namespace std;
long long m[size][size]= {{1,0,0},{0,1,0},{0,0,1}};//��ʼ��Ϊ1
long long n,t;
void setup(){//ע��ÿ�ζ�Ҫ��m��ʼ�� 
	m[0][0]=1;
	m[0][1]=0;
	m[0][2]=0;
	m[1][0]=0;
	m[1][1]=1;
	m[1][2]=0;
	m[2][0]=0;
	m[2][1]=0;
	m[2][2]=1;
}
void multi_m(long long x[size][size],long long y[size][size],long long ans[size][size]) { //����˷�
	long long tmp[size][size];
	for(int m=0; m<size; m++) {
		for(int s=0; s<size; s++) {
			tmp[m][s]=0;
			for(int n=0; n<size; n++) {
				tmp[m][s]=(tmp[m][s]+x[m][n]*y[n][s])%mod;
			}
		}
	}
	for(int m=0; m<size; m++) {
		for(int s=0; s<size; s++) ans[m][s]=tmp[m][s]%mod;
	}
}
void fast_pow(long long p) {//������
	long long t[size][size]= {{1,0,1},{1,0,0},{0,1,0}};
	while(p>0) {
		if(p%2==1) {
			multi_m(m,t,m) ;
		}
		p/=2;
		multi_m(t,t,t);
	}
}
int main() {
	cin>>t;
	for(int i=1; i<=t; i++) {
		cin>>n;
		setup();
		fast_pow(n-1);
		cout<<m[0][0]%mod<<endl;
		//debug(m);
	}
	return 0; 
}
