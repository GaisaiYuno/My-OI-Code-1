//书p452 例3.7 
//堆排序（最小堆 ） 
#include<iostream>
#define maxn 1000
using namespace std; 
int heap[maxn];
int n,a;
void put(int x){
	int now,next;
    heap[++heap[0]]=x;
    now=heap[0];
    while(now>1){
    	next=now/2;//找父亲
		if(heap[now]>heap[next]) return;
		swap(heap[now],heap[next]);
		now=next;
	}
	return;
}
void preorder(int root){//先序遍历
    if(heap[root]){
    	cout<<heap[root]<<' ';
    	preorder(2*root);
    	preorder(2*root+1);
	}    
	return;
}
void inorder(int root){
	if(heap[root]){
		inorder(2*root);
		cout<<heap[root]<<' ';
		inorder(2*root+1);
	}
	return;
}
void postorder(int root){
	if(heap[root]){
		postorder(2*root);
		postorder(2*root+1);
		cout<<heap[root]<<' ';
	}
	return;
}
int del(){
	int now,next,num;
	num=heap[1];
	heap[1]=heap[heap[0]--];
	now=1;
	while(now*2<=heap[0]){
		next=now*2;
		if(next<heap[0]&&heap[next+1]<heap[next]) next++;
		if(heap[now]<=heap[next]) return num;
		swap(heap[now],heap[next]);
		now=next;
	}
	return num;
} 
void heapsort(){
	for(int i=1;i<=n;i++)
	    cout<<del()<<' ';
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		put(a);
	}
	for(int j=1;j<=n;j++) cout<<heap[j]<<' ';
    preorder(1); 
    cout<<endl;
    inorder(1);
    cout<<endl;
    postorder(1);
    cout<<endl;
    heapsort();
	return 0;
}
