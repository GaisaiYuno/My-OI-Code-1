#include<iostream>
#include<cstdio>
using namespace std;
double x,ans;
int main(){
	for(int i=1;i<=12;i++){
		cin>>x;
		ans+=x;
	}
	printf("$%.2f",ans/12);
	return 0;
}
