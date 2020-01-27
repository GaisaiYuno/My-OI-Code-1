#include<iostream>
#include<cstdio>
using namespace std;
inline int fastpow(int x,int y,int k){
	int t=x;
	y-=1;
	while(y>0){
		if(y%2==1){
			x=(int)((long long)x%k*t%k);
			x%=k;
		}
		t=(int)((long long)t%k*t%k);
		t%=k;
		y/=2;
	}
	return x%k;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int b,n,k;
	cin>>b>>n>>k;
	cout<<fastpow(b,n,k)<<endl;
	return 0;
} 
