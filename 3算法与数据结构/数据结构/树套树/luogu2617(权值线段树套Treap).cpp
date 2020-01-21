//https://www.luogu.org/problemnew/show/P2617
//50·Ö´ý¿¨³£ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define maxn 200005
#define maxlogn 20
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
inline void qread(char &x){
    char c;
    while(c<'A'||c>'Z'){
        c=getchar();
    }
    x=c; 
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
int n,m;
struct treap{
    struct node{
		int ls;
		int rs;
		int val;
		int dat;
		int cnt;
		int sz;
	}tree[maxn*maxlogn];
	int ptr;
	int New(int val){
		ptr++;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].val=val;
		tree[ptr].dat=frandom();
		tree[ptr].cnt=tree[ptr].sz=1;
		return ptr;
	}
	void push_up(int x){
		tree[x].sz=tree[x].cnt+tree[tree[x].ls].sz+tree[tree[x].rs].sz;
	}
	void rturn(int &x){
		int y=tree[x].ls;
		tree[x].ls=tree[y].rs;
		tree[y].rs=x;
		x=y;
		push_up(tree[x].rs);
		push_up(x);
	}
	void lturn(int &x){
		int y=tree[x].rs;
		tree[x].rs=tree[y].ls;
		tree[y].ls=x;
		x=y;
		push_up(tree[x].ls);
		push_up(x);
	}
	void insert(int &x,int val){
		if(x==0){
			x=New(val);
			return;
		}
		if(tree[x].val==val){
			tree[x].cnt++;
			push_up(x);
			return;
		}
		if(val<tree[x].val){
			insert(tree[x].ls,val);
			if(tree[tree[x].ls].dat>tree[x].dat) rturn(x);
		}else{
			insert(tree[x].rs,val);
			if(tree[tree[x].rs].dat>tree[x].dat) lturn(x);
		}
		push_up(x);
	}
	void del(int &x,int val){
		if(x==0) return;
		if(tree[x].val==val){
			if(tree[x].cnt>1){
				tree[x].cnt--;
				push_up(x);
				return;
			}else{
				if(tree[x].ls||tree[x].rs){
					if(tree[tree[x].ls].dat>tree[tree[x].rs].dat||tree[x].rs==0){
						rturn(x);
						del(tree[x].rs,val);
					}else{
						lturn(x);
						del(tree[x].ls,val);
					}
					push_up(x);
				}else x=0;
				return;
			}
		}
		if(val<tree[x].val){
			del(tree[x].ls,val);
		}else{
			del(tree[x].rs,val);
		}
		push_up(x);
	}
    int lower_bound(int x,int val){
        if(x==0) return 0;
        if(val<tree[x].val) return lower_bound(tree[x].ls,val);
        else if(val==tree[x].val) return lower_bound(tree[x].ls,val)+tree[x].cnt;
        else return tree[tree[x].ls].sz+tree[x].cnt+lower_bound(tree[x].rs,val);
    }
//	void debug(int x){
//		if(x==0) return;
//		debug(tree[x].ls);
//		for(int i=1;i<=tree[x].cnt;i++) printf("%d ",tree[x].val);
//		debug(tree[x].rs);
//	}
}T1;
struct segment_tree{
    struct node{
        int l;
        int r;
        int root;
    }tree[maxn<<2];
    void build(int l,int r,int pos){
        tree[pos].l=l;
        tree[pos].r=r;
        if(l==r) return;
        int mid=(l+r)>>1;
        build(l,mid,pos<<1);
        build(mid+1,r,pos<<1|1);
    }
    void insert(int tpos,int tval,int pos){
        T1.insert(tree[pos].root,tval);
        if(tree[pos].l==tree[pos].r) return;
        int mid=(tree[pos].l+tree[pos].r)>>1;
        if(tpos<=mid) insert(tpos,tval,pos<<1);
        else insert(tpos,tval,pos<<1|1);
    }
    void del(int tpos,int tval,int pos){
        T1.del(tree[pos].root,tval);
        if(tree[pos].l==tree[pos].r) return;
        int mid=(tree[pos].l+tree[pos].r)>>1;
        if(tpos<=mid) del(tpos,tval,pos<<1);
        else del(tpos,tval,pos<<1|1);
    }
    int query(int p,int q,int qk,int pos){
        if(tree[pos].l==tree[pos].r) return tree[pos].l;
        int mid=(tree[pos].l+tree[pos].r)>>1;
        int lcnt=T1.lower_bound(tree[pos<<1].root,p)-T1.lower_bound(tree[pos<<1].root,q-1);
        if(qk<=lcnt) return query(p,q,qk,pos<<1);
        else return query(p,q,qk-lcnt,pos<<1|1);
    }
//	void debug(int pos){
//		printf("[%d,%d]: " ,tree[pos].l,tree[pos].r); 
//		T1.debug(tree[pos].root);
//		printf("\n");
//		if(tree[pos].l==tree[pos].r) return;
//		debug(pos<<1);
//		debug(pos<<1|1);
//	}
}T2;

struct oper{
    int type;
    int l,r,k;
    int pos,val;
    int dval;
}q[maxn];
int a[maxn];
int sz;
int b[maxn*2]; 
int main(){
    char cmd;
    qread(n);
    qread(m);
    for(int i=1;i<=n;i++){
        qread(a[i]);
        b[++sz]=a[i];
    }
    for(int i=1;i<=m;i++){
        qread(cmd); 
        if(cmd=='Q'){
            q[i].type=0;
            qread(q[i].l);
            qread(q[i].r);
            qread(q[i].k);
        }else{
            q[i].type=1;
            qread(q[i].pos);
            qread(q[i].val);
            b[++sz]=q[i].val;
        } 
    }
    sort(b+1,b+1+sz);
    sz=unique(b+1,b+1+sz)-b-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+sz,a[i])-b;
    for(int i=1;i<=m;i++){
        if(q[i].type==1){
            q[i].dval=lower_bound(b+1,b+1+sz,q[i].val)-b;
        }
    }
    T2.build(1,sz,1);
    for(int i=1;i<=n;i++){
        T2.insert(a[i],i,1);
    } 
//	T2.debug(1);
    for(int i=1;i<=m;i++){
        if(q[i].type==0){
            qprint(b[T2.query(q[i].r,q[i].l,q[i].k,1)]); 
            putchar('\n');
        }else{
            T2.del(a[q[i].pos],q[i].pos,1);
            T2.insert(q[i].dval,q[i].pos,1);
            a[q[i].pos]=q[i].dval;
            
//			T2.debug(1);
        }
    }
}

