#include<iostream>
#include<cstring>
#define max 50
using namespace std;
int q[max];
int tail=0;
int head=0;
void push(int in) {
	if(tail-head==max) cout<<"error";
	else q[tail++]=in;
}
void pop(int n) {
	for(int i=0; i<n; i++) {
		q[head]=0;//���Բ��� 
		head++;
	}
}

int main() {
	int input;
	int a,b,N;
	memset(q,0,sizeof(q));
	cin>>N;
	for(int j=0; j<N; j++) {
		cin>>a;
		if(a==1) {
			cin>>input;
			push(input);//1����input
		}
		if(a==2) {
			cin>>b;
			pop(b);//2���� b��
		}
	}
	for(int i=head; i<tail; i++) {
		cout<<q[i]<<' ';
	}
	return 0;
}
