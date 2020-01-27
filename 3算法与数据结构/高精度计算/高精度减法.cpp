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
	for(i=0; i<a.length(); i++) {//将输入的数组倒过来存
		b[a.length()-1-i]=a[i]-48;
		//cout<<b[a.length()-1-i];
	}
	for(i=0; i<c.length(); i++) {
		d[c.length()-1-i]=c[i]-48;
		//cout<<d[c.length()-1-i];

	}
	k=0;
	x=0;
	num=(a.length()>=c.length())?a.length():c.length();
	while(num>=k) {
		if(b[k]<d[k]) {
			b[k]+=10;
			b[k+1]--;

		}
		sum[k]=b[k]-d[k];
		k++;
	}
	if((sum[k]==0)&&(k>1) )k--;
	if(sum[k]!=0) {
		for(i=k-1; i>=0; i--) { //输出
			cout<<sum[i];
		}
	} else if(sum[k-2]!=0) {
		for(i=k-1; i>=0; i--) { //输出
			cout<<sum[i];
		}
	} else {
		for(i=k-3; i>=0; i--) { //输出
			cout<<sum[i];
		}
	}


	return 0;
}

