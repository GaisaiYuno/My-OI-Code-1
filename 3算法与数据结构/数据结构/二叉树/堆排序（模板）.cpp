//��p452 ��3.7 
//��������С�� �� 
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
    	next=now/2;//�Ҹ���
		if(heap[now]>heap[next]) return;
		swap(heap[now],heap[next]);
		now=next;
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
	heapsort();
//	cout<<del();
	return 0;
}
/* ������ 
����Ѳ��� 
   1. x-->a[a[0]]
   2.���� a[0]/2
   3.�жϴ�С������
   
   �����ɾ��
   1.���ڵ���β���ڵ㽻��
   2���ں������ұ�x��ģ�����
   3.�³�   
*/

 
