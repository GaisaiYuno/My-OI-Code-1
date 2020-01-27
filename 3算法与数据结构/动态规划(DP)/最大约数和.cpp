//洛谷 最大约数和
//01 背包 
#include<iostream>
#include<cstdio>
#define maxs 1005
using namespace std;
int s;
struct node{
	int size;
	int value;
}num[maxs];
int f[maxs];
int main(){
	cin>>s;
	num[1].size=num[1].value=1;
	for(int i=2;i<=maxs;i++){
		num[i].size=i;
		for(int j=1;j<i;j++){
			if(i%j==0){
				num[i].value+=j;
			}
		}
	}
	for(int i=2;i<=s;i++){
		for(int j=s;j>=num[i].size;j--){
			if(f[j]<f[j-num[i].size]+num[i].value) f[j]=f[j-num[i].size]+num[i].value;
		}
	}
	//for(int i=1;i<=s;i++) cout<<f[s]<<' ' ;
	cout<<f[s];
	return 0;
}
