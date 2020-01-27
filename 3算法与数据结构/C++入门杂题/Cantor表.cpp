//Âå¹È Cantor±í 
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
	int j; 
	cin>>n;
	for(j=1;j<n;j++){
		n-=j;
	}
	if(j%2==0) printf("%d/%d",n,j-n+1);
	else printf("%d/%d",j-n+1,n);
	return 0;
} 
