/*��һ��3*n�ĳ����η����У�����1*2�Ĺ��ƣ�����n,�󷽰���*/ 
#include<iostream>
#define maxn 100
using namespace std;
long long f[maxn];
int n; 
int main(){
	cin>>n;
	f[1]=0;
	f[2]=3;
	f[3]=0;
	f[4]=11;
	for(int i=5;i<=n;i++) f[i]=4*f[i-2]-f[i-4];
    cout<<f[n]<<endl;
    for(int i=1;i<=n;i++) cout<<f[i]<<' ';

}
