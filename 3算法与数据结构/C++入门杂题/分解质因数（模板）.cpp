#include<iostream>
#include<cstdio>
using namespace std;
long long n;
bool flag=false;
bool is_prime(long long x){
	if(x%2==0&&x!=2) return false;
	for(int i=3;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}
void find(long long x,long long minx) {
	if(x<minx) return;
	for(int i=minx; i<=x; i++) {
		if(x%i==0) {
			if(flag) cout<<'*';
			else flag=true;
			cout<<i;
			find(x/i,i);
			return;
		}
	}
	return;
}
int main() {
	cin>>n;
	if(is_prime(n)) cout<<"N0\n";
	else cout<<"YE5\n"; 
	cout<<n<<'=';
	find(n,2);
	return 0;
}
