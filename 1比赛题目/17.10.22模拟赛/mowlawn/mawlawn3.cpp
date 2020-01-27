//��� �޼���ƺ O(n*k)
#include<iostream>
#include<cstdio>
#define maxn 100005
long long e[maxn],f[maxn],heap[maxn];
long long n,k,total;
using namespace std;
inline long long read(){
	long long x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
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
int main(){
	freopen("mowlawn.8.in","r",stdin);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		e[i]=read();
		total+=e[i];
	}
	long long tmp;
	for(int i=k+1;i<=n;i++){
		tmp=0xffffffff;
		for(int j=i-k;j<=i;j++){
			if(tmp>f[j-1]+e[j]) tmp=f[j-1]+e[j];
			//tmp=min(tmp,f[j-1]+e[j]);
		}
		f[i]=tmp;
	}
	cout<<total-f[n];
}
/*
״̬ת�Ʒ���(1) 
    f[i]=min{f[j-1]+i~jЧ��֮��,f[i]}   j��[i-k,i]
״̬ת�Ʒ���(2) 
  �������Ч�� 
  ����iֻţ��СЧ��,������kֻ���� 
  f[i]=min{f[j-1]+e[j],f[i]}   j��[i-k,i] 
  ����Ч�ʼ�ȥ��СЧ�ʾ��ܵõ����Ч�ʣ���ֱ�������Ч�ʿ� 
*/ 
