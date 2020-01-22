#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 10005
#define maxheap 2*maxn+1
using namespace std;
int fruit[maxn];
int heap[maxheap];
int size=0;
int n,ans;
void insert(int x){
	heap[++size]=x;
	int now=size,nex;
	while(now>1){
		nex=now/2;
		if(heap[nex]<heap[now]) return;
		swap(heap[now],heap[nex]);
		now=nex;
	}
	return;
}
int del(){
	if(size==0) return 0;
	int now,nex;
	int x;
	x=heap[1];
	heap[1]=heap[size--];
	now=1;
	while(now*2<=size){
		nex=now*2;
		if(nex<size&&heap[nex+1]<heap[nex]) nex++;
		if(heap[now]<=heap[nex]) return x;
		swap(heap[now],heap[nex]);
		now=nex;
	}
	return x;
}
int main(){
	//freopen("fruit.in","r",stdin);
	//freopen("fruit.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>fruit[i];
	    insert(fruit[i]);
    }
	for(int i=1;i<n;i++){
		int t1=del();
		int t2=del();
		insert(t1+t2);
		ans=ans+t1+t2;
	}
	cout<<ans;
	return 0;
}
