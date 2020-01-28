#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
long long z;
struct node{
	int id;
	int cost;
	int val;
	node(){
		
	}
	node(int d,int a,int i){
		cost=d;
		val=a;
		id=i;
	}
}cmin[maxn],cmax[maxn];
int sz1,sz2;
int cmp1(node x,node y){
	return x.cost<y.cost;
}
int cmp2(node x,node y){
	return x.val>y.val;
} 
int main(){
	scanf("%d %d",&n,&z);
	int u,v;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&u,&v);
		if(u<=v) cmin[++sz1]=node(u,v,i);
		else cmax[++sz2]=node(u,v,i);
	}
	sort(cmin+1,cmin+1+sz1,cmp1);
	for(int i=1;i<=sz1;i++){
		if(z<=cmin[i].cost){
			printf("NIE");
			return 0;
		}
		z-=cmin[i].cost;
		z+=cmin[i].val; 
	}
	sort(cmax+1,cmax+1+sz2,cmp2);
	for(int i=1;i<=sz2;i++){
		if(z<=cmax[i].cost){
			printf("NIE");
			return 0;
		}
		z-=cmax[i].cost;
		z+=cmax[i].val;
	}
	printf("TAK\n");
	for(int i=1;i<=sz1;i++){
		printf("%d ",cmin[i].id);
	}
	for(int i=1;i<=sz2;i++){
		printf("%d ",cmax[i].id);
	}
}
