#include<iostream>
#include<cmath>
using namespace std;
bool is_prime(int x){
	if(x%2==0&&x!=2) return false;
	for(int i=3;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}
int main()
{
	long long int a;
    while(1){
	cout<<"�����룺";
	cin>>a;
	
	if(is_prime(a))
		cout<<a<<"������"<<'\n';
	else cout<<a<<"��������"<<'\n';
}
}
