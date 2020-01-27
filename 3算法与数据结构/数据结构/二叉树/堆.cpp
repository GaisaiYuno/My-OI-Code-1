//Âå¹È ¶Ñ£¨Ä£°å£©
#include<iostream>
#define maxn 1000005
using namespace std;
int heap[maxn];
void put(int x){
	int now,next;
    heap[++heap[0]]=x;
    now=heap[0];
    while(now>1){
    	next=now/2;//ÕÒ¸¸Ç×
		if(heap[now]>heap[next]) return;
		swap(heap[now],heap[next]) ;
		now=next;
	}
	return;
}
void del(){
	int now,next;//,num=0;
	//num=heap[1];
	heap[1]=heap[heap[0]--];
	now=1;
	while(now*2<=heap[0]){
		next=now*2;
		if(next<heap[0]&&heap[next+1]<heap[next]) next++;
		if(heap[now]<=heap[next]) break;//return num;
		swap(heap[now],heap[next]);
		now=next;
	}
	//return num;
} 
int main(){
	int a,n,d;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
	    if(a==1){
	    	cin>>d;
	    	put(d);
		} 
		if(a==2){
		   	cout<<heap[1]<<endl;	
		}
		if(a==3){
			del();
		}
	}
	return 0;
} 
