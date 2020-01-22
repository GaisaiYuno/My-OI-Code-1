#include<iostream>
#define maxn 100005
using namespace std;
int n,k;
int head,tail;
struct node{
	int num;
	int step;
}queue[maxn];
bool used[maxn];
void bfs(){
	head=0;
	tail=1;
	used[n]=true;
	queue[tail].num=n;
	queue[tail].step=0;
	int now_n,now_s;
	while(head<tail){  
	    head++;
        now_n=queue[head].num;
	    now_s=queue[head].step;
        if (now_n==k) {
	       cout<<now_s;
		   return; 
	    }  
        if (now_n+1<=maxn&&used[now_n+1]==0) {
	         used[now_n+1]=true;
	         tail++;
			 queue[tail].num=now_n+1;
			 queue[tail].step=now_s+1;  
	    }
        if (now_n-1>=0&&used[now_n-1]==0) {
       	     used[now_n-1]=true;
	         tail++;
			 queue[tail].num=now_n-1;
			 queue[tail].step=now_s+1;  
	    } 
        if (now_n*2<=maxn&&used[now_n*2]==0){
       	    used[now_n*2]=true;
	        tail++;
			queue[tail].num=now_n*2;
			queue[tail].step=now_s+1;  
	    }
//		for(int i=head;i<=tail;i++) cout<<queue[i].num<<' ';
//		cout<<endl;
    }
}
int main(){
	cin>>n>>k;
	bfs();
	return 0;
} 
