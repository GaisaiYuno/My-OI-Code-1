#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int a;
	int n=0;
input:
	cout<<"ÇëÊäÈë±¶Êý(1~10):" ;
	cin>>a;

	for(int i=0; i<10; i++) {
		for(int k=0; k<10; k++) {
			for(int j=0; j<10; j++) {
				if((i*100+k*10+j)%a==0) {
					cout<<i<<k<<j<<'\n';
					n=n+1;
					if(n=1000) break;
				}
			}

		}
	}
	goto input;
}
