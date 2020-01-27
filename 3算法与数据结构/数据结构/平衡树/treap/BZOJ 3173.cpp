#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define maxn 100005
#define lson tree[p].l
#define rson tree[p].r
#define INF 0x3f3f3f3f
using namespace std;
struct node {
	int l;
	int r;
	int val;
	int dat;
	int cnt;
	int size;
} tree[maxn];
int tot=0;
int root;
void update(int p) {
	tree[p].size=tree[lson].size+tree[rson].size+1;
}

void zig(int &p) {
	int q=tree[p].l;
	tree[p].l=tree[q].r;
	tree[q].r=p;
	p=q;
	update(tree[p].r);
	update(p);
}

void zag(int &p) {
	int q=tree[p].r;
	tree[p].r=tree[q].l;
	tree[q].l=p;
	p=q;
	update(tree[p].l);
	update(p);
}

int New(int val) {
	tree[++tot].val=val;
	tree[tot].dat=rand();
	tree[tot].cnt=1;
	tree[tot].size=1;
	return tot;
}

void build() {
	New(-INF);
	New(INF);
	root=1;
	tree[1].r=2;
	update(root);
}

void insert_by_pos(int &p,int val,int rank){
	if(p==0){
		p=New(val);
		return; 
	}
	tree[p].size++;
	if(tree[lson].size>=rank){
		insert_by_pos(lson,val,rank);
		if(tree[lson].dat>tree[p].dat) zig(p);
	}else{
		insert_by_pos(rson,val,rank-tree[lson].size-1);
		if(tree[rson].dat>tree[p].dat) zag(p); 
	}
	update(p);
	
}

int leng;
int seq[maxn];
int num[maxn];
void get_seq(int p){
	if(!p) return;
	get_seq(lson);
	seq[++leng]=tree[p].val;
	get_seq(rson); 
}

int top=0;
int s[maxn];
int ans[maxn];
int n;
int main(){
	int x,tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		insert_by_pos(root,i,x);
	}
	get_seq(root);
	s[0]=-INF;
	for(int i=1;i<=n;i++){
		if(seq[i]>s[top]){
			s[++top]=seq[i];
			ans[seq[i]]=top;
		}else{
			tmp=lower_bound(s,s+top+1,seq[i])-s;
			s[tmp]=seq[i];
			ans[seq[i]]=tmp;
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]=max(ans[i],ans[i-1]);
		printf("%d\n",ans[i]);
	}
}
