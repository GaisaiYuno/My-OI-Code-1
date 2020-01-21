#include<iostream>
#include<cstdio>
#define MAX 100002
#define INF 99999999999999
using namespace std;
struct node {
	long long value;
	long long index;
} heap[MAX];
long long heap_cp[MAX];
long long heap_tail=0;
long long dp[MAX],data[MAX];
inline int read() {
	int x=0,sign=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')sign=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*sign;
}
void heap_insert(int i) {
	heap_tail++;
	heap[i].index=heap_tail;
	heap[i].value=dp[i-1]+data[i];
	heap_cp[heap[i].index]=i;
	//上浮 
	while(heap[i].index!=1) {
		if(heap[heap_cp[heap[i].index/2]].value<heap[i].value) break;
		swap(heap_cp[heap[i].index/2],heap_cp[heap[i].index]);
		swap(heap[heap_cp[heap[i].index]].index,heap[i].index);//不能先交换heap[i].index,否则heap[i].index被改变，无法改变value
	}
}
void heap_delete(int i) {
	int j=heap_cp[heap_tail];
	swap(heap_cp[heap[i].index],heap_cp[heap_tail]);
	swap(heap[i].index,heap[heap_cp[heap[i].index]].index);
	heap_tail--;
	while(heap[j].index*2+1<=heap_tail) {
		int tmp;
		if(heap[heap[j].index*2].value<=heap[heap[j].index*2+1].value){
			tmp=heap_cp[heap[j].index*2];
		}
		else tmp=heap_cp[heap[j].index*2+1];
		if(heap[j].value<heap[tmp].value) break;
		swap(heap[j].index,heap[tmp].index);
        swap(heap_cp[heap[j].index],heap_cp[heap[tmp].index]);
	}
	//再次上浮 
	while(heap[j].index!=1){
        if(heap[heap_cp[heap[j].index/2]].value<=heap[j].value)break;
        swap(heap[heap_cp[heap[j].index]].index,heap[j].index);
        swap(heap_cp[heap[j].index/2],heap_cp[heap[j].index]);
    }
}
int main() {
	//freopen("mowlawn.2.in","r",stdin);
	long long n,k;
	long long min=INF;
	long long ans=0;
	n=read();
	k=read();
	for(int i=1; i<=n; i++) {
		data[i]=read();
		ans+=data[i];
	}
	for(int i=1; i<=n; i++) {
		heap_insert(i);
		if(i>k) {
			dp[i]=heap[heap_cp[1]].value;
			heap_delete(i-k);
		}
	}
	cout<<ans-dp[n]<<endl;
	return 0;
}
