/*��һ��3*n�ĳ����η����У�����1*2�Ĺ��ƣ�����n,�󷽰���*/
#include<iostream>
using namespace std;
long long f[1000][3];
int n;
int main(){
	f[0][0]=1;
	f[0][2]=1;
	f[1][1]=1;
	cin>>n;
	for(int i=2;i<=n;i++){
		f[i][0]=f[i-2][0]+f[i-1][1]+f[i-2][2];
		f[i][1]=f[i-1][2];
		f[i][2]=f[i-1][1]+2*f[i-1][0];
	}
	cout<<f[n][0]; 
}
/*
f[i][0]û��ͻ�� 
f[i][1]��һ��ͻ��
f[i][2]������ͻ�� 
*/ 

