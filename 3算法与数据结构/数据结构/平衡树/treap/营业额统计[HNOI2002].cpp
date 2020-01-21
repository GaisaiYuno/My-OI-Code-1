//http://119.29.55.79/problem/284
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define maxn 100005
#define maxv 1000005
#define INF 0x3f3f3f3f
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

inline int frandom() {
	static int seed=131;
	return seed=int(seed*48271LL%2147483647);
}

struct treap {
	struct node {
		int ls;
		int rs;
		int sz;
		int cnt;
		int val;
		int dat;
	} tree[maxn];
	int root,ptr;
	int New(int val) {
		ptr++;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].sz=tree[ptr].cnt=1;
		tree[ptr].val=val;
		tree[ptr].dat=frandom();
		return ptr;
	}
	void push_up(int x) {
		tree[x].sz=tree[tree[x].ls].sz+tree[tree[x].rs].sz+tree[x].cnt;
	}
	void rturn(int &x) {
		int y=tree[x].ls;
		tree[x].ls=tree[y].rs;
		tree[y].rs=x;
		x=y;
		push_up(tree[x].rs);
		push_up(x);
	}
	void lturn(int &x) {
		int y=tree[x].rs;
		tree[x].rs=tree[y].ls;
		tree[y].ls=x;
		x=y;
		push_up(tree[x].ls);
		push_up(x);
	}

	void insert(int &x,int val) {
		if(x==0) {
			x=New(val);
			return;
		}
		if(tree[x].val==val) {
			tree[x].cnt++;
			push_up(x);
			return;
		}
		if(tree[x].val>val) {
			insert(tree[x].ls,val);
			if(tree[x].dat<tree[tree[x].ls].dat) rturn(x);
		} else {
			insert(tree[x].rs,val);
			if(tree[x].dat<tree[tree[x].rs].dat) lturn(x);
		}
		push_up(x);
	}
	int get_pre(int x,int val) {
		if(x==0) return -INF;
		if(tree[x].val>=val) return get_pre(tree[x].ls,val);
		else return max(get_pre(tree[x].rs,val),tree[x].val);
	}
	int get_nex(int x,int val) {
		if(x==0) return INF;
		if(tree[x].val<=val) return get_nex(tree[x].rs,val);
		else return min(get_nex(tree[x].ls,val),tree[x].val);
	}
	int count(int x,int val){
		if(x==0) return 0;
		if(tree[x].val==val){
			return tree[x].cnt;
		}	
		if(val<tree[x].val) return count(tree[x].ls,val);
		else return count(tree[x].rs,val);
	}
	int size() {
		return tree[root].sz;
	}
} T;
int n;
int exist[maxv];
int main() {
#ifdef FILE_IO
	freopen("6.in","r",stdin);
#endif
	qread(n);
	int ans=0;
	int v;
	for(int i=1; i<=n; i++) {
		qread(v);
		if(i==1) {
			ans+=v;
		} else {
			int now=INF;
			int pre=T.get_pre(T.root,v);
			int nex=T.get_nex(T.root,v);
			if(pre!=-INF) {
				now=min(now,v-pre);
			}
			if(nex!=INF) {
				now=min(now,nex-v);
			}
			if(T.count(T.root,v)) now=0;
			ans+=now;
//			printf("%d %d %d\n",v,pre,nex);
		}
		T.insert(T.root,v);
//		printf("ok %d\n",i);
	}
	printf("%d\n",ans);
}
