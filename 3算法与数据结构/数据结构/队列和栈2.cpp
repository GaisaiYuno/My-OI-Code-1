#include<iostream>
#include<cstring>
#include<string.h>
#define max 101
int stack[max];
int queue[max];
string out[100];

bool flags [100];
bool flagq[100];


int top=0;
int head=0;tail=0;
void push_stack(int in1){
	if(top>max) cout<<"error";
	else stack[top++]=in1;
}
void pop_stack(int m){
	for(int i=0; i<m; i++) {
		if(top==0) cout<<"error";
		else top--;
	}
}
void push_queue(int in2) {
	if(tail-head==max) cout<<"error";
	else queue[tail++]=in2;
}
void pop_queue(int n) {
	for(int j=0; j<n; j++) {
		queue[head]=0;//可以不用 
		head++;
	}
}
int main(){
	int i, j;
	int m;
	cin >> m;
	for(i = 0; i < m; i++) {
		int n, num;
		char op[4];
		flags[i] = true;
		flagq[i] = true;

		cin >> n;
		for(j = 0; j < n; j++) {
			cin >> op;
			if(strcmp(op, "pop") == 0) {


			

			} else {
				cin >> num;
			
			}
		}


	}

	for(i = 0; i < m; i++) {
	

		

	}
	return 0;
}
	
} 
