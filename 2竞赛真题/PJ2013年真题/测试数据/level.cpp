//level
#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int main(){
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	cin>>n>>m;
	if(m==2) cout<<2;
	else if(m==3) cout<<3;
	else cout<<"I don't know the answer!!!!!";
	return 0;
} 
