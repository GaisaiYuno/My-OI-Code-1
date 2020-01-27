//expr
#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int a1,a2;
char sign;
int ans=0;
int main() {
	//freopen("expr.in","r",stdin);
	//freopen("expr.out","w",stdout);
	cin>>a1; 
	while(cin>>sign){
		cin>>a2;
		a2%=10000;
		if(sign=='+'){
			ans+=a1;
			ans%=10000;
			a1=a2;
		}
		if(sign=='*'){
			a1*=a2;
			a1%=10000;
		}
	}
	ans+=a1;
	cout<<ans%10000;
	return 0;
}
