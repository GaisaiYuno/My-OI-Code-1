#include<iostream>
using namespace std;
#define max 500
int main() {
	string a,c;
	int i,k,x,num;
	cin>>a;
	cin>>c;
	int b[max];
	int d[max];
	int sum[max];
	
	for(i=0; i<max; i++) {
	           sum[i]=0;
               b[i]=0;
               d[i]=0;
	}
	for(i=0; i<a.length(); i++) {
		b[i]=a[i]-48;

	}
	//cout<<'\n';
	for(i=0; i<c.length(); i++) {
		d[i]=c[i]-48;
		//cout<<d[i];

	}
	k=0;
	x=0;
	
	
	num=(a.length()>=c.length())?a.length():c.length();
	
	
	while(num>k) {
		sum[k]=d[k]+b[k]+x;
		x=sum[k]/10;
		sum[k]%=10;
		k++;
	}
	sum[k]=x;
	if(sum[k]==0) 
		k--;
	
	for(i=k; i>=0; i--)
		cout<<sum[i];
	cout<<endl;
	return 0;
}

