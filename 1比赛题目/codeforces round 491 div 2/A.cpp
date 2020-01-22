#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,n;
int main(){
	scanf("%d %d %d %d",&a,&b,&c,&n);
	int tot=a+b-c;
	if(a>n||b>n||c>n||tot<0||a>tot||b>tot||c>tot){
		printf("-1");
	}
	else if(n-tot<1){
		printf("-1");
	}else{
		printf("%d",n-tot);
	}
} 
