#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib> 
#include<stack>
#define maxn 100005
#define maxv 200005
#define maxs 5000005
#define lson tree[p].l
#define rson tree[p].r
using namespace std;
int n,k;
struct node {
	int l;
	int r;
	int val;
	int dat;
	int cnt;
	int size;
} tree[maxs];
int tot=0;
int root[maxv];
void update(int p) {
	tree[p].size=tree[lson].size+tree[rson].size+tree[p].cnt;
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

void insert(int &p,int val) {
	if(p==0) {
		p=New(val);
		return;
	}
	if(val==tree[p].val) {
		tree[p].cnt++;
		update(p);
		return;
	}
	if(val<tree[p].val) {
		insert(lson,val);
		if(tree[lson].dat>tree[p].dat) zig(p);
	} else {
		insert(rson,val);
		if(tree[rson].dat>tree[p].dat) zag(p);
	}
	update(p);
}

int get_rank_by_val(int p,int val) {
	if(p==0) return 0;
	if(val==tree[p].val) {
		return tree[lson].size+tree[p].cnt;
	}
	if(val<tree[p].val) {
		return get_rank_by_val(lson,val);
	}
	return get_rank_by_val(rson,val)+tree[lson].size+tree[p].cnt;
}

inline int lowbit(int x) {
	return x&-x;
}

void update(int x,int v){
	while(x<=k){ 
//		printf("	tree %d, update %d\n",x,v);
		insert(root[x],v);
		x+=lowbit(x); 
	}
}

int query(int x,int v){
	int level=0;
	while(x){
//		printf("	tree %d, query %d\n",x,v );
		level+=get_rank_by_val(root[x],v);
		x-=lowbit(x); 
	} 
	return level;
}


struct flower{
	int s;
	int c;
	int m;
	friend bool operator == (flower a,flower b){
		return a.s==b.s&&a.c==b.c&&a.m==b.m;
	}
	friend bool operator < (flower a,flower b){
		if(a.s==b.s){
			if(a.c==b.c) return a.m<b.m;
			else return a.c<b.c;
		}else{
			return a.s<b.s;
		}
	}
}a[maxn];
int level[maxn];
int cnt[maxn];
stack<int>s;
int main() {
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i].s,&a[i].c,&a[i].m);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
//		printf("now: (%d,%d,%d)\n",a[i].s,a[i].c,a[i].m);
		if(a[i]==a[i+1]) s.push(i);
		else{
			level[i]=query(a[i].c,a[i].m);
			while(!s.empty()){
				level[s.top()]=level[i];
				s.pop();
			} 
		}
		update(a[i].c,a[i].m);
	}
//	for(int i=1;i<=n;i++){
//		printf("(%d,%d,%d) = %d \n",a[i].s,a[i].c,a[i].m,level[i]);
//	}
//	printf("\n");
	for(int i=1;i<=n;i++){
		cnt[level[i]]++;
	}
	for(int i=0;i<=n-1;i++){
		printf("%d\n",cnt[i]);
	}
}
