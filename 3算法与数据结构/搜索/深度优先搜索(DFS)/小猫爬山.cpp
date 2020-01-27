#include<iostream>
using namespace std;
int c[100];
int main(){
	long long  n,w,sum=0;
	cin>>n>>w;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		sum+=c[i];
	}
	if(sum%w==0)cout<<sum/w;
	else cout<<(sum/w)+1;
	return 0;
}
