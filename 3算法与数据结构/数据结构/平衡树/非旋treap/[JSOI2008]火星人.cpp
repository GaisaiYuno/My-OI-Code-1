// luogu-judger-enable-o2
//常数略大，开O2AC，待卡常 
//https://www.luogu.org/problem/P4036
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
#define prime 27
using namespace std;
typedef unsigned int ull;
ull p[maxn+5];
struct fhq_treap{
#define lson(x) (tree[x].ls) 
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int val;
		int dat;
		ull hs;
		int sz;
	}tree[maxn+5];
	int ptr=0;
	int root;
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
		tree[x].hs=tree[lson(x)].hs*p[tree[rson(x)].sz+1]+tree[x].val*p[tree[rson(x)].sz]+tree[rson(x)].hs;
	}
	int New(int val){
		ptr++;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		tree[ptr].hs=val;
		tree[ptr].sz=1;
		return ptr;
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
	void insert(int pos,int val){//在pos后面插入val 
		int x,y;
		split(root,pos,x,y);
		root=merge(merge(x,New(val)),y);
	}
	void update(int pos,int val){//把pos改成val 
		int x,y,z;
		split(root,pos,y,z);
		split(y,pos-1,x,y);
		root=merge(merge(x,New(val)),z); 
	} 
	ull query(int l,int r){
		int x,y,z;
		ull ans;
		split(root,r,y,z);
		split(y,l-1,x,y);
		ans=tree[y].hs;
		root=merge(x,merge(y,z));
		return ans; 
	}
#undef lson
#undef rson
}T;

int n,m;
char a[maxn+5];
bool check(int x,int y,int len){
	return T.query(x,x+len-1)==T.query(y,y+len-1);
}
int bin_search(int x,int y){
	int l=1,r=min(n-x+1,n-y+1);
	int mid;
	int ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(x,y,mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
int main(){
	int x,y;
	char cmd[2],val[2];
	scanf("%s",a+1);
	n=strlen(a+1);
	p[0]=1;
	for(int i=1;i<=maxn;i++) p[i]=p[i-1]*prime;
	for(int i=1;i<=n;i++){
		T.insert(i-1,a[i]-'a'+1);
	}
	
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='Q'){
			scanf("%d %d",&x,&y);
			if(x>y) swap(x,y);
			printf("%d\n",bin_search(x,y)); 
		}else if(cmd[0]=='R'){
			scanf("%d %s",&x,val);
			T.update(x,val[0]-'a'+1);
		}else{
			scanf("%d %s",&x,val);
			T.insert(x,val[0]-'a'+1);
			n++;
		}
	}
}
