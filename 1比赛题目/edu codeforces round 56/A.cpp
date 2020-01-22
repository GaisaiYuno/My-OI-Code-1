#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,x;
int work(int a){
	for(int i=0;i<=a/3;i++){
		if((a-i*3)%2==0){
			return i+(a-i*3)/2;
		}
	}
}
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x;
		cout<<work(x)<<endl;
	}
} 
