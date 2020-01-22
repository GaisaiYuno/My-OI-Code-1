#include<iostream>
#include<cstdio>
#include<vector>
#include<utility> 
#include<algorithm> 
using namespace std;
int n;
struct node{
	int f;
	int s;
	int id;
	node(){
		
	}
	node(int x,int y,int i){
		f=x;
		s=y;
		id=i;
	} 
}; 
vector< node > a,b;
bool cmp1(node a,node b){
	if(a.f==b.f) return a.s<b.s;
	else return a.f<b.f;
}
bool cmp2(node a,node b){
	if(a.f==b.f) return a.s>b.s;
	else return a.f>b.f;
}
int main(){
	int x,y; 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		if(x<y) a.push_back(node(x,y,i));
		else b.push_back(node(x,y,i)); 
	}
	if(a.size()>b.size()){
		printf("%d\n",a.size()); 
		sort(a.begin(),a.end(),cmp2);
		for(node p : a) printf("%d ",p.id); 
	}else{
		printf("%d\n",b.size()); 
		sort(b.begin(),b.end(),cmp1);
		for(node p : b) printf("%d ",p.id); 
	} 
}

