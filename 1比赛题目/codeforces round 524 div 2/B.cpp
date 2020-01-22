#include<iostream>
#include<cstdio>
using namespace std;
int l,r,q;
long long sum(long long x,long long y){
	return (x+y)*((y-x)/2+1)/2;
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&l,&r);
		if(l%2==1&&r%2==1){
			cout<<sum(l+1,r-1)-sum(l,r);
		}else if(l%2==0&&r%2==0){
			cout<<sum(l,r)-sum(l+1,r-1);
		}else if(l%2==1&&r%2==0){
			cout<<sum(l+1,r)-sum(l,r-1);
		}else{
			cout<<sum(l,r-1)-sum(l+1,r);
		}
		cout<<endl;
	}
}
