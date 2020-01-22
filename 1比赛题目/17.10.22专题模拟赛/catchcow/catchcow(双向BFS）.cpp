#include<iostream>
#include<cstring>
#define maxn 100005
using namespace std;
int n,k;
int head1,tail1,head2,tail2;
struct node1{
	int num;
	int step;
}queue1[maxn];
struct node2{
	int num;
	int step;
}queue2[maxn];
int s[maxn];//标记走到那个点时人的坐标 
int walk1[maxn],walk2[maxn];
void bfs(){
	head1=0;
	tail1=1;
	walk1[n]=0;
	queue1[tail1].num=n;
	queue1[tail1].step=0;
	head2=0;
	tail2=1;
	walk2[n]=0;
	queue2[tail2].num=n;
	queue2[tail2].step=0;
	int now_n1,now_s1;
	int now_n2,now_s2;
	while(head1<tail1&&head2<tail2){  
	    head1++;
        now_n1=queue1[head1].num;
	    now_s1=queue1[head1].step;
	    head2++;
        now_n2=queue2[head2].num;
	    now_s2=queue2[head2].step;
	    if(walk1[now_n1]!=-1){
	    	cout<<now_s2+walk1[now_n1];
	    	return;
		}
	    if(walk2[now_n2]!=-1){
	    	cout<<now_s1+walk2[now_n2];
	    	return;
		}
        if (now_n1+1<=maxn&&walk1[now_n1+1]==-1) {
	         walk1[now_n1+1]=now_s1+1;
	         tail1++;
			 queue1[tail1].num=now_n1+1;
			 queue1[tail1].step=now_s1+1;  
	    }
        if (now_n1-1>=0&&walk1[now_n1-1]==-1) {
       	     walk1[now_n1+1]=now_s1+1;
	         tail1++;
			 queue1[tail1].num=now_n1-1;
			 queue1[tail1].step=now_s1+1;  
	    } 
        if (now_n1*2<=maxn&&walk1[now_n1*2]==-1){
       	    walk1[now_n1+1]=now_s1+1;
	        tail1++;
			queue1[tail1].num=now_n1*2;
			queue1[tail1].step=now_s1+1;  
	    }
	    if (now_n2+1<=maxn&&walk2[now_n2+1]==-1) {
	         walk2[now_n2+1]=now_s2+1;
	         tail2++;
			 queue2[tail2].num=now_n2+1;
			 queue2[tail2].step=now_s2+1;  
	    }
        if (now_n2-1>=0&&walk2[now_n2-1]==-1) {
       	     walk2[now_n2+1]=now_s2+1;
	         tail2;
			 queue2[tail2].num=now_n2-1;
			 queue2[tail2].step=now_s2+1;  
	    } 
        if (now_n2*2<=maxn&&walk2[now_n2*2]==-1){
       	    walk2[now_n1+1]=now_s2+1;
	        tail2++;
			queue2[tail2].num=now_n2*2;
			queue2[tail2].step=now_s2+1;  
	    }
    }
}
int main(){
	cin>>n>>k;
	memset(walk1,-1,sizeof(walk1));
	memset(walk2,-1,sizeof(walk2));
	bfs();
	return 0;
} 
