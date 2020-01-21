//Âå¹È Êı×ÖÍ³¼Æ
#include<iostream>
using namespace std;
int l,r,ans;
int count(int x){
	int n=0;
	while(x>0){
		if(x%10==2) n++;
		x/=10;
	}
	return n;
}
int main(){
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		ans+=count(i);
	}
	cout<<ans;
	return 0;
} 
