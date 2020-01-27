#include<iostream>
#include<cstring>
#define max 100
int s[max];
int q[max];
int i=0
using namespace std;
void push1(int k1) {

 s[i++]=k1;
}
void pop1() {
	for(int j=0; j<max; j++) {
		if(s[j]!=0) {
			s[j]=0;
			break;
		}
		cout<<"error";
	}
   return;
}
void push2(int k2){

	}
	return;
	
}
void pop2(){

}
int main(){
	memset(s,0,sizeof(s));
	push1(1);
	push1(2);
	pop1;
	return 0;
}
