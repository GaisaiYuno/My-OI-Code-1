#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n; 
	scanf("%d",&n);
	//��1~n,2~n-1��������n/2���ߣ�����Ϊ0 
	//��2~n,3~n-1 ����n/2���ߣ�����Ϊ1 
	if(n%2==0){
		printf("%d\n",n/2-1);
    }
    else printf("%d\n",n/2);
	 
} 
