#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000 
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
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
	}tree[maxn+5];
	int ptr;
	int root;
	int chk(int x){
		return rson(tree[x].fa)==x;
	}
	int New(int val) {
        ptr++;
        tree[ptr].ch[0]=tree[ptr].ch[1]=0;
        tree[ptr].val=val;
        tree[ptr].cnt=tree[ptr].sz=1;
        return ptr;
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
		if(goal==0) root=x;
	}
	
	int get_kth(int k){
		int cur=root;
		while(1){
			push_down(cur);
			if(k<=tree[lson(cur)].sz) cur=lson(cur);
			else if(k<=tree[lson(cur)].sz+tree[cur].cnt) return cur;
			else{
				k-=tree[lson(cur)].sz+tree[cur].cnt;
				cur=rson(cur);
			}
		}
	}
	
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+tree[x].cnt;
	}
	
	void push_down(int x){
		if(tree[x].mark){
			tree[lson(x)].mark^=1;
			tree[rson(x)].mark^=1;
			swap(lson(x),rson(x));
			tree[x].mark=0;
		}
	}
	
	void insert(int val){
		int cur=root;
		int f=0;
		while(cur&&tree[cur].val!=val){
			f=cur;
			cur=tree[cur].ch[val>tree[cur].val];
		}
		if(cur!=0){
			tree[cur].cnt++;
		}else{
			cur=New(val);
			if(f) tree[f].ch[val>tree[f].val]=cur;
			tree[cur].fa=f;
		}
		splay(cur);
	}
	
	void reverse(int x,int y){
		int l=x-1,r=y+1;
		l=get_kth(l);
		r=get_kth(r);
		splay(r);
		splay(l,r);
		tree[rson(lson(root))].mark^=1;
	}
	
	void print(int x) {
        push_down(x);
        if(x==0) return;
        print(lson(x));
        if(tree[x].val>=1&&tree[x].val<=n) printf("%d ",tree[x].val);
        print(rson(x));
    }
}T;
int main() {
    int l,r;
    scanf("%d %d",&n,&m);
    T.insert(-INF);
    T.insert(INF);
    for(int i=1; i<=n; i++) {
        T.insert(i);
    }
    for(int i=1; i<=m; i++) {
        scanf("%d %d",&l,&r);
        T.reverse(l+1,r+1);

    }
    T.print(T.root);
}

