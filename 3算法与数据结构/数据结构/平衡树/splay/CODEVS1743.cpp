#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[maxn];
struct Splay{
	#define lson(x) (tree[x].ch[0])
	#define rson(x) (tree[x].ch[1])
	struct node{
		int fa;
		int ch[2];
		int val;
		int sz;
		int cnt;
		int mark;
	}tree[maxn];
	int root;
	int ptr;
	void push_up(int x){
		tree[x].sz=tree[x].cnt+tree[lson(x)].sz+tree[rson(x)].sz;
	} 
	void push_down(int x){
		if(x!=0&&tree[x].mark){
			tree[lson(x)].mark^=1;
			tree[rson(x)].mark^=1;
			swap(lson(x),rson(x));
			tree[x].mark=0;
		}
	}
	int chk(int x){
		return tree[tree[x].fa].ch[1]==x;
	}
	void rotate(int x){
		int y=tree[x].fa,z=tree[y].fa,k=chk(x),w=tree[x].ch[k^1];
		push_down(x);
		push_down(y);
		tree[y].ch[k]=w;
		tree[w].fa=y;
		tree[z].ch[chk(y)]=x;
		tree[x].fa=z;
		tree[x].ch[k^1]=y;
		tree[y].fa=x;
		push_up(y);
		push_up(x);
	}
	void splay(int x,int goal=0){
		while(tree[x].fa!=goal){
			int y=tree[x].fa;
			int z=tree[y].fa;
			if(z!=goal){
				if(chk(x)==chk(y)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		if(!goal) root=x;
	}
	int find(int k){
		int cur=root;
		while(1){
			push_down(cur);
			if(k<=tree[lson(cur)].sz) cur=lson(cur);
			else if(k<=tree[cur].cnt+tree[lson(cur)].sz) return cur;
			else{
				k-=tree[cur].cnt+tree[lson(cur)].sz;
				cur=rson(cur);
			} 
		}
		return 0;
	}

	void build(int l,int r,int fa,int *a){
		int mid=(l+r)>>1;
		tree[mid].fa=fa; 
		tree[mid].sz=tree[mid].cnt=1;
		tree[mid].val=a[mid];
		tree[fa].ch[mid>fa]=mid;
		if(l==r) return;
		if(l<=mid-1) build(l,mid-1,mid,a);
		if(r>=mid+1) build(mid+1,r,mid,a);
		push_up(mid);
	}
	void reverse(int x,int y){
		int l=x-1;
		int r=y+1;
		l=find(l);
		r=find(r);
		splay(r);
		splay(l,r);
		tree[rson(lson(root))].mark^=1;
	} 
	#undef lson
	#undef rson
}T;
int main(){
	scanf("%d",&n);
	a[1]=-INF;
	for(int i=2;i<=n+1;i++){
		scanf("%d",&a[i]);
	} 
	a[n+2]=INF;
	T.build(1,n+2,0,a);//不能insert,因为insert会根据值来排序，破坏序列的位置关系 
	T.root=(n+3)/2;
	int cnt=0;
	while(cnt<=100000){
		int k=T.tree[T.find(2)].val;
		if(k==1) break;
		else{
			T.reverse(2,k+1);
			cnt++;
		}
	}
	if(cnt>100000) printf("-1");
	else printf("%d\n",cnt); 
}

