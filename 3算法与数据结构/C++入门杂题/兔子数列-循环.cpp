#include<iostream>
#define max 300
using namespace std;
int add(string a,string c) {
	int i,k,x,num;
	int b[max];
	int d[max];
	int sum[max];

		for(i=0; i<max; i++) {
			sum[i]=0;
			b[i]=0;
			d[i]=0;
		}
		for(i=0; i<a.length(); i++) {
			b[a.length()-1-i]=a[i]-48;
			
		}
		for(i=0; i<c.length(); i++) {
			d[c.length()-1-i]=c[i]-48;
			

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

	return 0;
}
int main() {
	int a,b,c,shu;
	b=1;
	c=1;
	cin>>a;
	for(int i=1; i<=a-2; i++) {
		shu=b+c;
		b=c;
		c=shu;

	}
	cout<<shu<<' ';
	return 0;
}
