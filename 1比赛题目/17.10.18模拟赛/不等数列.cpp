//��� �������� 
#include<iostream>
#define maxn 1001
#define mod 2015
using namespace std;
int f[maxn][maxn]; 
int n,k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) f[i][0]=f[i][i-1]=1;
	 //f[1][0]=1; 
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++)
		   f[i][j]=max(f[i][j],f[i-1][j-1]*(i-j)+f[i-1][j]*(j+1))%mod;
	}
	cout<<f[n][k];
} 
/*���ƹ�ʽ
f[i][j]��ʾǰi��������j��С�ں�
������x����ԭ�������� 
��ԭ��Ϊ>�� 5 4>3 2 1 ---->5 4<x>3 2 1  ��һ��<��
     ��i-1-j��>�ţ���*(i-j-1)
��ԭ��Ϊ<�� 1 2 3<4 5----->1 2 3<x>4>5   ��һ��<��
     ��j��<�ţ���*(i-j-1)
������ͷβҲ����һ��<
�� 5 4 3 2 1<x ��x>5 4 3 2 1,������+1 
f[i][j]=max(f[i][j],f[i-1][j-1]*(i-j)+f[i-1][j]*(j+1));
*/ 
