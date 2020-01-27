#include<iostream>
using namespace std;
int n,ans=1000000;
int n1,p1;
int n2,p2;
int n3,p3;
int div1(int x,int y){
	if(x%y==0) return x/y;
	else return x/y+1;
}
int main(){
	cin>>n;
	cin>>n1>>p1;
	cin>>n2>>p2;
	cin>>n3>>p3;
	ans=min(ans,div1(n,n1)*p1);
	ans=min(ans,div1(n,n2)*p2);
	ans=min(ans,div1(n,n3)*p3);
	cout<<ans;
	return 0;
} 
