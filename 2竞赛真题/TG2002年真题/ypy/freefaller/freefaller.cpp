#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double h,s1,v,l,k;
int n;
const double eps=0.0001;//误差 
const double g=10;
int cnt=0;
int main(){
	//freopen("freefaller.in","r",stdin);
	//freopen("freefaller.out","w",stdout);
	cin>>h>>s1>>v>>l>>k>>n;
	double left=s1-v*sqrt(2*h/g);
	double right=s1-v*sqrt(2*(h-k)/g)+l;
	//落到车后方不能被接住，但落到车前方可以 
	for(int i=0;i<=n-1;i++){
		if(left-eps<i&&i<right+eps){
			cnt++;
		}
	} 
	cout<<cnt;
}

