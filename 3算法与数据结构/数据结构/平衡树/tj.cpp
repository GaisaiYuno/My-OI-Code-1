#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

const int N=100010;
const int INF=1e9;
struct node{          //用线段树维护前缀和 
    int mn,ad;
};
node t[N<<2];
struct point{
    int x,type;
};
point po[N<<1],b[N];
int n,m,nn,a[N],w[N<<1];

int cmp(const point &A,const point &B) {   //按照a或b排序 
    return A.x<B.x||(A.x==B.x&&A.type<B.type);   
}

void push(int bh,int l,int r) {
    if (l==r) return;
    if (!t[bh].ad) return;
    int lc=bh<<1;
    int rc=bh<<1|1;
    t[lc].mn+=t[bh].ad; t[lc].ad+=t[bh].ad;
    t[rc].mn+=t[bh].ad; t[rc].ad+=t[bh].ad;
    t[bh].ad=0;
}

void update(int bh) {
    int lc=bh<<1;
    int rc=bh<<1|1;
    t[bh].mn=min(t[lc].mn,t[rc].mn);
}

void add(int bh,int l,int r,int L,int R,int z) {
    if (R<L) return;
    push(bh,l,r);
    if (l>=L&&r<=R) {
        t[bh].mn+=z;
        t[bh].ad+=z;
        return;
    }
    int mid=(l+r)>>1;
    if (L<=mid) add(bh<<1,l,mid,L,R,z);
    if (R>mid) add(bh<<1|1,mid+1,r,L,R,z);
    update(bh);
}

int ask(int bh,int l,int r,int L,int R) {
    if (R<L) return INF;
    push(bh,l,r);
    if (l>=L&&r<=R) return t[bh].mn;
    int ans=INF;
    int mid=(l+r)>>1;
    if (L<=mid) ans=min(ans,ask(bh<<1,l,mid,L,R));
    if (R>mid) ans=min(ans,ask(bh<<1|1,mid+1,r,L,R));
    return ans;
}

void solve(){
    ll ans=0;
    for (int i=n,j=m;i;i--,j--) {
        add(1,1,nn,w[i],nn,-1);
        for (;j;j--) {
            int k=w[b[j].type+n];
            if (ask(1,1,nn,1,k-1)>=0&&ask(1,1,nn,k,nn)>=-1&&a[i]+b[j].x>0) {
                ans+=(ll)a[i]+b[j].x;
                add(1,1,nn,k,nn,1);
                break;
            }
        }
        if (!j) break;
    }
    printf("%lld\n",ans);
}

int main() 
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) po[i].x=a[i],po[i].type=i;
    for (int i=1;i<=m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        po[i+n].x=x; po[i+n].type=i+n; 
        b[i].x=y-x; b[i].type=i;
    }
    nn=n+m;
    sort(po+1,po+1+nn,cmp); sort(b+1,b+1+m,cmp);
    for (int i=1;i<=nn;i++) w[po[i].type]=i;
    solve();
    return 0;
}

