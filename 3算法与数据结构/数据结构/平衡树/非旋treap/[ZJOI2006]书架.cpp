//https://www.luogu.org/problem/P2596
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define maxn 80000
using namespace std;
int n,m;
int a[maxn+5];
struct fhq_treap{
#define lson(x) (tree[x].ls) 
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int val;
		int dat;
		int fa;
		int sz;
	}tree[maxn+5];
	int hash_val[maxn+5];
	int ptr=0;
	int root;
	int New(int val){
		ptr++;
		tree[ptr].ls=tree[ptr].rs=tree[ptr].fa=0;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		tree[ptr].sz=1;
		hash_val[val]=ptr;
		return ptr;
	}
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
		if(lson(x)) tree[lson(x)].fa=x;
		if(rson(x)) tree[rson(x)].fa=x;
	}
	int merge(int x,int y){
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
		if(k<=tree[lson(now)].sz){
			y=now;
			split(tree[now].ls,k,x,tree[y].ls);
		}else{
			x=now;
			split(tree[now].rs,k-tree[lson(now)].sz-1,tree[x].rs,y);
		}
		push_up(now);
	}
	int get_rank(int x){
		int ans=0;
		ans+=tree[lson(x)].sz+1;
		while(x){
			if(tree[x].fa==0) break; 
			else if(tree[tree[x].fa].ls==x){
				x=tree[x].fa;
			}else{
				ans+=tree[lson(tree[x].fa)].sz+1;
				x=tree[x].fa; 
			}
		}
		return ans;
	}
	int get_val(int k){
		int x=root;
		while(1){
//			printf("%d\n",x);
			if(k<=tree[lson(x)].sz) x=lson(x);
			else if(k<=tree[lson(x)].sz+1) return tree[x].val;
			else{
				k-=tree[lson(x)].sz+1;
				x=rson(x);
			}
		}
		return -1;
	}
	void insert(int pos,int val){
		int x,y;
		split(root,pos-1,x,y);
		root=merge(merge(x,New(val)),y);
	}
}T; 

char cmd[10];
int main(){
	int s,t;
	int k;
	int x,y,z,u;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		T.insert(i,a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='T'){
			scanf("%d",&s);
			k=T.get_rank(T.hash_val[s]);
			T.split(T.root,k,y,z);
			T.split(y,k-1,x,y);
			T.root=T.merge(y,T.merge(x,z));
		}else if(cmd[0]=='B'){
			scanf("%d",&s);
			k=T.get_rank(T.hash_val[s]);
			T.split(T.root,k,y,z);
			T.split(y,k-1,x,y);
			T.root=T.merge(T.merge(x,z),y);
		}else if(cmd[0]=='I'){
			scanf("%d %d",&s,&t);
			k=T.get_rank(T.hash_val[s]);
			if(t==1){
				T.split(T.root,k+1,z,u);
				T.split(z,k,y,z);
				T.split(y,k-1,x,y);
//				T.root=T.merge(T.merge(x,z),T.merge(y,u)); 
				T.root=T.merge(x,T.merge(z,T.merge(y,u)));
			}else if(t==-1){
				T.split(T.root,k,z,u);
				T.split(z,k-1,y,z);
				T.split(y,k-2,x,y);
				T.root=T.merge(x,T.merge(z,T.merge(y,u)));
			}
		}else if(cmd[0]=='A'){
			scanf("%d",&s);
			k=T.get_rank(T.hash_val[s]);
			printf("%d\n",k-1);
		}else{
			scanf("%d",&s);
			printf("%d\n",T.get_val(s));
		}
	}
}

