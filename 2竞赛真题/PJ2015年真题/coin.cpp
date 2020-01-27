//coin
#include<iostream>
#include<cstdio>
using namespace std;
int num,k,day;
int main() {
	freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
	cin>>k;
	num=0;
	for(int i=1;; i++) {
		for(int j=1; j<=i; j++) {
			day++;
			num+=i;
			if(day==k) {
               cout<<num;
               return 0;
			}
		}
	}
	return 0;
}
