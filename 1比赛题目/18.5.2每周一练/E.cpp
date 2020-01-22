#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
struct node {
	int l;
	int r;
	int mark;
	int v;
	int len() {
		return r-l+1;
	}
}tree[maxn<<2];
void push_up(int pos) {
	tree[pos].v=tree[pos<<1].v&tree[pos<<1|1].v;
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=0;
	tree[pos].v=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}
void push_down(int pos) {
	if(tree[pos].mark) {
		tree[pos<<1].mark|=tree[pos].mark;
		tree[pos<<1|1].mark|=tree[pos].mark;
		tree[pos<<1].v|=tree[pos].mark;
		tree[pos<<1|1].v|=tree[pos].mark;
		tree[pos].mark=0;
	}
}
void update(int L,int R,int v,int l,int r,int pos) {
	if(L<=l&&R>=r) {
		tree[pos].mark|=v;
		tree[pos].v|=v;
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,v,l,mid,pos<<1);
	if(R>mid) update(L,R,v,mid+1,r,pos<<1|1);
	push_up(pos);
}
int query(int L,int R,int l,int r,int pos){
	if(L<=l&&R>=r){
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	int ans=0;  
    if(R<=mid) ans+=query(L,R,l,mid,pos<<1);  
    else if(L>mid) ans+=query(L,R,mid+1,r,pos<<1|1);  
    else ans+=(query(L,R,l,mid,pos<<1)&query(L,R,mid+1,r,pos<<1|1));  
    push_up(pos);  
    return ans;  
}
void print_tree(int L,int R,int l,int r,int pos){
	if(l==r){
		printf("%d ",tree[pos].v); 
		return;
	}
	push_down(pos); 
	int mid=(l+r)>>1;
	if(L<=mid) print_tree(L,R,l,mid,pos<<1);
	if(R>mid) print_tree(L,R,mid+1,r,pos<<1|1); 
}
int n,m;
struct limit{
	int l;
	int r;
	int q;
}lim[maxn]; 
int main(){
	scanf("%d %d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&lim[i].l,&lim[i].r,&lim[i].q);
		update(lim[i].l,lim[i].r,lim[i].q,1,n,1);
	} 
	bool flag=true;
	for(int i=1;i<=m;i++){
		if(query(lim[i].l,lim[i].r,1,n,1)!=lim[i].q){
			flag=false;
			break;
		}
	}
	if(flag){
		 printf("YES\n");
		 print_tree(1,n,1,n,1); 
	}else{
		printf("NO\n");
	} 
}
