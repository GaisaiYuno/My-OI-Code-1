#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll x,y,z; 
int main(){
	cin>>x>>y>>z;
	cout<<(x+y)/z<<' ';
	if(x/z+y/z<(x+y)/z) cout<<min(z-x%z,z-y%z)<<endl;
	else cout<<0<<endl;
	
}

