//洛谷 级数求和 
#include<iostream>
using namespace std;
double s;
int k,n;
int main(){
	cin>>k;
	for(n=1;;n++){
		s=s+(double)(1.0/n);
		if(s>k){
			cout<<n;
			return 0;
		} 
	}
}
