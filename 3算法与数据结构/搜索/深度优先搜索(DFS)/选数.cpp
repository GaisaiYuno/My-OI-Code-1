#include<iostream>
#define maxn 1000
using namespace std;
int n,k;
int a[maxn];
bool prime(int a)
{
	for(int i=2;i<=sqrt(a);i++)if(a%i==0) return false;
	return true;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
}
