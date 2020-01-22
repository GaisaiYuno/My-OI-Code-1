#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,x;
double ans;
int main(){
	cin>>t;
	while(t--){
		cin>>x;
		ans=0;
		for(int i=1;i<=x;i++){
			ans+=log10(i);
			//cout<<log10(i)<<' ';
		}
		cout<<(int)ans+1<<endl;
	}
} 
//log10(a*b)=log10(a)+log10(b) 
