#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(a%b==0) return b;
	else gcd(b,a%b);
}
int main(){
	int m,n;
	while(cin>>m>>n){
		cout<<m/gcd(m,n)*n<<endl;
	}
} 
