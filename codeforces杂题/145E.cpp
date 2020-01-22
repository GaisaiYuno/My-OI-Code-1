#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005 
using namespace std;
int n,m;
int a[maxn];
char s[maxn];
struct node{
	int l;
	int r;
	int mark;
	int cnt4;
	int cnt7;
	int uplen;
	int dwlen;
	int len(){
		return r-l+1;
	}
	void reverse(){
		swap(uplen,dwlen);
		swap(cnt4,cnt7);
	}
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].cnt4=tree[pos<<1].cnt4+tree[pos<<1|1].cnt4;
	tree[pos].cnt7=tree[pos<<1].cnt7+tree[pos<<1|1].cnt7;
	tree[pos].uplen=max(
		max(tree[pos<<1].cnt4+tree[pos<<1|1].uplen,tree[pos<<1].uplen+tree[pos<<1|1].cnt7),
		max(tree[pos].cnt4,tree[pos].cnt7)
    );
    tree[pos].dwlen=max(
		max(tree[pos<<1].cnt7+tree[pos<<1|1].dwlen,tree[pos<<1].dwlen+tree[pos<<1|1].cnt4),
		max(tree[pos].cnt4,tree[pos].cnt7)
    );
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=-1;
	if(l==r){
		if(a[l]==4) tree[pos].cnt4=1;
		else tree[pos].cnt7=1;
		tree[pos].uplen=tree[pos].dwlen=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void push_down(int pos){
	if(tree[pos].mark!=-1){
		if(tree[pos<<1].mark==-1)tree[pos<<1].mark=tree[pos].mark;
		else{
			tree[pos<<1].mark^=tree[pos].mark;
			tree[pos<<1].reverse();
		}
		if(tree[pos<<1|1].mark==-1)tree[pos<<1|1].mark=tree[pos].mark;
		else{
			tree[pos<<1|1].mark^=tree[pos].mark;
			tree[pos<<1|1].reverse();
		}
		tree[pos].mark=-1;
	}
}
void update(int L,int R,int is_swi,int pos){
	int l=tree[pos].l,r=tree[pos].r;
	if(L<=l&&R>=r){
		if(tree[pos].mark==-1)tree[pos].mark=is_swi;
		else tree[pos].mark^=1;
		tree[pos].reverse();
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,is_swi,pos<<1);
	if(R>mid) update(L,R,is_swi,pos<<1|1);
	push_up(pos);
}
int query(int L,int R,int pos){
	int l=tree[pos].l,r=tree[pos].r;
	if(L<=l&&R>=r){
		return tree[pos].uplen;	
    }
    push_down(pos);
    int mid=(l+r)>>1;
    int q1,q2; 
    if(L<=mid) q1=query(L,R,pos<<1);
	if(R>mid) q2=query(L,R,pos<<1|1); 
	return max(
		max(tree[pos<<1].cnt4+q2,q1+tree[pos<<1|1].cnt7),
		max(tree[pos].cnt4,tree[pos].cnt7)
    );
}
int main(){
	char cmd[20];
	int l,r;
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
	}
	build(1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='c'){
			printf("%d\n",query(1,n,1));
		}else{
			scanf("%d %d",&l,&r);
			update(l,r,1,1);
		}
	}
} 
/*
8 9
74777477
count
switch 7 7
switch 7 8
switch 4 8
switch 4 7
count
switch 4 8
count
*/
