#include<iostream>
using namespace std;
int f(int n) {
	if(n==1||n==0) return 1;
	return f(n-1)+f(n-2);
}
int main() {
	int a;
input:
	cout<<"����������:";
	cin>>a;

	cout<<"쳲��������еĵ�"<<a<<"����:"<<f(a-1)<<'\n';
	goto input;
}
