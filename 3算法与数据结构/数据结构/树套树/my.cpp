//https://www.luogu.org/problemnew/show/P2617
/*
树状数组套treap思路
对于静态的查询，root[i]对应的主席树的区间[l,r]保存的是a[1]~a[i]有多少个值落在区间[l,r]内
如果我们要修改a[i],则要修改O(n)棵主席树
那么我们像树状数组那样维护n棵主席树，不同的是每棵主席树里保存的是
a[i-lowbit(i)+1]~a[i]有多少个值落在区间[l,r]内
对于查询[ql,qr]时的做差
我们要像树状数组求和那样，把root[i],root[i-lowbit(i)],....共O(logn)棵主席树的值加起来
才能得到a[1]~a[i]有多少个数落在1~qr里面，1~(ql-1)同理
维护临时数组存储这O(logn)棵主席树的根即可
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define maxn 200005
#define maxlogn 27
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
    char c=getchar();
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

int n,m;
struct node {
    int ls;
    int rs;
    int sum;
} tree[maxn*maxlogn*maxlogn];
int root[maxn*maxlogn];
int ptr;
void push_up(int x) {
    tree[x].sum=tree[tree[x].ls].sum+tree[tree[x].rs].sum;
}
void update(int &x,int upos,int uval,int last,int l,int r) {
    x=++ptr;
    tree[x]=tree[last];
    if(l==r) {
        tree[x].sum+=uval;
        return;
    }
    int mid=(l+r)>>1;
    if(upos<=mid) update(tree[x].ls,upos,uval,tree[last].ls,l,mid);
    else update(tree[x].rs,upos,uval,tree[last].rs,mid+1,r);
    push_up(x);
}
int totx,x[maxn*maxlogn],toty,y[maxn*maxlogn];
int query(int k,int l,int r) {
    if(l==r) return l;
    int lcnt=0;
    int mid=(l+r)>>1;
    for(int i=1;i<=totx;i++){
        lcnt-=tree[tree[x[i]].ls].sum;
    }
    for(int i=1;i<=toty;i++){
        lcnt+=tree[tree[y[i]].ls].sum;
    } 
    if(k<=lcnt){
        for(int i=1;i<=totx;i++) x[i]=tree[x[i]].ls;
        for(int i=1;i<=toty;i++) y[i]=tree[y[i]].ls;
        return query(k,l,mid);
    }else{
        for(int i=1;i<=totx;i++) x[i]=tree[x[i]].rs;
        for(int i=1;i<=toty;i++) y[i]=tree[y[i]].rs;
        return query(k-lcnt,mid+1,r);
    }
}
inline int lowbit(int x){
    return x&-x;
}


struct oper {
    int type;
    int l,r,k;
    int pos,val;
    int dval;
} q[maxn];
int a[maxn];
int sz;
int b[maxn*2];

void add(int xpos,int xval,int v){
    for(int i=xpos;i<=sz;i+=lowbit(i)){
        update(root[i],xval,v,root[i],1,sz); 
    }
}
int answer(int l,int r,int k){
    totx=toty=0;
    for(int i=l-1;i;i-=lowbit(i)) x[++totx]=root[i];
    for(int i=r;i;i-=lowbit(i)) y[++toty]=root[i];
    return query(k,1,sz);
}
int main() {
    char cmd;
    qread(n);
    qread(m);
    for(int i=1; i<=n; i++) {
        qread(a[i]);
        b[++sz]=a[i];
    }
    for(int i=1; i<=m; i++) {
        qread(cmd);
        if(cmd=='Q') {
            q[i].type=0;
            qread(q[i].l);
            qread(q[i].r);
            qread(q[i].k);
        } else {
            q[i].type=1;
            qread(q[i].pos);
            qread(q[i].val);
            b[++sz]=q[i].val;
        }
    }
    sort(b+1,b+1+sz);
    sz=unique(b+1,b+1+sz)-b-1;
    for(int i=1; i<=n; i++) a[i]=lower_bound(b+1,b+1+sz,a[i])-b;
    for(int i=1; i<=m; i++) {
        if(q[i].type==1) {
            q[i].dval=lower_bound(b+1,b+1+sz,q[i].val)-b;
        }
    }
    for(int i=1; i<=n; i++) {
        add(i,a[i],1);
    }
//	T2.debug(1);
    for(int i=1; i<=m; i++) {
        if(q[i].type==0) {
            qprint(b[answer(q[i].l,q[i].r,q[i].k)]);
            putchar('\n');
        } else {
            add(q[i].pos,a[q[i].pos],-1);
            add(q[i].pos,q[i].dval,1);
            a[q[i].pos]=q[i].dval;

//			T2.debug(1);
        }
    }
}


