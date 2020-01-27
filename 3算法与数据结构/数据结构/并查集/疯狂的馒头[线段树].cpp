#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
using namespace std;
inline void qread(int& x) {
    x=0;
    char c=getchar();
    int sign=1;
    while(c<'0'||c>'9') {
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
    x*=sign;
}
inline void qprint(int x) {
    if(x<0) {
        putchar('-');
        qprint(-x);
    } else if(x==0) {
        putchar('0');
        return;
    } else {
        if(x/10>0) qprint(x/10);
        putchar('0'+x%10);
    }
}

struct node{
    int l;
    int r;
    int mark;
    int flg;
    int len(){
        return r-l+1;
    }
}tree[(maxn<<2)+5];
void push_up(int pos){
	tree[pos].flg=tree[pos<<1].flg&tree[pos<<1|1].flg;
}
void build(int l,int r,int pos){
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].mark=0;
    tree[pos].flg=0;
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1); 
    push_up(pos);
} 

void update(int L,int R,int v,int pos){//暴力更新，如果更新过了就返回 
	if(tree[pos].flg==1) return;
	if(tree[pos].l==tree[pos].r){
		tree[pos].mark=v;
		tree[pos].flg=1;
		return;
	}
//	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
} 

void print(int pos){
	if(tree[pos].l==tree[pos].r){
		qprint(tree[pos].mark);
		putchar('\n');
		return;
	}
	print(pos<<1);
	print(pos<<1|1); 
}

int n,m,p,q;
int main(){
	qread(n);
	qread(m);
	qread(p);
	qread(q);
	build(1,n,1);
	for(int i=m; i>=1;i--){//倒序覆盖，这样之后的就不会被之前的覆盖 
		int l=(i*p+q)%n+1;
		int r=(i*q+p)%n+1;
		if(l>r) swap(l,r);
		update(l,r,i,1);
	}
	print(1);
} 
