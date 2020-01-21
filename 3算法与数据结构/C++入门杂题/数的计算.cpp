//Âå¹È ÊıµÄ¼ÆËã
#include<iostream>
using namespace std;
int n,ans=0;
void f(int x){
	if(x==0) return;
	for(int i=1;i<=x/2;i++){
		ans++;
		f(i);
	}
}
int main(){
	cin>>n;
	f(n);
	cout<<ans+1;
	return 0;
} 
