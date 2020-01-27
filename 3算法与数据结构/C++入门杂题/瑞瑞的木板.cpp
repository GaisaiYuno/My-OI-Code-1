//洛谷 瑞瑞的木板 
#include<iostream>
#include<algorithm>
#define maxn 1000000
using namespace std;
long long int heap[maxn];
int n,a;
//一定要用小根堆！！！ 
void put(int x){
    int now,next;
    heap[++heap[0]]=x;
    now=heap[0];
    while(now>1){
        next=now/2;
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
    long long ans=0,left=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        put(a);
    } 
    for(int j=0;j<n-1;j++){
        int p=del()+del();
        put(p);
		ans+=p;
    }
    cout<<ans;
    return 0;
} 
