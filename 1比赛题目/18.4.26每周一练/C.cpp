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
从二进制的角度考虑，细菌数量乘2相当于右移一位，1总数不变
而加入一个细菌则多了一个1
因此转换为二进制，统计1数量就可以了 
*/
