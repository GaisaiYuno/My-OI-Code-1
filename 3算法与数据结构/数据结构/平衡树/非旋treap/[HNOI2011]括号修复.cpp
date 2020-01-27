//https://www.luogu.com.cn/problem/P3215
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define maxn 100000
using namespace std;
int n,m;
char a[maxn+5];

struct fhq_treap{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int sz;
		int val;
		int sum;
		int dat;
		int lmax;
		int lmin;
		int rmax;
		int rmin;
		bool revm;//区间翻转 
		bool invm;//区间*-1
		int setm;//区间赋值 
	}tree[maxn+5];
	int ptr;
	int root;
	int New(int val){
		ptr++;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].sz=1;
		tree[ptr].val=val;
		tree[ptr].sum=val;
		tree[ptr].dat=rand();
		tree[ptr].lmax=tree[ptr].rmax=max(0,tree[ptr].val);//不是0
		tree[ptr].lmin=tree[ptr].rmin=min(0,tree[ptr].val); 
		tree[ptr].revm=0;
		tree[ptr].invm=0;
		tree[ptr].setm=0; 
		return ptr;
	}
	inline void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
		tree[x].sum=tree[lson(x)].sum+tree[rson(x)].sum+tree[x].val;
		tree[x].lmax=max(tree[lson(x)].lmax,tree[lson(x)].sum+tree[x].val+tree[rson(x)].lmax);
		tree[x].lmin=min(tree[lson(x)].lmin,tree[lson(x)].sum+tree[x].val+tree[rson(x)].lmin);
		tree[x].rmax=max(tree[rson(x)].rmax,tree[rson(x)].sum+tree[x].val+tree[lson(x)].rmax);
		tree[x].rmin=min(tree[rson(x)].rmin,tree[rson(x)].sum+tree[x].val+tree[lson(x)].rmin);
	}
	inline void reverse(int x){
		tree[x].revm^=1;
		swap(lson(x),rson(x));
		swap(tree[x].lmax,tree[x].rmax);
		swap(tree[x].lmin,tree[x].rmin); 
	}
	inline void invert(int x){
		tree[x].invm^=1;
		tree[x].val*=-1;
		tree[x].sum*=-1;
		tree[x].lmax*=-1;
		tree[x].lmin*=-1;
		tree[x].rmin*=-1;
		tree[x].rmax*=-1;
		swap(tree[x].lmax,tree[x].lmin);
		swap(tree[x].rmax,tree[x].rmin);
		tree[x].setm*=-1;//覆盖标记也要*-1
	}
	inline void setval(int x,int val){
		tree[x].val=val;
		tree[x].sum=val*tree[x].sz;
		tree[x].lmax=max(0,tree[x].sum);
		tree[x].lmin=min(0,tree[x].sum);
		tree[x].rmax=max(0,tree[x].sum);
		tree[x].rmin=min(0,tree[x].sum);
		tree[x].setm=val;
	}
	void push_down(int x){
		//优先级:区间*-1>区间覆盖>区间反转 
		if(tree[x].invm){
			if(lson(x)) invert(lson(x));
			if(rson(x)) invert(rson(x));
			tree[x].invm=0;
		}
		if(tree[x].setm){
			if(lson(x)) setval(lson(x),tree[x].setm);
			if(rson(x)) setval(rson(x),tree[x].setm);
			tree[x].setm=0;
		}
		if(tree[x].revm){
			if(lson(x)) reverse(lson(x));
			if(rson(x)) reverse(rson(x));
			tree[x].revm=0;
		}
	}
	int merge(int x,int y){
		push_down(x);
		push_down(y);
		if(!x||!y) return x+y;
		if(tree[x].dat<tree[y].dat){
			tree[x].rs=merge(tree[x].rs,y);
			push_up(x);
			return x;
		}else{
			tree[y].ls=merge(x,tree[y].ls);
			push_up(y);
			return y;
		}
	}
	void split(int now,int k,int &x,int &y){
		if(now==0){
			x=y=0;
			return;
		}
		push_down(now);
		if(k<=tree[lson(now)].sz){//小心lson(now)不要写成lson(x) 
			y=now;
			split(lson(now),k,x,tree[y].ls);
		}else{
			x=now;
			split(rson(now),k-tree[lson(now)].sz-1,tree[x].rs,y);
		}
		push_up(now);
	}
	void Replace(int l,int r,char c){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y); 
		if(c=='(') setval(y,-1);
		else setval(y,1);
		root=merge(merge(x,y),z); 
	}
	void Push_back(char c){
		root=merge(root,New(c=='('?-1:1));
	}
	void Swap(int l,int r){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y);
		reverse(y);
		root=merge(merge(x,y),z); 
	}
	void Invert(int l,int r){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y);
		invert(y);
		root=merge(merge(x,y),z); 
	}
	int query(int l,int r){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y);
		int pre_max=tree[y].lmax;
		int suf_min=tree[y].rmin;
		root=merge(merge(x,y),z); 
		return (pre_max+1)/2+(abs(suf_min)+1)/2;
	}
#undef lson
#undef rson
}T;

int main(){
	char cmd[10],x[2];
	int l,r;
	scanf("%d %d",&n,&m);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++) T.Push_back(a[i]); 
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='R'){
			scanf("%d %d %s",&l,&r,x);
			T.Replace(l,r,x[0]);
		}else if(cmd[0]=='I'){
			scanf("%d %d",&l,&r);
			T.Invert(l,r);
		}else if(cmd[0]=='S'){
			scanf("%d %d",&l,&r);
			T.Swap(l,r);
		}else{
			scanf("%d %d",&l,&r);
			printf("%d\n",T.query(l,r));
		}
	}
}

