//���ȫ�����������0
//���ǰ����е�i����i
//��b>a/2,��a%b=a-b
//����a[i]-i>a[i]/2,��a[i]%(a[i]-i)=i-(a[i]-i)=i
//������Ĳ���ʽ֪a[i]>2*i 
//����ͳһ��ÿ��a[i]����2*n�Ϳ��Ա�֤��
//������һ��+������һ��%���� 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int main(){
	scanf("%d",&n);
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>=2&&a[i]<=a[i-1]){
			flag=false;
		}
	}
	if(flag){
		printf("0\n");
		return 0;
	}
	printf("%d\n",n+1);
	printf("1 %d 200000\n",n);
	for(int i=1;i<=n;i++){
		a[i]+=200000; 
	}
	for(int i=1;i<=n;i++){
		printf("2 %d %d\n",i,a[i]-i);
	}
}
