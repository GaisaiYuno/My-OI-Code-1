//<code class="hljs" objectivec="">//Hello. I'm Peter.
//#pragma comment(linker, /STACK:102400000,102400000)
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
//#include
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline ll readLL(){
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int r, c, m;
#define MAXN 1000010
 
#define lch id<<1
#define rch id<<1|1
#define mid ((l+r)>>1)
struct Segment_Tree{
    ll max, min, sum;
    ll fu, jia;
    int len;
}tree[MAXN << 2];
inline void plant_tree(int id,int l,int r){
    tree[id].max = tree[id].min = tree[id].sum = 0;
    tree[id].fu = tree[id].jia = 0;
    tree[id].len = r - l + 1;
    if(l == r) return;
    plant_tree(lch, l, mid);
    plant_tree(rch, mid + 1, r);
}
void pullup(int id){
    tree[id].sum = tree[lch].sum + tree[rch].sum;
    tree[id].max = max(tree[lch].max, tree[rch].max);
    tree[id].min = min(tree[lch].min, tree[rch].min);
}
void pushdown(int id){
    if(tree[id].fu > 0){
        tree[lch].fu = tree[id].fu;
        tree[lch].jia = 0;
        tree[lch].max = tree[lch].min = tree[id].fu;
        tree[lch].sum = tree[id].fu * tree[lch].len;
 
        tree[rch].fu = tree[id].fu;
        tree[rch].jia = 0;
        tree[rch].max = tree[rch].min = tree[id].fu;
        tree[rch].sum = tree[id].fu * tree[rch].len;
 
        tree[id].fu = 0;
    }
    else if(tree[id].jia > 0){
        //bug
        if(tree[lch].fu > 0) tree[lch].fu += tree[id].jia;
        else tree[lch].jia += tree[id].jia;
        tree[lch].sum += tree[id].jia * tree[lch].len;
        tree[lch].max += tree[id].jia;
        tree[lch].min += tree[id].jia;
 
 
        if(tree[rch].fu > 0) tree[rch].fu += tree[id].jia;
        else tree[rch].jia += tree[id].jia;
        tree[rch].sum += tree[id].jia * tree[rch].len;
        tree[rch].max += tree[id].jia;
        tree[rch].min += tree[id].jia;
 
        tree[id].jia = 0;
    }
}
inline void update_fu(int id,int ql,int qr,int l,int r,ll v){
    if(ql == l && qr == r){
        tree[id].fu = v;
        tree[id].jia = 0;
        tree[id].min = tree[id].max = v;
        tree[id].sum = v * tree[id].len;
        return;
    }
    pushdown(id);
 
    if(qr <= mid) update_fu(lch, ql, qr, l, mid, v);
    else if(mid < ql) update_fu(rch, ql, qr, mid + 1, r, v);
    else update_fu(lch, ql, mid, l, mid, v), update_fu(rch, mid + 1, qr, mid + 1, r, v);
 
    pullup(id);
}
inline void update_jia(int id,int ql,int qr,int l,int r,ll v){
    if(ql == l && qr == r){
        if(tree[id].fu > 0) tree[id].fu += v;
        else tree[id].jia += v;
        tree[id].sum += v * tree[id].len;
        tree[id].max += v;
        tree[id].min += v;
        return;
    }
    pushdown(id);
 
    if(qr <= mid) update_jia(lch, ql, qr, l, mid, v);
    else if(mid < ql) update_jia(rch, ql, qr, mid + 1, r, v);
    else update_jia(lch, ql, mid, l, mid, v), update_jia(rch, mid + 1, qr, mid + 1, r, v);
 
    pullup(id);
}
inline ll query_min(int id,int ql,int qr,int l,int r){
    if(ql == l && qr == r) return tree[id].min;
    pushdown(id);
 
    if(qr <= mid) return query_min(lch, ql, qr, l, mid);
    else if(mid < ql) return query_min(rch, ql, qr, mid + 1, r);
    else return min(query_min(lch, ql, mid, l, mid), query_min(rch, mid + 1, qr, mid + 1, r));
}
inline ll query_max(int id,int ql,int qr,int l,int r){
    if(ql == l && qr == r) return tree[id].max;
    pushdown(id);
 
    if(qr <= mid) return query_max(lch, ql, qr, l, mid);
    else if(mid < ql) return query_max(rch, ql, qr, mid + 1, r);
    else return max(query_max(lch, ql, mid, l, mid), query_max(rch, mid + 1, qr, mid + 1, r));
}
inline ll query_sum(int id,int ql,int qr,int l,int r){
    if(ql == l && qr == r) return tree[id].sum;
    pushdown(id);
 
    if(qr <= mid) return query_sum(lch, ql, qr, l, mid);
    else if(mid < ql) return query_sum(rch, ql, qr, mid + 1, r);
    else return query_sum(lch, ql, mid, l, mid) + query_sum(rch, mid + 1, qr, mid + 1, r);
}
int f(int x,int y){
    return (x - 1) * c + y;
}
int main(){
    //freopen(/Users/peteryuanpan/data.txt,r,stdin);
 
    while(~scanf(%d%d%d,&r,&c,&m)){
 
        int n = r * c;
        plant_tree(1, 1, n);
 
        for(int im = 1; im <= m; im++){
            int ty = read();
            int x1, y1, x2, y2;
            ll v;
            if(ty == 1){
                x1 = read(), y1 = read();
                x2 = read(), y2 = read();
                v = readLL();
                for(int i = x1; i <= x2; i++){
                    int l = f(i, y1), r = f(i, y2);
                    update_jia(1, l, r, 1, n, v);
                }
            }
            else if(ty == 2){
                x1 = read(), y1 = read();
                x2 = read(), y2 = read();
                v = readLL();
                for(int i = x1; i <= x2; i++){
                    int l = f(i, y1), r = f(i, y2);
                    update_fu(1, l, r, 1, n, v);
                }
            }
            else if(ty == 3){
                ll sum = 0, maxi = -1e18, mini = 1e18;
                x1 = read(), y1 = read();
                x2 = read(), y2 = read();
                for(int i = x1; i <= x2; i++){
                    int l = f(i, y1), r = f(i, y2);
                    sum += query_sum(1, l, r, 1, n);
                    maxi = max(maxi, query_max(1, l, r, 1, n));
                    mini = min(mini, query_min(1, l, r, 1, n));
                    //printf(i = %d l=%d r=%d %lld %lld %lld
,i,l,r,sum,mini,maxi);
                }
 
                printf(%lld %lld %lld
,sum,mini,maxi);
            }
        }
    }
 
    return 0;
}</map></set></vector></queue></stack></ctime></cctype></functional></algorithm></cstdlib></cmath></string></cstring></sstream></iostream></cstdio></code>

