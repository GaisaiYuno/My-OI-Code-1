#include<iostream>
#include<cstring>
#include<stack>
#define maxn 50005
using namespace std;
inline int fread() {
    int x=0,sign=1;
    char c=getchar();
    while(c<'0'||c>'9') {
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*sign;
}
struct node {
    int l,r;
    int mark;
    int lmax,rmax,maxsum;
    int len() {
        return r-l+1;
    }
} tree[maxn*4];
void push_up(int pos) {
    tree[pos].lmax=tree[pos*2].lmax;
    tree[pos].rmax=tree[pos*2+1].rmax;
    tree[pos].maxsum=max(max(tree[pos*2].maxsum,tree[pos*2+1].maxsum),tree[pos*2].rmax+tree[pos*2+1].lmax);
    int mid=(tree[pos].l+tree[pos].r)/2;
    if(tree[pos*2].lmax==mid-tree[pos].l+1) tree[pos].lmax+=tree[pos*2+1].lmax;
    if(tree[pos*2+1].rmax==tree[pos].r-mid) tree[pos].rmax+=tree[pos*2].rmax;
}
void push_down(int pos) {
    if(tree[pos].mark!=-1) {
        tree[pos*2].lmax=tree[pos*2].rmax=tree[pos*2].maxsum=tree[pos*2].len()*tree[pos].mark;
        tree[pos*2+1].lmax=tree[pos*2+1].rmax=tree[pos*2+1].maxsum=tree[pos*2+1].len()*tree[pos].mark;
        tree[pos*2].mark=tree[pos*2+1].mark=tree[pos].mark;
        tree[pos].mark=-1;
    }
}
void build(int l,int r,int pos) {
    tree[pos].mark=-1;
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].lmax=tree[pos].rmax=tree[pos].maxsum=tree[pos].len();
    if(l==r) return;
    int mid=(l+r)/2;
    build(l,mid,pos*2);
    build(mid+1,r,pos*2+1);
    //push_up(pos);
}
void update_point(int l,int r,int pos,int x,int value) {
    if(l==r) {
        tree[pos].mark=value;
        tree[pos].lmax=tree[pos].rmax=tree[pos].maxsum=tree[pos].len()*value;
        return;
    }
    push_down(pos);
    int mid=(l+r)/2;
    if(x<=mid) update_point(l,mid,pos*2,x,value);
    else update_point(mid+1,r,pos*2+1,x,value);
    push_up(pos);
}
int query(int l,int r,int pos,int x) {
    if(l==r||tree[pos].maxsum==r-l+1||tree[pos].maxsum==0) {
        return tree[pos].maxsum;
    }
    int mid=(l+r)/2;
    if(x<=mid) {
        if(x>=mid-tree[pos*2].rmax+1) return tree[pos*2].rmax+tree[pos*2+1].lmax;
        else return query(l,mid,pos*2,x);
    } else {
        if(x<=tree[pos*2+1].lmax+mid+1) return tree[pos*2+1].lmax+tree[pos*2].rmax;
        else return query(mid+1,r,pos*2+1,x);
    }
}
int n,m;
stack<int>s;
int is_d[maxn];
int main() {
    char cmd[3];
    int x;
    while(cin>>n>>m) {
        build(1,n,1);
        while(!s.empty()) s.pop();
        memset(is_d,0,sizeof(is_d));
        while(m--) {
            cin>>cmd;
            if(cmd[0]=='D') {
                x=fread();
                s.push(x);
                if(is_d[x]==0)update_point(1,n,1,x,0);
                is_d[x]=1;
            } else if(cmd[0]=='Q') {
                x=fread();
                if(is_d[x]==0)printf("%d\n",query(1,n,1,x));
                else printf("0\n");
            } else if(cmd[0]=='R') {
                if(!s.empty()) {
                    x=s.top();
                    s.pop();
                    if(is_d[x]==1)update_point(1,n,1,x,1);
                    is_d[x]=0;
                }
            }
        }
    }
    return 0;
}
