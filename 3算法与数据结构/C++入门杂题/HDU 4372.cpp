//ѭ������:n�����ų�һȦ�ķ����� n!/n=(n-1)! 
//��һ��˹������S(p,k)����p�������ų�k���ǿ�ѭ�����еķ�������
//S(p,k)�ĵ��ƹ�ʽ�� S(p,k)=(p-1)*S(p-1,k)+S(p-1,k-1) ,1<=k<=p-1
// (p-1)*S(p-1,k)�嵽֮ǰ������,����p-1��λ������ѡһ��           S(p-1,k-1)����һ���� 
//�߽�S(i,i)=1,S(i,0)=0
 
//����ߵ��ó���,�����f-1�����ӿ��Կ������ұ���b-1�����ӣ�
//Ҳ���Ǵ�n-1��������ѡ��f+b-2�����ӣ���f+b-2�����Ӹ�������һ�飬�ֳ���f+b-2��
//����ÿ��������k����,�����Ǹ����������ң��ߣ�ʣ��ģ�k-1)��ȫ���У�������(k-1)!������(k-1)������k������ѭ������
//���Է���������S(n-1,f+b-2)
//����Ϊ��ǰ���ϵ��Ҫ��f+b-2��ѡf-1����ǰ��ķ���
//���մ�Ϊ  S(n-1,f+b-2)*C(f+b-2,f-1)

#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000
#define mod 1000000007
using namespace std;
int t,n,f,b;
long long S[maxn+5][maxn+5];
long long C[maxn+5][maxn+5];
void prework(){
	C[0][0]=1;
	for(int i=1;i<=maxn;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	S[0][0]=1;
	for(int i=1;i<=maxn;i++){
		S[i][0]=0;
		S[i][i]=1;
		for(int j=1;j<i;j++){
			S[i][j]=(S[i-1][j-1]+((i-1)*S[i-1][j])%mod)%mod;
		}
	}
} 
int main(){
	prework();
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&f,&b);
		if(f+b-2>n){
			printf("%d\n",0);
		}else{
			printf("%I64d\n",(S[n-1][f+b-2]*C[f+b-2][f-1])%mod);
		}
	}
} 

