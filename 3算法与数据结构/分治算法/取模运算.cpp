//Êép283 Àı7.5 
//Âå¹È ¿ìËÙÃİ 
#include<iostream>
using namespace std;
long long int b,p,k,s;
int div(int p){
	int temp; 
	if(p==0) return 1;
	else{
	    temp=div(p/2)%k;
		temp=(temp*temp)%k;
		if(p%2==1) temp=(temp*b)%k;
	}
	return temp;
}
int main(){
	cin>>b>>p>>k;
	int t=b;
	b=b%k;
	cout<<t<<"^"<<p<<' '<<"mod"<<' '<<k<<"="<<div(p)<<endl; 
} 
