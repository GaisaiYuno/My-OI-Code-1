#include<iostream>
#include<cstdio>
using namespace std;
int n;
void f2(int x,int y);
void f1(int x,int y){
	if(x<n) f2(y,x+y); 
} 
void f2(int x,int y){
	printf("%d ",x);
	f1(y,x+y);
}
int main(){
	scanf("%d",&n);
	f1(0,1);
}

