#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define calm (l+r)>>1
const int INF=1e9+7;

const int maxn=100010;
int n,sum[maxn<<2],tag[maxn<<2];
struct EE{
    int h,l,r,v;
}a[maxn];
inline bool cmp(EE a,EE b){
    return a.h>b.h;
}
inline void pushup(int rt){
    sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
}
inline void pushdown(int rt){
    if(tag[rt]){
        tag[rt<<1]=tag[rt<<1|1]=sum[rt<<1]=sum[rt<<1|1]=tag[rt];
        tag[rt]=0;
    }
}
void build(int l,int r,int rt){
    sum[rt]=-INF;
    tag[rt]=0;
    if(l==r)return;
    int m=calm;
    build(lson);build(rson);
}
void update(int x,int v,int l,int r,int rt){
    if(l==r){
        sum[rt]=v;
        return;
    }
    pushdown(rt);
    int m=calm;
    if(x<=m)update(x,v,lson);
    else update(x,v,rson);
    pushup(rt);
}
void update(int L,int R,int v,int l,int r,int rt){
    if(L<=l&&r<=R){
        sum[rt]=tag[rt]=v;
        return;
    }
    pushdown(rt);
    int m=calm;
    if(L<=m)update(L,R,v,lson);
    if(R>m)update(L,R,v,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return sum[rt];
    }
    pushdown(rt);
    int m=calm,ans=-INF;
    if(L<=m)ans=max(ans,query(L,R,lson));
    if(R>m)ans=max(ans,query(L,R,rson));
    return ans;
}
int main(){
    //freopen("D://input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        int len=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&a[i].h,&a[i].l,&a[i].r,&a[i].v);
            len=max(len,a[i].r);
        }
        sort(a,a+n,cmp);
        build(1,len,1);
        update(a[0].l,100+a[0].v,1,len,1);
        update(a[0].r,100+a[0].v,1,len,1);
        for(int i=1;i<n;i++){
            int pre=query(a[i].l,a[i].r,1,len,1);
            update(a[i].l,a[i].r,-INF,1,len,1);
            if(pre>0){
                update(a[i].l,pre+a[i].v,1,len,1);
                update(a[i].r,pre+a[i].v,1,len,1);
            }
        }
        int ans=sum[1];
        if(ans<0)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
