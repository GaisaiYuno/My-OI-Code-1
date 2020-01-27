/*
[El Psy Congroo]
For Selina

Problem:B
Source:Codeforces round 533 (div 2)
Description:
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long k,x; 
int main(){
	cin>>n;
	while(n--){
		cin>>k>>x;
		cout<<(k-1)*9+x<<endl;
	}
}

