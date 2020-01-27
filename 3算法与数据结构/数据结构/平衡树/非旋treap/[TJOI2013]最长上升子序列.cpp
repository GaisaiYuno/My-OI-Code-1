//插入第i个数后的答案，为以当前序列中的数为结尾的LIS长度的最大值，而当前序列中的数值都在[1,i]内，
//那么我们可以维护以值v为结尾的LIS长度，查询的时候直接从1到n扫一遍取max，就可以得到答案
//而注意到在i之后后插入的数对以a[i]为结尾的LIS长度无影响
//只要处理出最后的序列，跑LIS即可 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define maxn 100000 
using namespace std;
struct fhq_treap{
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		int val;
		int sz;
		int dat;
	}tree[maxn+5];
	int root;
	int ptr;
	int New(int val){
		ptr++;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		tree[ptr].sz=1;
		return ptr;
	}
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
	} 
	int merge(int x,int y){
		if(!x||!y) return x+y;
		if(tree[x].dat<tree[y].dat){
			tree[y].ls=merge(x,tree[y].ls);
			push_up(y);
			return y;
		}else{
			tree[x].rs=merge(tree[x].rs,y);
			push_up(x);
			return x;
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
	void insert(int val,int pos){
		int x,y;
		split(root,pos-1,x,y);
		root=merge(merge(x,New(val)),y);
	}
	void print(int x,int *out,int &sz){
		if(x==0) return;
		print(lson(x),out,sz);
		out[++sz]=tree[x].val;
		print(rson(x),out,sz);
	}
}T;

int n;
int sz=0;
int a[maxn+5];

int top=0;
int s[maxn+5];
int len[maxn+5];//以值i为结尾的LIS长度 
void get_lis(){
	for(int i=1;i<=n;i++){
		if(a[i]>s[top]){
			s[++top]=a[i];
			len[a[i]]=top;
		}else{
			int tmp=lower_bound(s+1,s+1+top,a[i])-s;
			s[tmp]=a[i];
			len[a[i]]=tmp;
		} 
	}
} 
int main(){
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		x++;
		T.insert(i,x);
	}
	T.print(T.root,a,sz);
//	for(int i=1;i<=sz;i++) printf("%d ",a[i]);
	get_lis();
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,len[i]);
		printf("%d\n",ans);
		//第i个数插入的时候，序列里只有1~i的数，把以它们为结尾的lis长度取max即可 
	} 
}

