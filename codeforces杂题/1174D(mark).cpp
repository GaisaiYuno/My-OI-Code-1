#include<iostream>
#include<cstdio>
#define maxn (1<<18)
using namespace std;
//ά�����е�ǰ׺xor�ͣ�������ת��Ϊǰ׺
//����ͱ�Ϊǰ׺�������в�������ͬ���������Ҳ��ܴ���һ����xor����Ϊx
//������1~2^n-1���ȥȻ���жϾͿ����� 
//����sum[i]=sum[i-1]^a[i],����a[i]=sum[i]^sum[i-1] 
int sum[maxn+5];
int vis[maxn+5];
int n,x;
int cnt=0;
int main(){
	scanf("%d %d",&n,&x);
	sum[0]=0;
	vis[0]=1;
	for(int i=1;i<(1<<n);i++){
		if(vis[i^x]) continue;
		sum[++cnt]=i;
		vis[i]=1;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		printf("%d ",sum[i]^sum[i-1]);
	}
}

