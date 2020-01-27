#include<iostream>
using namespace std;
int main(){
	int m,s,t;
	int l1,l2;
	cin>>m>>s>>t;
	for(int i=1;i<=t;i++){
		l1=l1+17;
		if(m>=10){
			l2=l2+60;
			m-=10;
		}
		else m+=4;
		if(l1<l2) l1=l2;
		if(l1>=s){
			cout<<"Yes"<<endl<<i;
			return 0; 
		}
	}
	cout<<"No"<<endl<<l1;
	return 0; 
} 
