#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib> 
#define maxn 500000
using namespace std;


struct mem_pool{
	int top;
	int stk[maxn+5];
	int New(){
		return stk[top--];	
	}
	void Del(int x){
		stk[++top]=x;
	}
	void ini(int n){
		top=n;
		for(int i=1;i<=n;i++) stk[n-i+1]=i;
	}
}pool;

struct fhq_treap{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs) 
//protected:
	struct node{
		int ls;
		int rs;
		int sz;
		int dat;
		int val;
		int minv;
		int addm;
		bool revm;
	}tree[maxn+5];
	int root;
	int cnt;
	int New(int val){
		int ptr=++cnt;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].sz=1;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		tree[ptr].minv=val;
		tree[ptr].addm=0;
		tree[ptr].revm=0;
		return ptr;
	}
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
		tree[x].minv=tree[x].val;
		if(lson(x)) tree[x].minv=min(tree[x].minv,tree[lson(x)].minv);
		if(rson(x)) tree[x].minv=min(tree[x].minv,tree[rson(x)].minv);
	}
	void reverse(int x){
		swap(tree[x].ls,tree[x].rs); 
		tree[x].revm^=1;
	}
	void add_val(int x,int val){
		tree[x].val+=val;
		tree[x].minv+=val;
		tree[x].addm+=val;
	}
	void push_down(int x){
		if(tree[x].revm){
			reverse(lson(x));
			reverse(rson(x));
			tree[x].revm=0;
		}
		if(tree[x].addm){
			add_val(lson(x),tree[x].addm);
			add_val(rson(x),tree[x].addm);
			tree[x].addm=0;
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
		if(k<=tree[lson(now)].sz){
			y=now;
			split(lson(now),k,x,lson(y));
		}else{
			x=now;
			split(rson(now),k-tree[lson(now)].sz-1,rson(x),y);
		}
		push_up(now);
	}
	void Add(int l,int r,int val){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y);
		add_val(y,val);
		root=merge(merge(x,y),z);
	}
	void Reverse(int l,int r){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y);
		reverse(y);
		root=merge(merge(x,y),z);
	}
	void Revolve(int l,int r,int t){
		int x,y,z,u;
		split(root,r,y,z);
		split(y,l-1,x,y);
		split(y,(r-l+1)-t,u,y);
//		reverse(y);
		root=merge(merge(x,u),merge(y,z));
	}
	void Insert(int pos,int val){
		int x,y;
		split(root,pos,x,y);
		root=merge(merge(x,New(val)),y);
	} 
	void Delete(int pos){
		int x,y,z;
		split(root,pos,y,z);
		split(y,pos-1,x,y);
		pool.Del(y);
		root=merge(x,z);
		
	}
	int Get_min(int l,int r){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y);
		int ans=tree[y].minv;
		root=merge(merge(x,y),z);
		return ans;
	}
	void Push_back(int val){
		root=merge(root,New(val)); 
	}
	void print(int x){
		push_down(x);
		if(lson(x)) print(lson(x));
		printf("%d ",tree[x].val);
		if(rson(x)) print(rson(x));
	}
	void Print(){
		print(root);
		printf("\n");
	} 
#undef lson
#undef rson
}T;

int n,m;
int a[maxn+5];
int main(){
	char cmd[10];
	int l,r,c;
	pool.ini(maxn);
	scanf("%d",&n);
//	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		T.Push_back(a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='A'){
			scanf("%d %d %d",&l,&r,&c);
			T.Add(l,r,c);
		}else if(cmd[0]=='R'&&cmd[3]=='E'){
			scanf("%d %d",&l,&r);
			T.Reverse(l,r);
		}else if(cmd[0]=='R'&&cmd[3]=='O'){
			scanf("%d %d %d",&l,&r,&c);
			c%=(r-l+1);
			T.Revolve(l,r,c);
		}else if(cmd[0]=='I'){
			scanf("%d %d",&l,&c);
			T.Insert(l,c);
		}else if(cmd[0]=='D'){
			scanf("%d",&l);
			T.Delete(l);
		}else{
			scanf("%d %d",&l,&r);
			printf("%d\n",T.Get_min(l,r));
		}
//		T.Print();
	}
	
}
