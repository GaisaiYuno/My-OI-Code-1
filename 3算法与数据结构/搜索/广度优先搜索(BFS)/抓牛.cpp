//Êép310 Ìâ6 
#include<iostream>
#define max 100001
int a[max];
int step[max];
int p[max];
int used[max]={-1};
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int head,tail;
	int x;
	int temp;
	//int dist=abs(n-k);
	p[head]=n;
	step[n]=0;
	head=0;
	tail=1;
	used[n]=1;
	do{
		if(p[head]==k) {
			cout<<step[p[head]];
			break;
		}
		x=p[head];
		if(2*x<max && step[2*x]==0 && 2*x!=n){
			tail++;
			p[tail]=2*x;
			step[p[tail]]=step[p[head]]+1;
		}
		if(x-1>=0 && step[x-1]==0 && x-1!=n){
			tail++;
			p[tail]=x-1;
			step[p[tail]]=step[p[head]]+1;
		}
		if(x+1<max && step[x+1]==0 && x+1!=n){
		    tail++; 
			p[tail]=x+1;
			step[p[tail]]=step[p[head]]+1;
			
		}
		head++;
	}while(head<=tail);
	
	return 0;
}
