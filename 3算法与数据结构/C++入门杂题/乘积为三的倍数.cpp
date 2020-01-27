#include<iostream>
using namespace std;
int main() {
	freopen("out3.txt","w",stdout);
	int i=0;
	for(i=0; i<10; i++) {
		for(int k=0; k<10; k++) {
			for(int j=0; j<10; j++) {
				if((i+k+j)%3==0) {
					cout<<i<<k<<j<<'\n';
					//freopen("out3.txt","w",stdout);
				}
			}

		}
	}
	//i=11;
}
