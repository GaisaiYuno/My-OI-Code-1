//Âå¹È ÌÔÌÔÕªÆ»¹û 1046 
#include<iostream>
using namespace std;
int apple[10];
int main(){
	int h,ans=0,i;
	for(i=0;i<10;i++){
		cin>>apple[i];
	}
	cin>>h;
	for(i=0;i<10;i++){
		if(apple[i]<=h+30) ans++;
	}
	cout<<ans;
} 
