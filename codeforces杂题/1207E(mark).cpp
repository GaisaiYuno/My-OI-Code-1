//�����飬��һ��ǰ7λ��ͬ���������Եõ���ǰ7λ 
//�ڶ���ͬ����7λ��ͬ 
#include<iostream>
#include<cstdio>
using namespace std;
int a[105];
int ask(int *a){
	printf("? ");
	for(int i=1;i<=100;i++) printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}

int main(){
	for(int i=1;i<=100;i++) a[i]=(i<<7); //ǰ7λ��ͬ,Ϊ0 
	int x=ask(a);
	for(int i=1;i<=100;i++) a[i]=i;//��7λ��ͬ��Ϊ0
	int y=ask(a); 
	int ans=(x&((1<<7)-1))|(y&(((1<<7)-1)<<7));
	printf("! %d",ans);
}

