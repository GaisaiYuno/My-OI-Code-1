/*��һ��2*n�ĳ����η����У�����1*2�Ĺ��ƣ�����n,�󷽰���*/ 
#include<iostream>
#define maxn 100
using namespace std;
long long f[maxn];
int n; 
int main(){
	cin>>n;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
	cout<<f[n];
}
