#include<iostream>
using namespace std;
#define max 1500
int main() {
	int N;
	int i,k,x,m;
	int b[max];
	int d[max];
	int sum[max];
input:
	cout<<"请输入正整数："<<'\n' ;
	cin>>N;
	for(i=0; i<max; i++) {
		sum[i]=0;
		b[i]=0;
		d[i]=0;
	}
	b[0]=1;
	d[0]=1;
	if(N==1||N==2) {
		cout<<1;
		return 0;
	}
	for(i=1; i<=N-2; i++) {
		k=0;
		x=0;
		while(max>k) {//加法程序
			sum[k]=d[k]+b[k]+x;
			x=sum[k]/10;
			sum[k]%=10;
			k++;
		}
		sum[k]=x;
		if(sum[k]==0)
			k--;
		for(m=0; m<max; m++) {
			b[m]=d[m];
			d[m]=sum[m];

		}

	}
	for(i=max-1; i>=0; i--) {
		if(sum[i]!=0) 	break;

	}
	for(; i>=0; i--) {
		cout<<sum[i];
	}
	cout<<'\n' ;
	goto input;
	return 0;
}
