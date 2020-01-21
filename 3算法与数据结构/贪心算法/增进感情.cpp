//洛谷 增进感情 2080 
#include<iostream>
#include<cmath>
#include<algorithm>
#define maxn 100
using namespace std;
int n,v;
struct str{
	int a;
	int b;
	int c;
}num[maxn];
int comp(str x,str y){
	return abs(x.c)<abs(y.c);
}
int main(){
	cin>>n>>v;
	for(int i=0;i<n;i++){
		cin>>num[i].a>>num[i].b;
		num[i].c=num[i].a-num[i].b;
	}
	sort(num,num+n,comp);
	int sum=0,diff=0;//和与差 
	for(int i=0;i<n;i++){
		if(sum>=v) {
			cout<<abs(diff);
			return 0;
		}
		sum=sum+num[i].a+num[i].b;
		diff+=num[i].c;
	}
	cout<<"-1";
	return 0;
} 
