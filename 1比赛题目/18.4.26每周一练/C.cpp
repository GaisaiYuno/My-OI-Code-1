#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int cnt=0;
	int x;
	while(scanf("%d",&x)!=EOF){
		cnt=0;
		while(x>0){
			if(x%2==1) cnt++;
			x/=2;
		}
		printf("%d\n",cnt);
	} 
} 
/*
�Ӷ����ƵĽǶȿ��ǣ�ϸ��������2�൱������һλ��1��������
������һ��ϸ�������һ��1
���ת��Ϊ�����ƣ�ͳ��1�����Ϳ����� 
*/
