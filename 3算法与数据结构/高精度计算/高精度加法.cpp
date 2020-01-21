#include<iostream>
using namespace std;
#define max 500
int main() {
	string a,c;
	int i,k,x,num;
	int b[max];
	int d[max];
	int sum[max];
	//while(1) {
		//cout<<"请输入两个小于500位的正整数："<<'\n' ;
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
		//cout<<'\n';
		for(i=0; i<c.length(); i++) {
			d[c.length()-1-i]=c[i]-48;
			//cout<<d[c.length()-1-i];

		}
		k=0;
		x=0;
		num=(a.length()>=c.length())?a.length():c.length();
		while(num>k) {//加法程序
			sum[k]=d[k]+b[k]+x;
			x=sum[k]/10;
			sum[k]%=10;
			k++;
		}
		sum[k]=x;
		if(sum[k]==0)
			k--;
		//cout<<"它们的和是：" ;
		for(i=k; i>=0; i--)//输出
			cout<<sum[i];
		//cout<<endl<<'\n';
	//}
	return 0;
}

