#include<iostream>
using namespace std;
#define max 300
int main() {
	string a,c;
	int i,k,x,num;
	int b[max];
	int d[max];
	int sum[max];
		cin>>a;
		cin>>c;

		for(i=0; i<max; i++) {//初始化，否则生成的是随机数
			sum[i]=0;
			b[i]=0;
			d[i]=0;
		}

		if(fuhao==0) {
			for(i=0; i<a.length(); i++) {
				b[a.length()-1-i]=a[i]-48;
				
			}
			for(i=0; i<c.length(); i++) {
				d[c.length()-1-i]=c[i]-48;
			

			}
		}
 		else{
			for(i=0; i<a.length(); i++) {
				d[a.length()-1-i]=a[i]-48;
				
			}
			for(i=0; i<c.length(); i++) {
				b[c.length()-1-i]=c[i]-48;
				

			}
		}
		k=0;
		x=0;
		num=(a.length()>=c.length())?a.length():c.length();
		while(num>k) {
			if(b[k]<d[k]) {
				b[k]+=10;
				b[k+1]--;

			}
			sum[k]=b[k]-d[k];
			k++;
		}
		k--;
		while(sum[k]==0) {
			k--;
			if(k==0) {
				//	cout<<sum[i];
				break;
			}
		}
		 if(fuhao==1) 	cout<<'-';
		for(i=k; i>=0; i--) { //输出		   
			cout<<sum[i];
		}
	return 0;
}
