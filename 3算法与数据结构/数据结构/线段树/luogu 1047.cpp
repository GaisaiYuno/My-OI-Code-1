#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10005
using namespace std;
struct node{
	int l,r;
	int value;
	int mark;
	int len(){
		return r-l+1;
	}
}tree[maxn*4];
void push_up(int pos){
	tree[pos].value=tree[pos*2].value+tree[pos*2+1].value;
}
void push_down(int pos){
	if(tree[pos].mark!=0){
	    tree[pos*2].mark=tree[pos*2+1].mark=tree[pos].mark;
	    tree[pos*2].value=tree[pos].mark*tree[pos*2].len();
		tree[pos*2+1].value=tree[pos].mark*tree[pos*2+1].len();
	    tree[pos].mark=0;
	}
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=0;
	tree[pos].value=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
}
void update_section(int to_l,int to_r,int value,int pos){
	if(to_l<=tree[pos].l&&tree[pos].r<=to_r){
		tree[pos].mark=value;
		tree[pos].value=tree[pos].len()*value;
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)/2;
	if(to_l<=mid) update_section(to_l,to_r,value,pos*2);
	if(to_r>mid) update_section(to_l,to_r,value,pos*2+1);
	push_up(pos);
}
int query(int to_l,int to_r,int pos){
	if(to_l<=tree[pos].l&&tree[pos].r<=to_r){
		return tree[pos].value;
	}
	int ans=0; 
	int mid=(tree[pos].l+tree[pos].r)/2;
	if(to_l<=mid) ans+=query(to_l,to_r,pos*2);                        
    if(to_r>mid) ans+=query(to_l,to_r,pos*2+1);
    return ans;
}
int l,m,s,t;
int main(){
	cin>>l>>m;
	build(0,l,1);
	for(int i=1;i<=m;i++){
		cin>>s>>t;
		update_section(s,t,1,1);
	}
	cout<<l-query(0,l,1)+1<<endl;
}
