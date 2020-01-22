#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,m;
long long judge(long long n,long long m){
	if(n==1){
		return max(m%6-3,0ll)*2+m/6*6; 
	}else if(n==2){
		if(m==2) return 0;
		if(m==3) return 4;
		if(m==7) return 12;
		return m*2ll;
	}else{
		if(n%2==1&&m%2==1) return n*m-1;
		else return n*m; 
	}
}
int main(){
	cin>>n>>m;
	if(n>m) swap(n,m);
	cout<<judge(n,m);
}
