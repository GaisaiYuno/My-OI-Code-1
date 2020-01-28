#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 200005
using namespace std;
int n,m;
int v[maxn];
struct bi_link{
	int pre;
	int nex;
	int v;
}list[maxn];
void del(int x){
	list[list[x].pre].nex=list[x].nex;
	list[list[x].nex].pre=list[x].pre;
	list[x].pre=0;
	list[x].nex=0;
}
struct node{
	int x;
	int id;
	node(){
		
	}
	node(int v,int i){
		x=v;
		id=i;
	}
	friend bool operator < (node a,node b){
		return a.x<b.x;
	}
};
priority_queue<node>heap;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	if(m>n/2){
		printf("Error!");
		return 0;
	}
	for(int i=1;i<=n;i++){
		list[i].nex=i+1;
		list[i].pre=i-1;
	}
	list[1].pre=n;
	list[n].nex=1;
	for(int i=1;i<=n;i++){
		heap.push(node(v[i],i));
	}
	int ans=0;
	node now;
	for(int i=1;i<=m;i++){
		while(list[heap.top().id].nex==0) heap.pop();
		now=heap.top();
		heap.pop();
		ans+=now.x;
		v[now.id]=v[list[now.id].nex]+v[list[now.id].pre]-v[now.id]; 
		del(list[now.id].pre);
		del(list[now.id].nex);
		heap.push(node(v[now.id],now.id));
	}
	printf("%d\n",ans);
}
