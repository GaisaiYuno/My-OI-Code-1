#include<iostream>
using namespace std;
#define max 500

int add(int sum[],int d[],int b[],int num) {

	int i,k,x;
	k=0;
	x=0;

	while(num>k) {//加法程序
		sum[k]=d[k]+b[k]+x;
		x=sum[k]/10;
		sum[k]%=10;
		k++;
	}
	sum[k]=x;
	if(sum[k]==0)
		k--;

	return k;
}
int main() {
	string a,c;
	int i,k,no,lenout;
	int add1[max];
	int add2[max];
	int result[max];
input:
	cout<<"请输入两个小于500位的正整数："<<'\n' ;
	cin>>a;
	cin>>c;

	for(i=0; i<max; i++) {//初始化，否则生成的是随机数
		result[i]=0;
		add1[i]=0;
		add2[i]=0;
	}
	for(i=0; i<a.length(); i++) {//将输入的数组倒过来存
		add1[a.length()-1-i]=a[i]-48;

	}
	cout<<'\n';
	for(i=0; i<c.length(); i++) {
		add2[c.length()-1-i]=c[i]-48;


	}
	no=(a.length()>=c.length())?a.length():c.length();
	lenout=add(result,add1,add2,no);
	cout<<"它们的和是：" ;

	for(i=lenout; i>=0; i--) //输出
		cout<<result[i];
	cout<<endl<<'\n';
	goto input;
	return 1;
}

