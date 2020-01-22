#include<iostream>
#include<set>
using namespace std;
int n,x0,y0;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
struct frac{
	int x;
	int y;
	frac(int fm,int fz){
		x=fz;
		y=fm;
		x/=gcd(fz,fm);
		y/=gcd(fm,fz);
	}
};
bool operator < (frac a,frac b){
	return b.x==a.x?b.y<a.y:b.x<a.x;
}
set<frac>a;
int main(){
	cin>>n>>x0>>y0;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a.insert(frac(x-x0,y-y0));
	}
	cout<<a.size();
}
