#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
using namespace std;
struct leftist_tree {
	int fa[maxn];
	struct node {
		int l;
		int r;
		int d;
		long long v;
	} a[maxn];
	void ini() {
		a[0].d=-1;
	}
	int merge(int x,int y) {
		if(x==0||y==0) return x+y;
		if(a[x].v<a[y].v) swap(x,y);
		a[x].r=merge(a[x].r,y);
		fa[a[x].r]=x;
		if(a[a[x].r].d>a[a[x].l].d) swap(a[x].l,a[x].r);
		if(a[x].r==0) a[x].d=0;
		else a[x].d=a[a[x].r].d+1;
		return x;
	}
	int pop(int x) {
		fa[a[x].l]=fa[a[x].r]=0;
		int root=merge(a[x].l,a[x].r);
		a[x].l=a[x].r=0;
		return root;
	}
} T;

struct segment {
	int l;
	int r;
	int size;
	int root;
	long long val;
	segment() {

	}
	segment(int lb,int rb,int sz,int rt,long long v) {
		l=lb;
		r=rb;
		size=sz;
		root=rt;
		val=v;
	}
} S[maxn];
int top;
int n;
long long a[maxn],b[maxn];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	T.ini();
	for(int i=1; i<=n; i++) {
		a[i]-=i;
		T.a[i].v=a[i];
	}
	top=0;
	S[++top]=segment(1,1,1,1,a[1]);
	for(int i=2; i<=n; i++) {
		S[++top]=segment(i,i,1,i,a[i]);
		while(top>1&&S[top].val<S[top-1].val) {
			top--;
			S[top].root=T.merge(S[top].root,S[top+1].root);
			S[top].size+=S[top+1].size;
			S[top].r=S[top+1].r;
			while(S[top].size>(S[top].r-S[top].l+2)/2) {
				S[top].size--;
				S[top].root=T.pop(S[top].root);
			}
			S[top].val=T.a[S[top].root].v;
		}
	}
	long long ans=0;
	for(int i=1;i<=top;i++){
		for(int j=S[i].l;j<=S[i].r;j++){
			ans+=abs(T.a[S[i].root].v-a[j]);
		}
	} 
	printf("%lld\n",ans);
//	for(int i=1;i<=n;i++){
//		printf("%lld\n",i+b[i]);
//	}
}
