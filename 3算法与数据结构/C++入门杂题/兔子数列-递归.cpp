#include<iostream>
using namespace std;
int f(int n) {
	if(n==1||n==0) return 1;
	return f(n-1)+f(n-2);
}
int main() {
	int a;
input:
	cout<<"请输入项数:";
	cin>>a;

	cout<<"斐波那契数列的第"<<a<<"项是:"<<f(a-1)<<'\n';
	goto input;
}
