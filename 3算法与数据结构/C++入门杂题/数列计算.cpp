#include<iostream>
#define max 1000000
using namespace std;
double a[max];
int main(){
	a[1]=0;
	a[2]=2016;
	int n;
	cin>>n;
	freopen("out.txt","w",stdout);
	cout<<a[1]<<' '<<a[2];
    for(int i=3;i<=n;i++){
		a[i]=(a[i-1]+a[i-2])/2;
		cout<<a[i]<<' ';
    }
    return 0;
} 
