#include<iostream>
using namespace std;
//—Ó≈‡‘¥
int main() {
	int a,b,c,shu;
input:
	b=1;
	c=1;

	cout<<"«Î ‰»Î";
	cin>>a;

	for(int i=1; i<=a-2; i++) {
		shu=b+c;
		b=c;
		c=shu;
		//cout<<shu<<' ';
	}
	cout<<shu<<' ';
//	shu=0;
	goto input;
	return 0;
}
