#include<iostream>
using namespace std;
int n;
int base=1;
int main(){
	freopen("ans.out","w",stdout);
//	if(!n)cin>>n;
	n=1000000;
	if(n==3){
		cout<<1*base<<' '<<1*base<<' '<<3*base<<' ';
		return 0;
	}
	if(n==2){
		cout<<1*base<<' '<<2*base<<' ';
		return 0;
	}
	if(n==1){
		cout<<base;
		return 0;
	}
	for(int i=1;i<=n;i+=2){
		cout<<base<<' ';
	}
	base*=2;
	n/=2;
	main();
}
