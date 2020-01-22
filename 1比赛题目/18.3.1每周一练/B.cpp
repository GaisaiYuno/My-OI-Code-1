#include<iostream>
#include<cmath>
using namespace std;
int c,n;
int n1,n2,n3;
int main(){
	cin>>c;
	while(c--){
		cin>>n;
		n1=n/2;
		n-=n1;
		n2=n*2/3;
		n-=n2;
		n3=n;
		int sum=0;
		sum+=n1/10+n2/10+n3/10;
		if(n1-10*(n1/10)>0) sum++;
		if(n2-10*(n2/10)>0) sum++;
		if(n3-10*(n3/10)>0) sum++;
        cout<<sum<<endl;
	}
} 
