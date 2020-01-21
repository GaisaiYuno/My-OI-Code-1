#include<iostream>
using namespace std;
long long read() {
	long long x = 0;
	char c;
	int sign = 1;
	while(c<'0'||c>'9') {
		c=getchar();
		if(c=='-') sign=-1;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x *= sign;
	return x;
}
int main() {
	long long a=read();
	cout<<a;
}
