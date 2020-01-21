//https://www.luogu.org/problemnew/show/P1486 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
int n,lim;
struct fhq_treap{
	struct node{
		int ls;
		int rs;
		int val;
		int dat;
		int sz;
		int cnt;
	}tree[maxn+5];
	int ptr;
	int xx,yy;
	int root;
	void push_up(int x){
		tree[x].sz=tree[tree[x].ls].sz+tree[tree[x].rs].sz+tree[x].cnt;
	}
	int merge(int x,int y){//val[x]<=val[y] 
		if(x==0||y==0) return x+y;
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
	void split(int now,int k,int &x,int &y){//把值<=k的分出来 
		if(now==0){
			x=y=0;
			return;
		}else{
			if(k>=tree[now].val){
				x=now;
				split(tree[now].rs,k,tree[x].rs,y);
			}else{
				y=now;
				split(tree[now].ls,k,x,tree[now].ls);		
			}
			push_up(now);
		}
	} 
	
	int get_kth(int k){
		int x=root;
		while(1){
			if(k<=tree[tree[x].ls].sz) x=tree[x].ls;
			else if(k<=tree[tree[x].ls].sz+tree[x].cnt) return tree[x].val;
			else{
				k-=tree[tree[x].ls].sz+tree[x].cnt;
				x=tree[x].rs;
			}
		}
		return 0;
	} 
	int New(int val){
		ptr++;
		tree[ptr].sz=tree[ptr].cnt=1;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		return ptr;
	}
	
	void insert(int val){
		split(root,val,xx,yy);
		root=merge(xx,merge(New(val),yy));
	}
	
	int del(int val){
		split(root,val,xx,yy);
		root=yy;
		return tree[xx].sz;
	}
}T;

int delta;
char cmd[2];
int main(){
	int x;
	int ans=0;
	scanf("%d %d",&n,&lim);
	for(int i=1;i<=n;i++){
		scanf("%s %d",cmd,&x);
		if(cmd[0]=='I'){
			if(x>=lim){
				x-=delta;
				T.insert(x);
			} 
		}else if(cmd[0]=='A'){
			delta+=x;
		}else if(cmd[0]=='S'){
			delta-=x;
			ans+=T.del(lim-delta-1);
		}else if(cmd[0]=='F'){
			int all=T.tree[T.root].sz;
			if(x>all) printf("-1\n");
			else printf("%d\n",T.get_kth(all-x+1)+delta);
		}
	}
	printf("%d\n",ans);
} 
